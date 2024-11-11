#include "TxNovaCompra.h"

std::string obtenerFechaActual() {
    // Obtener el tiempo actual
    std::time_t tiempoActual = std::time(0);

    // Estructura para almacenar la fecha y hora local
    struct tm tiempoLocal;

    // Utilizar localtime_s en lugar de localtime
    if (localtime_s(&tiempoLocal, &tiempoActual) != 0) {
        // Manejar el error
        throw std::runtime_error("Error al obtener la fecha y hora local");
    }

    // Obtener el día, mes y año actual
    int diaActual = tiempoLocal.tm_mday;
    int mesActual = tiempoLocal.tm_mon + 1;  // tm_mon es 0-based (0-11)
    int anioActual = tiempoLocal.tm_year + 1900;  // tm_year cuenta los años desde 1900

    // Crear un string con el formato "dd/mm/yyyy"
    std::string strFechaActual = std::to_string(diaActual) + "/" + std::to_string(mesActual) + "/" + std::to_string(anioActual);

    return strFechaActual;
}

TxNovaCompra::TxNovaCompra(std::string element, double preu) {
    _element = element;
    _preu = preu;
}

void TxNovaCompra::executar() {
    Videoconsola& v = Videoconsola::getInstance();
    std::string usu = v.obteUsuari().obteSobrenom();
    std::string data = obtenerFechaActual();
    PassarellaCompra c(_element, usu, data, _preu);
    try {
        c.insereix();
    }
    catch (const pqxx::sql_error& e) {
        throw std::runtime_error("Error al inserir una compra");
    }
}