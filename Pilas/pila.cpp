#include <iostream>
using namespace std;

template <typename T>
struct Nodo{
    T info;
    Nodo<T> *sgte;
};

/*
Cuando yo quiera agregar un dato, necesto saber dos cosas: donde? que?
*/
template <typename T>
void push(Nodo<T> *&pila, T dato){
    Nodo<T> *nuevo = new Nodo<T>();
    nuevo->info = dato; 
    nuevo->sgte = pila;
    pila = nuevo;
}

/*
Cuando yo quiera quitar un dato y retornarlo, necesto saber dos cosas: donde? de que tipo es el dato?
*/
template <typename T>
T pop(Nodo<T> *&pila){
    Nodo<T> *aux = pila;
    T ret = aux->info;
    pila = aux->sgte;
    delete aux;
    return ret;
}

struct Empleado{
    int legajo;
    float sueldo;
};

//operar pilas

void funcion(){
    //como creo una pila
    Nodo<int> *pila = NULL;
    Nodo<Empleado> *pilaEmp = NULL;
    Nodo<float> *pilaFloat = NULL;

    //como agrego un elemento:
    push(pila,100);
    push(pila,101);
    push(pila,102);
    push(pila,103);


    //como quito un elemento
    int dato = pop(pila);
    cout << dato << endl;
    
    while(pila != NULL){
        int dato = pop(pila);
        cout << dato << endl;
    }

    int resInt = suma<int>(10,20);
    float resFloat = suma<float>(10.90,20.49);
}

template <typename T>
T suma(T a, T b){
    return a + b;
}


/*Dada una lista de 10 números enteros, cargarlos en una pila. Luego, mostrar los elementos por pantalla desapilándolos */

void agregarMostrarElementos(int vecNumeros[], int tamVecNumeros,Nodo<int> *&pila){
    for(int i = 0; i< tamVecNumeros; i++){
        push(pila,vecNumeros[i]);
    }

    while(pila != NULL){
        int info = pop(pila);
        cout << info << endl;
    }
    
}

/*Realizar una función que reciba una pila y devuelva la cantidad de elementos que contiene. */
int contar(Nodo<int> *&pila){
    Nodo<int> *pilaAux = NULL;
    int contElem = 0;

    while(pila != NULL){
        push(pilaAux,pop(pila));
        contElem++;
    }

    while(pilaAux != NULL){
        push(pila,pop(pilaAux));
    }
}
