#include <cstdlib>
#include <iostream>

#include "vector.h"

using namespace std;

template <typename T>
struct Dimensions {      
    int operator()(int* coordinates, int* sizes, int dimensions) {
        int num = coordinates[0]-1;
        int sizevalue = 1;
        for(int i = 1; i <= dimensions-1; i++){
            sizevalue *= sizes[i-1];
            num += (coordinates[i]-1)*sizevalue;
        }
        return num;
        // TODO
    }
};

struct Integer {
       typedef int T;
       typedef Dimensions<T> Operation;
};

int main(int argc, char *argv[]) {
    int* sizes = new int [3];
    sizes[0] = 3;
    sizes[1] = 3;
    sizes[2] = 3;
    int* coordenadas = new int [3];
    auto dimension = Vector<Integer>(3,sizes);
    int cont = 0;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            for(int k = 1; k <= 3; k++){
                coordenadas[0] = i;
                coordenadas[1] = j;
                coordenadas[2] = k;
                cont ++;
                dimension.set(cont,coordenadas);
            }
        }
    }
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            for(int k = 1; k <= 3; k++){
                coordenadas[0] = i;
                coordenadas[1] = j;
                coordenadas[2] = k;
                cout << dimension.get(coordenadas) << " ";
            }
        }
    }
    //    system("pause");
    return EXIT_SUCCESS;
}