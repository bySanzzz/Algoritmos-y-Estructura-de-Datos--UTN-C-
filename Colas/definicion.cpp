#include <cstddef>   // define NULL
#include <iostream>
using namespace std;

// Cada nodo es una "cajita" de la cola: guarda un dato y la dirección del nodo que está detrás
struct Nodo{
    int info;      // el dato que guarda este nodo
    Nodo *sgte;    // dirección del nodo que viene después (NULL si es el último)
};


// ENCOLAR: agrega un dato al FINAL de la cola
// frente y fin llevan *& porque la función los puede modificar y el cambio tiene que verse afuera
void queue(Nodo *&frente, Nodo *&fin, int dato){
    Nodo *nuevo = new Nodo();   // 1) crea un nodo suelto en memoria
    nuevo->info = dato;         // 2) le guarda el dato
    nuevo->sgte = NULL;         // 3) como va a ser el último, detrás no tiene a nadie

    if (frente == NULL){        // 4) caso cola vacía:
        frente = nuevo;         //    el nodo nuevo es el único, así que también es el frente
    } else {                    //    caso cola con elementos:
        fin->sgte = nuevo;      //    el que era el último ahora apunta al nuevo (lo engancha detrás)
    }
    fin = nuevo;                // 5) en los dos casos, el nodo nuevo pasa a ser el último
}


// DESENCOLAR: saca el dato del FRENTE de la cola y lo devuelve
int unqueue(Nodo *&frente, Nodo *&fin){
    if (frente == NULL) return false;   // si la cola está vacía no hay nada que sacar
                                        // (ojo: false vale 0, y se confunde con un 0 real de la cola)

    int retorno = frente->info;   // 1) guarda el dato del primero antes de borrar nada
    Nodo *aux = frente;           // 2) guarda el nodo para poder borrarlo después
    frente = frente->sgte;        // 3) el frente avanza al nodo siguiente

    if (frente == NULL){          // 4) si al avanzar la cola quedó vacía...
        fin = NULL;               //    ...fin también tiene que quedar en NULL (si no, apuntaría a un nodo ya borrado)
    }

    delete aux;                   // 5) libera la memoria del nodo viejo
    return retorno;               // 6) devuelve el dato que guardamos en el paso 1
}


// COLA VACÍA: dice si la cola no tiene elementos
// recibe frente sin *& porque solo lo mira, no lo modifica
bool colaVacia(Nodo *frente){
    return (frente == NULL);      // true si frente no apunta a nada
}


// EJEMPLO DE USO
int main(){
    Nodo *frente = NULL;          // cola vacía: los dos punteros arrancan en NULL
    Nodo *fin = NULL;

    queue(frente, fin, 5);        // cola: 5
    queue(frente, fin, 7);        // cola: 5, 7
    queue(frente, fin, 9);        // cola: 5, 7, 9

    while (!colaVacia(frente)){   // mientras haya elementos...
        cout << unqueue(frente, fin) << endl;   // ...los saca y muestra: 5, 7, 9
    }

    return 0;
}