#include <iostream>
using namespace std;

struct Alumno{
    int legajo;
    float promedio;
};

int main(){
    /*
    puntero: variable que guarda la dirección de memoria de otro elemento

    xxx1    valor = 20;
    xxx2    *pValor = &valor;
    xxx5    **dirPValor = &pValor;
    */
    int valor = 20;
    int *pValor = &valor;
    cout << pValor << endl; // -> dirMemoria valor
    *pValor = 200; // -> desrreferenciar una variable, o sea, la convierto del tipo puntero al tipo valor;
    cout << valor << endl;

    int **dirpValor = &pValor; // ->
    cout << dirpValor << endl;
    cout << **dirpValor << endl;

    cout << "==========================" << endl;
    int vec[3] = {100,200,300};
    cout << vec << endl; // dirMem -> vec[0]
    cout << (vec+1) << endl; // dirMem -> vec[1]
    cout << (vec+2) << endl; // dirMem -> vec[1]


    //td *nombreVar = new td;
    int *var = new int;
    *var = 200;
    delete var;

    int *vecNumeros = new int[3];
    vecNumeros[0] = 100;
    vecNumeros[1] = 200;
    vecNumeros[2] = 300;
    delete[] vecNumeros;

    Alumno *info = new Alumno();
    info->legajo = 12983;
    info->promedio = 10;
    delete info;


    return 0;
}