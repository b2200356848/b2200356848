#include <iostream>
#include "Machine.h"


using namespace std;

int main() {

    const char* argv[6];

    argv[1]="18x18";
    argv[2]="3";
    argv[3]="mapmatrix.txt";
    argv[4]="keymatrix.txt";
    argv[5]="output.txt";

    Machine OBJECT ;

    OBJECT.MapDim(argv[1],OBJECT,argv[2],argv[3],argv[4],argv[5]);

    cout<<OBJECT.getKeySize()<<"\n";

    int** KeyMatrix = new int * [OBJECT.getKeySize()];  // Dynamic Alloc 1D

    for (int i = 0; i < OBJECT.getKeySize(); i++) {
        // Dynamic Alloc 2D
        KeyMatrix[i] = new int[OBJECT.getKeySize()];
    }


    int ** MapMatrix = new int * [OBJECT.getMapRow()];  // Dynamic Alloc 1D

    for (int i = 0; i < OBJECT.getMapRow(); i++) {      // Dynamic Alloc 2D
        MapMatrix[i] = new int[OBJECT.getMapCol()];
    }



    OBJECT.ReaderFunc(OBJECT,KeyMatrix,MapMatrix);

    OBJECT.StartDefine(OBJECT);

    string O=OBJECT.Multiplier(OBJECT,KeyMatrix,MapMatrix);

    OBJECT.setOutputString(O);
    // Call Multiply Function



    // Freeing the allocated memory

    for (int i = 0; i < 18; i++) {
        delete[] MapMatrix[i];
    }
    delete[] MapMatrix;

    for (int i = 0; i < 3; i++) {
        delete[] KeyMatrix[i];
    }
    delete[] KeyMatrix;


    return 0;

}


