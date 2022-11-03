
#include "Machinery.h"

Machinery::Machinery() {}

int Machinery::getArg1Row() const {
    return arg1Row;
}

void Machinery::setArg1Row(int arg1Row) {
    Machinery::arg1Row = arg1Row;
}

int Machinery::getArg2Col() const {
    return arg2Col;
}

void Machinery::setArg2Col(int arg2Col) {
    Machinery::arg2Col = arg2Col;
}

int Machinery::getKeySize() const {
    return KeySize;
}

void Machinery::setKeySize(int keySize) {
    KeySize = keySize;
}

const string &Machinery::getMapmatrixtxt() const {
    return mapmatrixtxt;
}

void Machinery::setMapmatrixtxt(const string &mapmatrixtxt) {
    Machinery::mapmatrixtxt = mapmatrixtxt;
}

const string &Machinery::getKeymatrixtxt() const {
    return keymatrixtxt;
}

void Machinery::setKeymatrixtxt(const string &keymatrixtxt) {
    Machinery::keymatrixtxt = keymatrixtxt;
}

const string &Machinery::getOutputtxt() const {
    return outputtxt;
}

void Machinery::setOutputtxt(const string &outputtxt) {
    Machinery::outputtxt = outputtxt;
}
