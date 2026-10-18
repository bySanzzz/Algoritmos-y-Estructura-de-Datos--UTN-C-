#include <iostream>
using namespace std;

int main(){
    return 0;
}

void funcion(){
    /*
    [1 2 3 4]
    [5 6 7 8]
    [9 0 1 2]
    */

    //tipoDato nombre[][]
    int matNumeros[3][3];
    matNumeros[0][0] = 100;
    int filas = 3, columnas = 3;
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout << matNumeros[i][j] << endl;
        }
    }
}

/*
1) defino una variable auxiliar, tiene que tener el mismo tipo de dato que el vector.
2) 1er for: cuenta cuantas veces, repetimos el ordenamiento. Siempre descarta al último elemento [i < tamVec - 1]
3) 2da for: es el ordenamiento, recorrer al vector tirando los más pesados o ligeros hacia el fondo [j < tamVec - 1 - i]
    a) por cada elemento al que vaya
        si (act > sgte){
            aux = act;
            act = sgte;
            sgte = aux;
        }

1ra vuelta [5 - 1 - 0 = 4]
[4] - 1 - 5 - 2 - 3
1 - [4] - 5 - 2 - 3
1 - 4 - [5] - 2 - 3
1 - 4 - 2 - [5] - 3
1 - 4 - 2 - 3 | 5

2da vuelta [5 - 1 - 1]
[1] - 4 - 2 | 3
1 - [4] - 2 | 3
1 - 2 - [4] | 3
1 - 2 - 3 | 4

3ra vuelta
[1] - 2 | 3
1 - [2] | 3
1 - 2 | 3

4ta vuelta
[1] | 2
1 | 2
*/

struct Alumno{
    int legajo;
    float promedio;
};

void ordenamiento(Alumno vec[], int tamVec){
    Alumno aux;

    for(int i = 0; i < tamVec - 1; i++){
        for(int j = 0; j < tamVec - 1 - i; j++){
            if(vec[j].legajo > vec[j+1].legajo){
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }
}


