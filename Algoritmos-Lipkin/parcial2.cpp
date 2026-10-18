#include <iostream>
using namespace std;
#define MAX_ELEMENTOS_PILOTOS 500;
#define MAX_ELEMENTOS_BITACORA 5000;

struct Pilotos
{
    int legajo;
    string NombreyApellido;
    string RangoActual;
};

struct Bitacora
{   
    int legajoPiloto;
    string CodigoDeNave;
    float Horas;
};

void procesarBitacora(Bitacora vecBitacora[],int tamVecBitacora, Pilotos vecPilotos[],int tamVecPilotos ){
    int sumHoras = 0;
    for (int j = 0; j < tamVecPilotos; j++){
        for(int i = 0; i < tamVecBitacora; i++){
            if (vecBitacora[i].legajoPiloto == vecPilotos[j].legajo){
                sumHoras = sumHoras + vecBitacora[i].Horas;
                
                }
            if (sumHoras > 50)
                vecPilotos[j].RangoActual = "Capitan";
            }
        cout << "La cantidad de Horas del aviador"<< vecPilotos[j].legajo <<" fueron de: <<" << sumHoras;     
        }
    }
void mayorPilotoAeronave(Bitacora vecBitacora[],int tamVecBitacora, Pilotos vecPilotos[],int tamVecPilotos ){
    float sumPilotoMayor = 0;
    int pilotoMayor = -1;
    for (int j = 0; j < tamVecPilotos; j++){
        int sumPiloto = 0;
        for(int i = 0; i < tamVecBitacora; i++){
            if (vecBitacora[i].legajoPiloto == vecPilotos[j].legajo && vecBitacora[i].CodigoDeNave == "A320"){
                sumPiloto = sumPiloto + vecBitacora[i].Horas;    
            }
        }
        if (sumPiloto > sumPilotoMayor){
            sumPilotoMayor = sumPiloto;
            pilotoMayor = j;
        }
    }
}


int main(){
    Pilotos vecPilotos[MAX_ELEMENTOS_PILOTOS];
    Bitacora vecBitacora[MAX_ELEMENTOS_BITACORA];
    int tamPilotos = 0;
    int tamBitacora = 0;

    // 1) Cargar los vectores
    tamPilotos = cargarPilotos(vecPilotos);
    tamBitacora = cargarVuelos(vecBitacora);

    // 2) Listado de horas y actualización de rangos
    procesarBitacora(vecPilotos, tamPilotos, vecBitacora, tamBitacora);

    // 3) Piloto con más horas en A320 (después del punto anterior)
    pilotoMasHorasA320(vecPilotos, tamPilotos, vecBitacora, tamBitacora);

    return 0;
}