using namespace std;
# include <iostream>
int main (){
    int nota,menor = 11, mayor = 0;
    int cant_my,cant_mn;
    int Cant_notas;
    float promedio;
    int Apro = 0, Desa = 0;
    int total_notas = 0, i = 0;
    cout << "Ingrese cantidad de notas: ";
    cin >> Cant_notas; 
    while (Cant_notas > i) {
        cout << "Introduzca nota del parcial en un rango de 1 a 10: ";
        cin >> nota; 
        //Contador de Numero mayor
         if (nota > mayor) {
            mayor = nota;
            cant_my = 1;
        } else {
            if (nota == mayor) {
                cant_my+=1;
            }
        }
        //Contador de Numero menor
        if (nota < menor) {
            menor = nota;
            cant_mn = 1;
        } else {
            if (nota == menor) {
                cant_mn+=1;
            }
        }

        //Promedio
        total_notas = total_notas + nota;

        //Contador de notas
        if (nota >= 6){
            Apro+=1;
        }else {
            Desa+=1;
        }
        i +=1;
   
    }
    promedio = (float) total_notas / Cant_notas;
    if (Cant_notas == 0) {
        cout << "No se ingresaron notas";
    } else {
        cout << "Aprobaron en total: " << Apro << "\n";
        cout << "Desaprobaron en total: " << Desa << "\n";
        cout << "El promedio final del curso es de: " << promedio << "\n";
        cout << "La mejor nota fue de: " << mayor << " y se repitio: " << cant_my << "\n";
        cout << "La peor nota fue de: " << menor << " y se repitio: " << cant_mn << "\n";
    }
    return 0;
}