#include "TxTancaSessio.h"

//creadora
TxTancaSessio::TxTancaSessio() {

}
void TxTancaSessio::executar() {	//fa el que digui el diagrama de seq
	Videoconsola& v = Videoconsola::getInstance();
	v.tanca_sessio();
}
