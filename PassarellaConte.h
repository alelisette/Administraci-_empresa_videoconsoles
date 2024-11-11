#pragma once
#include<iostream>
class PassarellaConte
{
private:
    std::string _nomP;
    std::string _nomV;

public:
    std::string obtePaquet();
    std::string obteVideojoc();
    PassarellaConte(std::string nomP, std::string nomV);
    PassarellaConte& operator=(const PassarellaConte& other);

};
