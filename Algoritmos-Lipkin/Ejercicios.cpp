#include <iostream> //entrada y salida de datos
using namespace std;
const int MAX_ELEMENTOS = 100;


//prototipo, firma
int sumaValores(int, int);
int sumaValores(int valA, int valB){
    return valA + valB;
}

int restaValores(int valA, int valB){
    return valA - valB;
}

void calculadora(){
    int a, b;
    cout << "Ingrese valor: "; cin >> a;
    cout << "Ingrese valor: "; cin >> b;

    int resultado = sumaValores(a,b);
    cout << "la suma es: " << resultado;
    resultado = restaValores(a,b);
    cout << "la resta es: " << resultado;
}

/*

struct Nombre{
    tipoDato nombreVariable;
};
*/

struct Persona{
    string nombre;
    int edad;
    int dni;
};

void funcion(){
    Persona info;
    info.nombre = "Santiago";
    info.edad = 20;
    info.dni = 89328493;

    Persona vecPersonas[MAX_ELEMENTOS];
    int tamVecPersonas = 0;

    for(int i = 0; i < MAX_ELEMENTOS;i++){
        cout << "Ingrese nombre: "; cin >> vecPersonas[tamVecPersonas].nombre;
        cout << "Ingrese edad: "; cin >> vecPersonas[tamVecPersonas].edad;
        cout << "Ingrese dni: "; cin >> vecPersonas[tamVecPersonas].dni;
        //siempre que agrego un dato, debo aumentar el tamaño del vector.
        tamVecPersonas++;
    }
    
    for(int i = 0; i < tamVecPersonas; i++){
        cout << "Nombre: " <<  vecPersonas[i].nombre << endl;
        cout << "Edad: " <<  vecPersonas[i].edad << endl;
        cout << "dni: " <<  vecPersonas[i].dni << endl;
    }
}

/* Definir la estructura Libro con los campos: título, sueldo y cantidad de páginas. Desarrollar una función para cargar un vector de 10 Empleado y otra para mostrarlos por pantalla. 

1)  Que hay que hacer? Tengo que mostrar los elementos de un vector por pantalla
2)  Que herramientas tengo para resolver el problema? tengo un vector de 10 elementos, el vector tiene la estructura libro
3)  Que herramientas no tengo pero necesito para resolver el problema? yo tengo que cargar el vector, tengo que crear la estructura.

a) que tipo de dato es la función? la respuesta la sacamos con el punto 1. 
b) defino los parámetros: la respuesta la sacamos del punto 2 y 3.
*/

struct Libro{
    string Empleado;
    string sueldo;
    int cantPaginas;
};

void cargarVector(){
    Libro vecEmpleado[MAX_ELEMENTOS];
    int tamVecEmpleado = 0;

    for(int i = 0; i < 10; i++){
        cout << "Ingrese Empleado: "; cin >> vecEmpleado[tamVecEmpleado].Empleado;
        cout << "Ingrese sueldo: "; cin >> vecEmpleado[tamVecEmpleado].sueldo;
        cout << "Ingrese cantPaginas: "; cin >> vecEmpleado[tamVecEmpleado].cantPaginas;
        tamVecEmpleado++;
    }
}

void mostrarVector(Libro vecLibro[], int tamVecEmpleado){
    for(int i = 0; i < tamVecEmpleado; i++){
        cout << "Empleado: " << vecLibro[i].Empleado;
        cout << "sueldo: " << vecLibro[i].sueldo;
        cout << "cantPaginas: " << vecLibro[i].cantPaginas;
    }
}

/*Crear la estructura Persona con los campos: nombre y edad. Leer un vector de 15 personas y crear una función que cuente y retorne cuántas de ellas son mayores de 18 años. */

struct Personas{
    string nombre;
    int edad;
};

int contarMayores(Personas vecPersonas[], int tamVecPersonas){
    int contadorMayores = 0;
    for (int i = 0; i < tamVecPersonas; i++){
        if(vecPersonas[i].edad >= 18){
            contadorMayores++;
        }
    }
    return contadorMayores;
}

/*Definir la estructura Producto que contenga código, precio y stock. Cargar un arreglo de 20 productos e implementar una función que calcule el valor total del inventario general (precio x stock de todos los artículos).*/
//-------------------------------//


//Definir la estructura Empleado con legajo y sueldo. Cargar 10 empleados en un vector y 
//desarrollar una función que incremente el sueldo de todos en un 10%, mostrando el vector actualizado. //

//Que hay que hacer? Crear Struct empleados con legajo y sueldo
//Que herramientas tengo para resolver el problema?  un vector de 10 empleados
//Que herramientas no tengo pero necesito para resolver el problema?// Funcion 10% 

const int MAX_ELEMENTOS = 100;

    struct Empleado
    {
        int legajo;
        int sueldo;
    };

void cargarVector(){
    Empleado vecEmpleado[MAX_ELEMENTOS];
    int tamVecEmpleado = 0;

    for(int i = 0; i < 10; i++){
        cout << "Ingrese legajo: "; cin >> vecEmpleado[tamVecEmpleado].legajo;
        cout << "Ingrese sueldo: "; cin >> vecEmpleado[tamVecEmpleado].sueldo;
        tamVecEmpleado++;
    }
}



void aumentoVector(Empleado vecEmpleado[], int tamVecEmpleado){
    for(int i = 0; i < tamVecEmpleado; i++){
       vecEmpleado[i].sueldo *= 1.10;
    }
}

void mostrarVector(Empleado vecEmpleado[], int tamVecEmpleado){
    aumentoVector(vecEmpleado,tamVecEmpleado);
    for(int i = 0; i < tamVecEmpleado; i++){
        cout << "Empleado: " << vecEmpleado[i].legajo;
        cout << "sueldo: " << vecEmpleado[i].sueldo;
    }
}

//Crear la estructura Mascota con nombre, especie ("Perro", "Gato", etc.) y edad. Cargar un
//arreglo de 20 mascotas y construir una función que cuente cuántos perros y cuántos gatos//
//hay en el vector.//
const int MAX_DATOS = 100;
struct Mascotas
{
    string nombre;
    string especie;
    int edad;
};

void cargarMascotas(){
    Mascotas vecMascotas[MAX_DATOS];
    int tamVecMascotas = 0;

    for(int i = 0; i < 20; i++){
        cout << "Ingrese nombre: "; cin >> vecMascotas[tamVecMascotas].nombre;
        cout << "Ingrese especie: "; cin >> vecMascotas[tamVecMascotas].especie;
        cout << "Ingrese edad: "; cin >> vecMascotas[tamVecMascotas].edad;
        tamVecMascotas++;
    }
}
int contadorPerros = 0;
int contadorGatos = 0;
int contadorMascotas(Mascotas vecMascotas[], int tamVecMascotas){
    for(int i = 0; i < 20; i++){
        if(vecMascotas[i].especie == "Perro"){
            contadorPerros++;
            return;
        }
        if(vecMascotas[i].especie == "Gato"){
            contadorGatos++;
            return;
        }
    }
}
