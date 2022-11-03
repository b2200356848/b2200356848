#include <sstream>
#include "Machine.h"
#include <fstream>
#include <vector>

using namespace std;

// constructor
Machine::Machine() {}

// function for defining terminal arguments
void Machine::MapDim(const char *argDim, Machine obj, const char *argDim2, const char *argDim3, const char *argDim4,
                     const char *argDim5) {

    // Get the map row col dimensions using string stream

    stringstream s;
    s<<argDim;
    vector<string> rowcolvector;

    while (s.good()) {
        string parsed;
        getline(s, parsed, 'x');
        rowcolvector.push_back(parsed);
    }

    int a ;
    int b;

    stringstream x1;
    x1<<rowcolvector[0];
    x1>>a;

    stringstream x2;
    x2<<rowcolvector[1];
    x2>>b;

    obj.setMapRow(a);
    obj.setMapCol(b);


    // get the key matrix dimensions using string stream

    int d ;

    stringstream s2;
    s2<< argDim2;
    s2>>d;

    obj.setKeySize(d);

    cout<<obj.getKeySize()<<"\n";


    // get the txt files names on strings , I wanted to keep them on class attributes rather than using it raw

    // map matrix txt
    string t1;

    stringstream s3;
    s3<< argDim3;
    s3>>t1;

    obj.setMapTxt(t1);

    // key matrix txt
    string t2;

    stringstream s4;
    s4<< argDim4;
    s4>>t2;

    obj.setKeyTxt(t2);

    // output txt
    string t3;

    stringstream s5;
    s5<< argDim5;
    s5>>t3;

    obj.setOutTxt(t3);

}

// function for defining matrix from in-put txt files
void Machine::ReaderFunc(Machine obj, int **KeyMatrix, int **MapMatrix) {
    // Read TXT Files
    int x;              // just for declaring a type which is int

    ifstream KeyTxtFile;    // create a file
    KeyTxtFile.open(obj.getKeyTxt());   // open the file with argument TXT

    int a=0;
    int b=0;

    while (KeyTxtFile >> x) {       // Chooses every matched type x inputs which is integer

        if ( b == obj.getKeySize()){
            a++;
            b =0;
            KeyMatrix[a][b] = x;
            b++;
        } else{

            KeyMatrix[a][b] = x;
            b++;
        }

    }

    int y;

    ifstream MapTxtFile;
    MapTxtFile.open(obj.getMapTxt());

    int c=0;
    int d=0;

    while (MapTxtFile >> y) {

        if ( d == obj.getMapRow()){
            c++;
            d =0;
            MapMatrix[c][d] = y;
            d++;
        } else{

            MapMatrix[c][d] = y;
            d++;
        }

    }
}

void Machine::StartDefine(Machine obj) {
    // In order to find middle point of matrices we divide Key Matrix dimension with 2
    // e.g. 3x3 key size matrices , 3/2 = 1 so start origin points are 1,1 // 5x5 5/2=2 2,2
    // also this division number gives us how many rows and cols of every side of middle point

    obj.setCurRow(obj.getKeySize()/2);

    obj.setCurCol(obj.getKeySize()/2);
}

string Machine::Multiplier(Machine obj, int **KeyMatrix, int **MapMatrix) {

    // Main Block
    int Result1 = MapMatrix[obj.getCurRow()][obj.getCurCol()] * KeyMatrix[obj.getKeySize()/2][obj.getKeySize()/2];

    // Upper Block

    for (int i = 0; i < (obj.getKeySize()/2)  ; ++i) {

        Result1 += MapMatrix[obj.getCurRow()-(obj.getKeySize()/2)+i][obj.getCurCol()] * KeyMatrix[i][obj.getKeySize()/2];
    }

    // Bottom Block

    for (int i = (obj.getKeySize()/2)+1; i < obj.getKeySize()  ; ++i) {

        Result1 += MapMatrix[obj.getCurRow()-(obj.getKeySize()/2)+i][obj.getCurCol()] * KeyMatrix[i][obj.getKeySize()/2];
    }

    // Right Block

    for (int i = (obj.getKeySize()/2)+1; i < obj.getKeySize()  ; ++i) {

        Result1 += MapMatrix[obj.getCurRow()][obj.getCurCol()-(obj.getKeySize()/2)+i] * KeyMatrix[obj.getKeySize()/2][i];
    }

    // Left Block

    for (int i = 0; i < (obj.getKeySize()/2)  ; ++i) {

        Result1 += MapMatrix[obj.getCurRow()][obj.getCurCol()-(obj.getKeySize()/2)+i] * KeyMatrix[obj.getKeySize()/2][i];
    }

    // Result

    // Writing

    int a = obj.getCurRow();
    int b = obj.getCurCol();
    int c = Result1;

    stringstream a1;
    stringstream a2;
    stringstream a3;

    a1 << a;
    string row;
    a1>>row;


    a2 << b;
    string col;
    a2>>col;


    a3 << c;
    string result;
    a3>>result;


    string outstr = row+","+ col+":"+ result+"\n";




    if (Result1 < 0){

        Result1 = 5 - (  (-Result1)%5);

    }


    // Direction

    if ((Result1 % 5) == 0){

        return outstr;

    }


    else if((Result1 % 5) == 1){

        obj.setCurRow(obj.getCurRow() - obj.getKeySize());


        if ( (obj.getCurRow() - (obj.getKeySize()/2)) < 0){

            obj.setCurRow(obj.getCurRow() + (2*obj.getKeySize()) );
            // call function
            return outstr+Multiplier(obj,KeyMatrix,MapMatrix);


        }
        else{

            // call function
            return outstr+Multiplier(obj,KeyMatrix,MapMatrix);

        }


    }

    else if((Result1 % 5) == 2){

        obj.setCurRow(obj.getCurRow() + obj.getKeySize());

        if ( (obj.getCurRow() + (obj.getKeySize()/2)) > obj.getMapRow()-1){

            obj.setCurRow(obj.getCurRow() - (2*obj.getKeySize()) );
            // call function
            return outstr+Multiplier(obj,KeyMatrix,MapMatrix);

        }
        else{
            // call function
            return outstr+Multiplier(obj,KeyMatrix,MapMatrix);

        }

    }
    else if((Result1 % 5) == 3){

        obj.setCurCol(obj.getCurCol() +  obj.getKeySize() );

        if ( (obj.getCurCol() + (obj.getKeySize()/2)) > obj.getMapCol()-1){

            obj.setCurCol( obj.getCurCol() - (2*obj.getKeySize()));
            // call function
            return outstr+Multiplier(obj,KeyMatrix,MapMatrix);

        }
        else{
            // call function
            return outstr+Multiplier(obj,KeyMatrix,MapMatrix);

        }

    }
    else if((Result1 % 5) == 4){

        obj.setCurCol(obj.getCurCol() -  obj.getKeySize() );

        if ( (obj.getCurCol()) - (obj.getKeySize()/2) < 0){ // Map Col 18

            obj.setCurCol( obj.getCurCol() + (2*obj.getKeySize()));
            // call function
            return outstr+Multiplier(obj,KeyMatrix,MapMatrix);

        }
        else{
            // call function
            return outstr+Multiplier(obj,KeyMatrix,MapMatrix);

        }

    }
}



// GETTER AND SETTERS

int Machine::getMapRow() const {
    return MapRow;
}

void Machine::setMapRow(int mapRow) {
    MapRow = mapRow;
}

int Machine::getMapCol() const {
    return MapCol;
}

void Machine::setMapCol(int mapCol) {
    MapCol = mapCol;
}

int Machine::getKeySize() const {
    return KeySize;
}

void Machine::setKeySize(int keySize) {
    KeySize = keySize;
}

const string &Machine::getMapTxt() const {
    return MapTXT;
}

void Machine::setMapTxt(const string &mapTxt) {
    MapTXT = mapTxt;
}

const string &Machine::getKeyTxt() const {
    return KeyTXT;
}

void Machine::setKeyTxt(const string &keyTxt) {
    KeyTXT = keyTxt;
}

const string &Machine::getOutTxt() const {
    return OutTXT;
}

void Machine::setOutTxt(const string &outTxt) {
    OutTXT = outTxt;
}


int Machine::getCurRow() const {
    return CurRow;
}

void Machine::setCurRow(int curRow) {
    CurRow = curRow;
}

int Machine::getCurCol() const {
    return CurCol;
}

void Machine::setCurCol(int curCol) {
    CurCol = curCol;
}

const string &Machine::getOutputString() const {
    return OutputString;
}

void Machine::setOutputString(const string &outputString) {
    OutputString = outputString;
}










