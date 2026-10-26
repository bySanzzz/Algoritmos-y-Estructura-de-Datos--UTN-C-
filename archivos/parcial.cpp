#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Catalogo{
    int id;
    string nombre;
    float precio;
    float totalRecaudado;
};

struct Transacciones{
    int idArma;
    char desgaste;  
}; 

int buscarSkin(Catalogo vecCatalogo[], int tamVec, int idArma){
    int indice = -1;
    for(int i = 0; i < tamVec; i++){
        if (vecCatalogo[i].id == idArma){
            indice = i;
            break;
        } 
    }
    return indice;
}

void mercado(Catalogo vecCatalogo[], int tamVec,char rutaArch[]){
    FILE *archTransaccion = fopen(rutaArch,"rb");
    if(archTransaccion == NULL){
        cout << "no se pudo abrir el archivo" << endl;
        return;
    }
    Transacciones rTransac;
    while(fread(&rTransac,sizeof(Transacciones),1,archTransaccion)){
        int Skinencontrada = buscarSkin(vecCatalogo,tamVec,rTransac.idArma);
        if (Skinencontrada != -1){
            if(rTransac.desgaste == 'F'){
                vecCatalogo[Skinencontrada].totalRecaudado += vecCatalogo[Skinencontrada].precio * 2.5;
            }else if(rTransac.desgaste == 'M'){
                vecCatalogo[Skinencontrada].totalRecaudado += vecCatalogo[Skinencontrada].precio;
            }else{
                vecCatalogo[Skinencontrada].totalRecaudado += vecCatalogo[Skinencontrada].precio * 0.5; 
            }
        }else{
            cout << "Transaccion huerfana" << endl;
        }
    }
    fclose(archTransaccion);
}

void mostrarRecaudacion(Catalogo vecCatalogo[], int tamVec){
    for(int i = 0; i < tamVec; i++){
        if(vecCatalogo[i].totalRecaudado > 0){
            cout << "Nombre: " << vecCatalogo[i].nombre << " - Total recaudado: $" << vecCatalogo[i].totalRecaudado << endl;
        }
    }
}
