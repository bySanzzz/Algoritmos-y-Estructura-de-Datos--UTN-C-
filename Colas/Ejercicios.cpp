#include <iostream>
using namespace std;
#define tamListadoVec

struct Nodo{
       int info;
       Nodo *sgte;
};
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







/*
=====================================================
NIVEL FÁCIL
=====================================================
*/

/*
CONSIGNA 1
Dada una lista de 10 números enteros, cargarlos en una cola y luego
mostrarlos por pantalla desencolándolos.
*/
// Tu resolución acá
void mostrarDescolado(Nodo *&frente, Nodo *&fin, int vecListadodeNumeros[], int tamListadoVec){
    
    for(int i = 0 ; i < tamListadoVec; i++){
        int valor = vecListadodeNumeros[i];
        queue(frente,fin,valor);    
    }
    while (frente != NULL){
        cout << unqueue(frente,fin) << endl;
    }
}
/*
CONSIGNA 2
Escribir una función que devuelva la cantidad de elementos que
contiene una cola, sin alterar el contenido original de la estructura.
*/
// Tu resolución acá

int cantElementos(Nodo *&frente, Nodo *&fin){
    Nodo *FrenteAux = NULL;
    Nodo *FinAux = NULL;
    int cantVueltas = 0;
    while (frente != NULL){
        int valor = unqueue(frente, fin);
        queue(FrenteAux,FinAux, valor);
        cantVueltas++;
    }
    while (FrenteAux != NULL){
        int valor = unqueue(FrenteAux,FinAux);
        queue(frente, fin, valor);
    }
    return cantVueltas;

}

/*
CONSIGNA 3
Realizar una función que calcule el promedio de los valores
almacenados en una cola de números reales.
*/
// Tu resolución acá
int promedioCola(Nodo *&frente, Nodo *&fin){
    Nodo *auxFrente = NULL;
    Nodo *auxFin = NULL;
    int sumTotal;
    int cant = 0;
    while (frente != NULL){
        int sum = unqueue(frente,fin);
        int sumTotal = sumTotal + sum;
        cant++;
        queue(auxFrente,auxFin,sum);
    }
    int prom = sumTotal/cant;
    return prom;
}


/*
CONSIGNA 4
Crear una función que reciba una cola y devuelva el valor máximo
almacenado en ella, dejando la cola intacta tras la ejecución.
*/
// Tu resolución acá



/*
CONSIGNA 5
Diseñar una función que reciba una cola de enteros y un valor X, y
agregue ese valor X al final de la cola solo si no existe ya en la
misma, evitando duplicados.
*/
// Tu resolución acá



/*
CONSIGNA 6
Dada una cola con caracteres, generar una segunda cola que contenga
los mismos elementos pero eliminando aquellos que sean vocales.
*/
// Tu resolución acá



/*
CONSIGNA 7
Construir una función que elimine todas las ocurrencias de un número
dado por el usuario en una cola, manteniendo el orden relativo del
resto de los elementos.
*/
// Tu resolución acá



/*
CONSIGNA 8
Escribir una función que reciba dos colas (A y B) y devuelva una
tercera cola (C) que sea la concatenación de ambas (primero los
elementos de A y luego los de B).
*/
// Tu resolución acá



/*
CONSIGNA 9
Definir la estructura Cliente con los campos nombre y tipo de trámite.
Cargar 5 clientes en una cola y procesarlos (desencolarlos) mostrando
por pantalla qué trámite está realizando cada uno.
*/
// Tu resolución acá



/*
CONSIGNA 10
Definir la estructura Factura con número de factura y monto. Encolar 8
facturas e implementar una función que procese la cola para calcular e
informar el monto total facturado.
*/
// Tu resolución acá



/*
=====================================================
NIVEL INTERMEDIO
=====================================================
*/

/*
CONSIGNA 11
Implementar una función que "rote" una cola N veces, donde rotar
significa quitar el elemento del frente y volver a insertarlo al
final.
*/
// Tu resolución acá



/*
CONSIGNA 12
Realizar una función que reciba una cola y la divida en dos nuevas
colas: una con los elementos menores a su promedio y otra con los
mayores o iguales.
*/
// Tu resolución acá



/*
CONSIGNA 13
Dada una cola de enteros, eliminar todos los elementos que sean
consecutivos iguales (Ejemplo: de 1, 2, 2, 3 pasará a ser 1, 2, 3).
*/
// Tu resolución acá



/*
CONSIGNA 14
Escribir una función que verifique si una cola de números enteros está
ordenada de forma creciente, devolviendo un valor booleano y dejando
la cola intacta.
*/
// Tu resolución acá



/*
CONSIGNA 15
Insertar un elemento en una posición específica de la cola (por
ejemplo, en la posición 3), desplazando de forma correcta los
elementos siguientes.
*/
// Tu resolución acá



/*
CONSIGNA 16
Definir la estructura Articulo con código, descripción y precio.
Encolar 10 artículos y buscar un código recibido por parámetro,
rotando la cola para no perder los datos e informando su precio al
hallarlo.
*/
// Tu resolución acá



/*
CONSIGNA 17
Implementar una función que reciba dos colas ordenadas de enteros y
las fusione en una tercera cola resultante que también mantenga el
orden ascendente.
*/
// Tu resolución acá



/*
CONSIGNA 18
Definir la estructura Mascota con nombre, especie y edad. Dada una
cola de mascotas, separar los datos en dos colas distintas: una
exclusiva para perros y otra para gatos.
*/
// Tu resolución acá



/*
CONSIGNA 19
Dada una cola de enteros, construir una función que busque el número
más pequeño y lo mueva al frente de la cola, manteniendo el orden
relativo del resto de los elementos y sin utilizar otro tipo de
estructuras auxiliares.
*/
// Tu resolución acá



/*
CONSIGNA 20
Definir una estructura Vehiculo con patente y tarifa a abonar. Simular
una cabina de peaje: desencolar cada vehículo, acumular el monto
cobrado de la tarifa y mostrar la recaudación final de la jornada al
vaciar la cola.
*/
// Tu resolución acá



/*
=====================================================
NIVEL AVANZADO
=====================================================
*/

/*
CONSIGNA 21
Diseñar una función que reciba una cola y, utilizando una pila como
estructura auxiliar, invierta por completo el orden de sus elementos
(desencolando hacia la pila y desapilando hacia la cola).
*/
// Tu resolución acá



/*
CONSIGNA 22
Dada una cola de caracteres, determinar si la palabra o frase formada
es un palíndromo (capicúa) utilizando una pila auxiliar para comparar
los extremos.
*/
// Tu resolución acá



/*
CONSIGNA 23
Invertir el orden únicamente de la primera mitad de una cola con
cantidad par de elementos, dejando la segunda mitad en su orden
original, permitiendo el uso de una pila.
*/
// Tu resolución acá



/*
CONSIGNA 24
Dada una pila de enteros y un valor X, usar una cola auxiliar para
eliminar todas las ocurrencias de X de la pila, manteniendo intacto el
orden del resto de los elementos.
*/
// Tu resolución acá



/*
CONSIGNA 25
Dada una cola de números desordenados, utilizar una pila auxiliar para
lograr ordenarlos de menor a mayor pasando los elementos entre ambas
estructuras.
*/
// Tu resolución acá



/*
CONSIGNA 26
Resolver el "Sandwich Inverso": dada una cola, invertir solamente los
elementos que se encuentran entre el primer y el último número
negativo de la secuencia, dejando los elementos exteriores en su lugar
original.
*/
// Tu resolución acá



/*
CONSIGNA 27
Definir la estructura Paciente con DNI, nombre y prioridad (1: Alta,
2: Media, 3: Baja). Atender (desencolar) de manera prioritaria a todos
los de prioridad 1, utilizando colas auxiliares para retener a los
demás pacientes y luego encolarlos nuevamente.
*/
// Tu resolución acá



/*
CONSIGNA 28
Definir la estructura Pedido con ID, nombre del cliente y estado
(Completado o Pendiente). Procesar una cola de pedidos; si el estado
es "Pendiente", enviarlo a una pila de revisión manual, si es
"Completado" descartarlo, e informar cuántos pedidos fueron a
revisión.
*/
// Tu resolución acá



/*
CONSIGNA 29
Dada una cola de enteros que simula un flujo continuo de datos de un
sensor, implementar una función que almacene en una pila únicamente
los últimos 5 elementos leídos antes de que la cola se vacíe.
*/
// Tu resolución acá



/*
CONSIGNA 30
Simular el "Round Robin" de un procesador: definir la estructura
Proceso con ID y tiempo restante de ejecución. Encolar 5 procesos. En
cada ciclo de CPU, desencolar, restarle 10 unidades de tiempo y, si el
tiempo restante es mayor a cero, volver a encolarlo al final. Finalizar
y contar los ciclos totales cuando la cola quede vacía.
*/
// Tu resolución acá