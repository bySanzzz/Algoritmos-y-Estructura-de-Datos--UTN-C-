#include <iostream>
#include <stack>
using namespace std;

struct Nodo{
    int info;        // el dato
    Nodo *sgte;      // la dirección del nodo que tiene debajo 
}; //[ info | sgte ]//

Nodo *pila = NULL; // Creo pila 

void push(Nodo *&pila, int dato){
    Nodo *nuevo = new Nodo();   // 1) crear un nodo
    nuevo->sgte = pila;         // 3) que apunte al que era el tope
    pila = nuevo;                nuevo->info = dato;         // 2) guardarle el dato
   // 4) ahora el tope es el nuevo
}

int pop(Nodo *&pila){
    Nodo *aux = pila;       // 1) me guardo el nodo del tope
    int ret = aux->info;    // 2) me guardo su dato
    pila = aux->sgte;       // 3) el tope pasa a ser el de abajo
    delete aux;             // 4) libero el nodo viejo
    return ret;             // 5) devuelvo el dato
}

/*
=====================================================
NIVEL 1
=====================================================
*/

/*
CONSIGNA 1
Dada una lista de 10 números enteros, cargarlos en una pila. Luego,
mostrar los elementos por pantalla desapilándolos.
*/
// Tu resolución acá

void agregarMostrarElementos(int vecNumeros[], int tamVecNumeros,Nodo *&pila){
    for(int i = 0; i< tamVecNumeros; i++){
        push(pila,vecNumeros[i]);// pila y su dato
    }

    while(pila != NULL){
        int info = pop(pila); //Solo la pila
        cout << info << endl;
    }
    
}

/*
CONSIGNA 2
Escribir una función que reciba una pila cargada con números enteros
y un número X. La función debe agregar el número X al tope de la pila
solamente si la pila no está vacía.
*/
// Tu resolución acá



/*
CONSIGNA 3
Realizar una función que reciba una pila y devuelva la cantidad de
elementos que contiene (la pila original debe quedar en su estado
inicial).
*/
// Tu resolución acá
int contar(Nodo *&pila){
    Nodo *pilaAux = NULL;
    int contElem = 0;

    while(pila != NULL){
        push(pilaAux,pop(pila)); 
        contElem++;
    }

    while(pilaAux != NULL){
        push(pila,pop(pilaAux));
    }
}


/*
CONSIGNA 4
Dada una pila de enteros, diseñar una función que calcule y devuelva
la suma de todos sus elementos sin alterar el contenido original de
la pila.
*/
// Tu resolución acá
int contar(Nodo *&pila){
    Nodo *pilaAux = NULL;
    int sumTotal = 0 ;

    while(pila != NULL){
        int valor = pop(pila);
        sumTotal = valor + sumTotal;
        push(pilaAux,valor); 
        
    }

    while(pilaAux != NULL){
        push(pila,pop(pilaAux));
    } 
    return sumTotal;
}




/*
CONSIGNA 5
Escribir una función que reciba una pila y reemplace todas las
ocurrencias de un número N (dado por el usuario) por un nuevo valor M.
*/
// Tu resolución acá
void reemplazar(Nodo *&pila, int n , int m){
    Nodo *pilaAux = NULL;
    while(pila != NULL){
        int valor = pop(pila);
        if (n == valor){
            valor = m;
        }
        push(pilaAux,valor); 
    }
    while (pilaAux != NULL){
        push(pila,pop(pilaAux));
    }
}




/*
CONSIGNA 6
Construir una función que reciba una pila y devuelva el promedio de
sus valores.
*/
float prom(Nodo *&pila){
    float sumTotal = 0 ;
    float cont = 0;
    float promE = 0;

    while(pila != NULL){
        float valor = pop(pila);
        sumTotal = valor + sumTotal;
        cont++;
    }
    if (sumTotal != 0 ){
        float promE = sumTotal / cont;
    }
   
    return promE;
}


/*
CONSIGNA 7
Dada una pila con números enteros, realizar una función que determine
cuál es el valor mínimo almacenado en ella. Restaurar la pila original
antes de terminar.
*/
void minimo(Nodo *&pila){
    Nodo *auxPila = NULL;

    int minAbs = pop(pila);
    push(auxPila,minAbs);

    while (pila != NULL){
       int aux =  pop(pila);
       if (minAbs > aux){
            minAbs = aux;
       }
       push(auxPila,aux);
    }
    while (auxPila != NULL){
        push(pila,pop(auxPila));
    }
    
}

/*
CONSIGNA 8
Escribir una función que reciba una pila (origen) y pase sus elementos
a otra pila (destino) de modo que el orden de los elementos en la pila
destino sea el mismo que en la origen.
*/
// Tu resolución acá
void origenyDestino(Nodo *&pilaOrigen, Nodo *&pilaDestino){
    Nodo *pilAux = NULL;
    while (pilaOrigen != NULL){
        push(pilAux,pop(pilaOrigen));
    }
    while (pilAux != NULL){
        push(pilaDestino,pop(pilAux));
    }
}


/*
=====================================================
NIVEL 2
=====================================================
*/

/*
CONSIGNA 9
Dada una pila de números enteros, dividirla en dos nuevas pilas: una
que contenga solo los números pares y otra con los impares. La pila
original debe quedar vacía.
*/
// Tu resolución acá
void paresEimpares(Nodo *&pila){
    Nodo *pilaPares = NULL;
    Nodo *pilaImpares = NULL;
    while (pila != NULL){
        int verificador = pop(pila);
        if (verificador % 2 == 0){
            push(pilaPares,verificador);
        }else{
            push(pilaImpares, verificador);
        }
    }
}

/*
CONSIGNA 10
Diseñar una función que reciba dos pilas (A y B) y determine si son
exactamente iguales (mismo tamaño, mismos elementos en el mismo orden).
*/
// Tu resolución acá
void igualesPilas(Nodo *&pilaA, Nodo *&pilaB){
    bool Igualdad = true;
    while (pilaA != NULL && pilaB != NULL){
        if (pop(pilaA) != pop(pilaB)) {
            Igualdad = false;
        }
    }
    if (pilaA == NULL && pilaB != NULL){
        cout << "No tienen el mismo tamaño"<<endl;
    }
    if (pilaA != NULL && pilaB == NULL){
        cout << "No tienen el mismo tamaño"<<endl;
    }

}




/*
CONSIGNA 11
Dada una pila de caracteres, determinar si la secuencia forma un
palíndromo (se lee igual al derecho y al revés).
*/
// Tu resolución acá



/*
CONSIGNA 12
Escribir una función que reciba una pila y un valor X. La función debe
eliminar todas las ocurrencias de X en la pila, conservando el orden
del resto de los elementos.
*/
// Tu resolución acá

void reemplazar(Nodo *&pila, int x){
    Nodo *pilaAux = NULL;
    while(pila != NULL){
        int valor = pop(pila);
        if (valor != x){
            push(pilaAux,valor); 
        }
    }
    while (pilaAux != NULL){
        push(pila,pop(pilaAux));
    }
}

/*
CONSIGNA 13
Dada una pila cargada con números enteros, insertar un nuevo elemento X
en la posición de "fondo" de la pila (es decir, debe quedar debajo de
todo).
*/
// Tu resolución acá
void elementoX(Nodo *&pila, int x){
    Nodo *pilaAux = NULL;
    while (pila != NULL){
        push(pilaAux,pop(pila));
    }
    push(pila,x);
     while (pilaAux != NULL){
        push(pila,pop(pilaAux));
    }

}


/*
CONSIGNA 14
Realizar una función que reciba una pila y mueva el elemento que está
en el fondo hacia el tope, desplazando los demás hacia abajo,
manteniendo su orden relativo.
*/
// Tu resolución acá
void funcion(Nodo *&pila){ 
    Nodo *pilaAux = NULL;
    
    while (pila != NULL){
        int tope = pop(pila);
        push(pilaAux,tope);
    }
    while (pilaAux != NULL){
        int valor = pop(pilaAux);
        if (tope != valor) {
            push(pila,valor);
        }
    }
    push(pila,tope);

}



/*
=====================================================
NIVEL 3
=====================================================
*/

/*
CONSIGNA 15
Dada una pila de enteros ordenada de menor a mayor (donde el tope es el
mayor), realizar una función que inserte un nuevo número manteniendo el
orden de la pila.
*/
// Tu resolución acá



/*
CONSIGNA 16
Escribir una función que ordene una pila de números enteros de mayor a
menor. Se permite el uso de una sola pila auxiliar, pero no de otros
arrays o vectores.
*/
// Tu resolución acá



/*
CONSIGNA 17
Dadas dos pilas ordenadas de forma creciente, generar una tercera pila
que contenga la unión de ambas, también ordenada.
*/
// Tu resolución acá



/*
CONSIGNA 18
Dada una pila que contiene números positivos y negativos, reorganizarla
de manera que queden primero los negativos (en el fondo) y luego los
positivos (en el tope), manteniendo el orden relativo original de
llegada de cada grupo.
*/
// Tu resolución acá



/*
CONSIGNA 19
Implementar una función que reciba una pila con números repetidos y
elimine los duplicados, dejando solo la primera aparición de cada
número.
*/
// Tu resolución acá



/*
CONSIGNA 20
Dadas 3 pilas (Origen, Auxiliar, Destino), simular el movimiento de 3
discos (representados por los números 3, 2, 1) desde Origen a Destino,
cumpliendo la regla de que nunca un número mayor puede estar sobre uno
menor.
*/
// Tu resolución acá



/*
=====================================================
NIVEL 4
=====================================================
*/

/*
CONSIGNA 21
Invertir el contenido de una pila utilizando exclusivamente una única
pila auxiliar y una variable de tipo entero.
*/
// Tu resolución acá



/*
CONSIGNA 22
Desarrollar una función que elimine el enésimo elemento contando desde
el tope hacia abajo, validando que la pila tenga al menos esa cantidad
de elementos.
*/
// Tu resolución acá



/*
CONSIGNA 23
Dadas dos pilas de diferentes tamaños, generar una tercera pila que
intercale sus elementos uno a uno hasta que ambas queden vacías.
*/
// Tu resolución acá



/*
CONSIGNA 24
Escribir una función que evalúe una cadena de caracteres que contiene
paréntesis (), corchetes [] y llaves {} y determine, utilizando una
pila, si la expresión está correctamente balanceada.
*/
// Tu resolución acá



/*
CONSIGNA 25
Dada una pila de cadenas de texto (strings), buscar una palabra
específica. Si existe, moverla al tope de la pila; si no, dejar la pila
intacta.
*/
// Tu resolución acá



/*
CONSIGNA 26
Desarrollar un procedimiento que purgue una pila de enteros,
eliminando únicamente aquellos números que sean primos.
*/
// Tu resolución acá



/*
CONSIGNA 27
Simular el comportamiento de una Cola (FIFO: First In, First Out)
empleando internamente solo dos Pilas (LIFO). Implementar las
funciones de encolar y desencolar bajo esta restricción.
*/
// Tu resolución acá



/*
CONSIGNA 28
Rotar los elementos de una pila una posición hacia arriba: el elemento
del tope debe pasar al fondo, y todos los demás suben una posición.
*/
// Tu resolución acá



/*
CONSIGNA 29
Encontrar el segundo valor más grande almacenado en una pila de números
reales sin aplicar ningún método de ordenamiento masivo sobre la
estructura.
*/
// Tu resolución acá



/*
CONSIGNA 30
Dada una expresión matemática en notación postfija (Polaca Inversa)
representada en una colección de strings, utilizar una pila de
operandos para evaluar la expresión y devolver el resultado numérico
final.
*/
// Tu resolución acá