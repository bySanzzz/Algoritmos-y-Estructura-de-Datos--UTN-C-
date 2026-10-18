#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    return 0;
}

struct Empleado{
    int legajo;
    float sueldo;
};

/*
binarios -> pueden usar estructuras -> 2 tipos (.bin y .dat)

"empleados.bin"
*/

void formaUno(char rutaArchEmpleados[]){
    //como abro un archivo
    /*
    FILE *archNombre = fopen(rutaArch,"modoApertura");

    rb: solo lectura, el archivo debe existir previamente
    wb: solo escritura, el archivo debe existir previamente 
    ab: lectura y escritura, si el archivo no existe, lo crea. Si existe, permite la escritura en la posición libre
    rb+: lectura y escritura, sobreescritura -> el archivo debe existir previamente.
    wb+: lectura y escritura, sobreescritura -> si el archivo no existe, lo crea. Si existe, pisa el archivo anterior.
    */
    FILE *archEmpleado = fopen(rutaArchEmpleados,"rb+");

    //verificar que ese archivo se haya podido abrir
    if(archEmpleado == NULL){
        //el archivo no se pudo abrir
        cout << "no se pudo abrir el archivo" << endl;
        return;
    }

    //como leo un archivo
    //Necesito una variable para guardar los datos que voy leyendo, la misma tiene el mismo td del archivo
    Empleado rEmp;
    //fread(&varible,cuantoMide[sizeof(Estructura)],cuantosRegLeo,archNombre); -> 1 si pudo leer algo, 0 si no.
    fread(&rEmp, sizeof(Empleado),1,archEmpleado);
    cout << rEmp.legajo << rEmp.sueldo << endl;
    
    //leer secuencialmente un archivo
    
    while(fread(&rEmp, sizeof(Empleado),1,archEmpleado)){
        cout << rEmp.legajo << rEmp.sueldo << endl;
    }
    
    //formaDos de leer
    fread(&rEmp, sizeof(Empleado),1,archEmpleado);
    while(!feof(archEmpleado)){
        cout << rEmp.legajo << rEmp.sueldo << endl;
        fread(&rEmp, sizeof(Empleado),1,archEmpleado);
    }
    
    //escribir en un archivo
    
    Empleado buffer;
    buffer.legajo = 83948;
    buffer.sueldo = 200000;
    //fwrite(&varible,cuantoMide[sizeof(Estructura)],cuantosRegEscribo,archNombre);
    fwrite(&buffer, sizeof(Empleado),1,archEmpleado);
    
    Empleado vecEmpleado[50000];
    int tamVecEmpleado = 50000;
    fwrite(vecEmpleado, sizeof(Empleado),tamVecEmpleado,archEmpleado);


    //fseek(archNombre,cuantoMeMuevo[n * sizeof(Estructura)],desdeDonde)
    /*
    SEEK_SET: desde el inicio del archivo
    SEEK_END: desde el final del archivo
    SEEK_CUR: desde la posición actual del archivo
    */

    //modifcar el sueldo del empleado con legajo 5000, sumarle 100000 al sueldo

    Empleado regEmpleado;
    while(fread(&regEmpleado,sizeof(Empleado),1,archEmpleado)){
        if(regEmpleado.legajo == 5000){
            fseek(archEmpleado,-1 * sizeof(Empleado),SEEK_CUR);
            regEmpleado.sueldo + 100000;
            fwrite(&regEmpleado,sizeof(Empleado),1,archEmpleado);
        }
    }

    fclose(archEmpleado);
}

typedef char str50[51];

struct Alumno{
    int legajo;
    str50 nombre;
    float promedio;
    bool activo;
};


void funcion(){
    Alumno data;
    //strcpy(vecDestino,cadOrigen);
    strcpy(data.nombre,"Santiago");
    
    //strcmp(cadUno,cadDos); -> [izq: -1, centro: 0, der: 1];
    //strcmp(Santiago,Santiago); -> 0 
}
/*Alta de Registros: Crear una función agregarAlumno que permita ingresar los datos de un alumno y lo guarde en el archivo alumnos.dat. */

void agregarAlumnos(char rutaArchAlumnos[]){
    FILE *archAlumnos = fopen(rutaArchAlumnos,"ab");
    if(archAlumnos == NULL){
        return;
    }

    Alumno data;
    cout << "Ingrese nombre: "; cin > data.nombre;
    cout << "Ingrese legajo: "; cin > datos.legajo;
    cout << "Ingrese promedio: "; cin > datos.promedio;

    fwrite(&datos,sizeof(Alumno),1,archAlumnos);

    fclose(archAlumnos);
}

/*Realizar una función listarAlumnos que lea el archivo alumnos.dat registro por registro y muestre los datos de todos los alumnos. */
void listarALumnos(char rutaArchAlumnos[]){
    FILE *archAlumnos = fopen(rutaArchAlumnos,"rb");
    if(archAlumnos == NULL){
        return;
    }
    Alumno data;
    while(fread(&data,sizeof(Alumno),1,archAlumnos)){
        cout << "Nombre: " << data.nombre;
        cout << "legajo: "<< data.legajo;
        cout << "Promedio: " << data.promedio;
    }
    fclose(archAlumnos);
}