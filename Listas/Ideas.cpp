#include <iostream>
using namespace std;

/*
=====================================================
IDEA CENTRAL
Una lista es un puntero al PRIMER nodo.
Si ese puntero es NULL, la lista está vacía.
Todo lo demás es moverse con punteros auxiliares sin perder ese primero.

    lista --> [2|•] --> [5|•] --> [9|•] --> NULL
=====================================================
*/

struct Nodo{
    int info;      // el dato que guarda el nodo
    Nodo *sgte;    // dirección del nodo siguiente (NULL si es el último)
};


/*
=====================================================
1) NODO *LISTA vs NODO *&LISTA
Es lo mismo que viste con las pilas.

- Sin &: la función recibe una COPIA de la dirección del primer nodo.
  Se usa en funciones que solo miran (mostrar, buscar, contar).

- Con &: la función trabaja sobre el puntero ORIGINAL.
  Se usa en funciones que pueden cambiar a qué nodo apunta lista
  (insertar, eliminar). Sin el &, ese cambio se pierde al terminar.

Si el cambio es solo en el medio de la lista (aux->sgte = ...) el &
no es imprescindible, porque modificás nodos que existen afuera.
Pero en cuanto puede cambiar EL PRIMERO (lista vacía, insertar al
principio, borrar el primero), sin & el cambio se pierde.
=====================================================
*/


/*
=====================================================
2) RECORRER UNA LISTA: siempre con un aux
Si avanzaras con lista = lista->sgte, perderías la dirección del
primer nodo y no podrías volver. aux es una copia: moverla no toca
a lista.
=====================================================
*/
void mostrarLista(Nodo *lista){          // sin &: solo mira
    Nodo *aux = lista;                   // aux arranca en el primer nodo
    while (aux != NULL){
        cout << aux->info << endl;       // acá hacés lo que necesites con el nodo
        aux = aux->sgte;                 // avanzo al siguiente
    }
}


/*
=====================================================
3) AGREGAR UN NODO: tres pasos
   1) Crear el nodo:           Nodo *nuevo = new Nodo();
   2) Cargarle el dato:        nuevo->info = valor;
   3) Engancharlo en su lugar  (el único paso que cambia según dónde
                                lo quieras)
=====================================================
*/

// --- Insertar al PRINCIPIO (el más simple, igual que push) ---
void insertarPrincipio(Nodo *&lista, int valor){
    Nodo *nuevo = new Nodo();
    nuevo->info = valor;
    nuevo->sgte = lista;      // el nuevo apunta al que era el primero
    lista = nuevo;            // ahora el nuevo es el primero
}

// --- Insertar al FINAL (hay que llegar hasta el último nodo) ---
void insertarFinal(Nodo *&lista, int valor){
    Nodo *nuevo = new Nodo();
    nuevo->info = valor;
    nuevo->sgte = NULL;               // va a ser el último: detrás no tiene a nadie

    if (lista == NULL){               // caso borde: lista vacía
        lista = nuevo;                // el nuevo es el único nodo
    } else {
        Nodo *aux = lista;
        while (aux->sgte != NULL){    // me detengo EN el último, no después
            aux = aux->sgte;
        }
        aux->sgte = nuevo;            // el último ahora apunta al nuevo
    }
}
// Fijate que el ciclo es aux->sgte != NULL y no aux != NULL.
// Con la segunda, aux terminaría en NULL y ya no tendrías el último
// nodo para enganchar el nuevo.


/*
=====================================================
4) QUITAR UN NODO
Hay que moverse hasta donde está el nodo, reconectar la lista para
saltearlo y recién ahí hacer el delete.
=====================================================
*/

// --- Eliminar el PRIMER nodo ---
void eliminarPrimeroLista(Nodo *&lista){
    if (lista == NULL) return;    // caso borde: lista vacía, no hay nada que borrar

    Nodo *aux = lista;            // guardo el primero para poder borrarlo
    lista = aux->sgte;            // el primero pasa a ser el segundo
    delete aux;                   // libero el nodo viejo
}
// Ojo con el PDF: en su versión hay un "int dato = aux->info;" que no se
// usa para nada, y la función se cae si la lista está vacía.


/*
=====================================================
5) CASOS BORDE (cuando el código "normal" se rompe)
Antes de escribir una función, preguntate:

  - ¿La lista está vacía?   (lista == NULL)
    Cualquier lista->algo se cae.

  - ¿Tiene un solo nodo?    (lista->sgte == NULL)
    Muchas veces el primero también es el último.

  - ¿El puntero de la izquierda de una flecha podría ser NULL?
    Hacer aux->sgte con aux == NULL compila bien, pero el programa se
    cae al ejecutarlo (el PDF dice "puede no compilar", y en realidad es
    peor: el compilador no te avisa).

El orden en las condiciones con && también importa:
    actual != NULL && actual->info < valor
Funciona porque, si actual es NULL, C++ no evalúa lo de la derecha.
Si lo escribieras al revés, se caería.
=====================================================
*/


/*
=====================================================
6) ANT Y ACTUAL: para insertar en el medio o borrar un nodo específico
Para insertar en el medio no alcanza con encontrar el nodo que viene
DESPUÉS: necesitás también el de ANTES, para reconectarlo. Por eso se
usan dos punteros que avanzan juntos, con ant siempre un paso atrás.
=====================================================
*/

// --- Insertar en una lista ORDENADA de menor a mayor ---
void insertarOrdenado(Nodo *&lista, int valor){
    // 1) crear el nodo y cargarle el dato
    Nodo *nuevo = new Nodo();
    nuevo->info = valor;

    // 2) buscar la posición
    Nodo *actual = lista;
    Nodo *ant = NULL;
    while (actual != NULL && actual->info < valor){
        ant = actual;               // ant se queda con donde estaba actual
        actual = actual->sgte;      // actual avanza
    }

    // 3) reconectar
    nuevo->sgte = actual;           // el nuevo apunta al primero que NO es menor
    if (ant == NULL){
        lista = nuevo;              // no avancé nada: el nuevo va al principio
    } else {
        ant->sgte = nuevo;          // el anterior ahora apunta al nuevo
    }
}
/*
Traza con la lista 2, 5, 9 y valor = 7:

    Arranque:   ant = NULL   actual = [2]    2 < 7 -> avanzo
    Vuelta 1:   ant = [2]    actual = [5]    5 < 7 -> avanzo
    Vuelta 2:   ant = [5]    actual = [9]    9 < 7 es falso -> paro

    Antes:    [2] --> [5] --> [9] --> NULL

    nuevo->sgte = actual :     [7] --> [9]
    ant->sgte   = nuevo  :     [5] --> [7]

    Después:  [2] --> [5] --> [7] --> [9] --> NULL

El orden de los dos enganches importa, igual que en push: primero
nuevo->sgte = actual y después ant->sgte = nuevo. Si cortás antes de
guardar a dónde apuntaba ant, perdés el resto de la lista.

ant == NULL significa que el ciclo no avanzó nunca: el nuevo es menor
que todos (o la lista estaba vacía) y pasa a ser el primero. Es el
caso que el PDF pide separar.
*/

// --- Eliminar un nodo con un valor específico ---
// Usa el mismo recorrido, pero en vez de enganchar un nodo, lo saltea
void eliminarValor(Nodo *&lista, int valor){
    Nodo *actual = lista;
    Nodo *ant = NULL;
    while (actual != NULL && actual->info != valor){
        ant = actual;
        actual = actual->sgte;
    }

    if (actual == NULL) return;     // el valor no estaba en la lista

    if (ant == NULL){
        lista = actual->sgte;       // era el primero: la lista arranca en el segundo
    } else {
        ant->sgte = actual->sgte;   // el anterior se salta a actual
    }
    delete actual;                  // libero el nodo salteado
}


/*
=====================================================
PARA COMPROBAR QUE LO ENTENDISTE
Con la lista 3, 6, 8 y insertarOrdenado(lista, 5):
¿en qué nodos quedan parados ant y actual cuando el ciclo termina,
y cómo queda la lista? Hacé la traza como la de arriba.
=====================================================
*/

int main(){
    Nodo *lista = NULL;          // lista vacía

    insertarFinal(lista, 3);
    insertarFinal(lista, 6);
    insertarFinal(lista, 8);

    insertarOrdenado(lista, 5);
    mostrarLista(lista);

    return 0;
}