#include <iostream>
#define FILAS 35
#define COLUMNAS 21
using namespace std;

struct Inscripto{
    string nombre;
    string apellido;
    int legajo;
};

struct InscriptoFinal{
    Inscripto info; // Añade la informacion de Inscriptos a un nuevo struct para no repetir los datos
    float asistencia;
    bool rinde;
};



int main (){
    return 0;   
}

/*
a) tipoRetorno -> que hay que hacer?
b) parámetros -> las herramientas que tenés y que no tenés 

*/

int asistencia(int matAsistencias[][COLUMNAS], int legajo){ //Funcion que contabiliza las asistencias de un Legajo
    int asistenciaAlumno = 0;
    for(int i = 0; i < FILAS; i++){
        if (matAsistencias[i][0] == legajo){
            for(int j = 0; j < COLUMNAS; j++){
                if (matAsistencias[i][j] == 1)
                    asistenciaAlumno++;
            }
            break;
        }    
    }
    return asistenciaAlumno;
}


void rinde(int matAsistencias[][COLUMNAS], InscriptoFinal vec[], int &tamVec){//matrix y y un vector vacio con los datos del struct
    tamVec = 0;
    for(int i = 0; i< FILAS; i++){
        vec[tamVec].info.legajo = matAsistencias[i][0]; //Agarra el Legajo de la matrix asistencias para posteriori copiarlo en el campo de la tabla Inscriptos final columna legajo
        int cantAsistencias = asistencia(matAsistencias,matAsistencias[i][0]);// matriz y legajo, Cant de asistencias del estudiante
        vec[tamVec].asistencia = (cantAsistencias / 20) * 100;
        if(vec[tamVec].asistencia > 75){
            vec[tamVec].rinde = true;
        }else{
            vec[tamVec].rinde = false;
        }
        tamVec++;
    }

}



void ordenarLista(Inscripto vec[], int tamVec){
   Inscripto aux;//guarda lo mismo que los datos que se va a comparar por eso tiene el mismo Struct
   for(int i = 0; i < tamVec - 1; i++){
        for(int j = 0; j < tamVec - 1 - i; j++){
            if(vec[j].apellido != vec[j+1].apellido){
                if(vec[j].apellido < vec[j+1].apellido){
                    aux = vec[j];
                    vec[j] = vec[j+1];
                    vec[j+1] = aux;
                }
            }
            if(vec[j].apellido == vec[j+1].apellido){
                if(vec[j].nombre < vec[j+1].nombre){
                    aux = vec[j];
                    vec[j] = vec[j+1];
                    vec[j+1] = aux;
                }
        }
    }
}
}

