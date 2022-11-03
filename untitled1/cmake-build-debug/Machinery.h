
#ifndef UNTITLED1_MACHINERY_H
#define UNTITLED1_MACHINERY_H

#include <iostream>

using namespace std;

class Machinery {


public:
    Machinery();

    int arg1Row;
    int arg2Col;
    int KeySize;
    string mapmatrixtxt;
    string keymatrixtxt;
    string outputtxt;

    int getArg1Row() const;

    void setArg1Row(int arg1Row);

    int getArg2Col() const;

    void setArg2Col(int arg2Col);

    int getKeySize() const;

    void setKeySize(int keySize);

    const string &getMapmatrixtxt() const;

    void setMapmatrixtxt(const string &mapmatrixtxt);

    const string &getKeymatrixtxt() const;

    void setKeymatrixtxt(const string &keymatrixtxt);

    const string &getOutputtxt() const;

    void setOutputtxt(const string &outputtxt);
};


#endif //UNTITLED1_MACHINERY_H
