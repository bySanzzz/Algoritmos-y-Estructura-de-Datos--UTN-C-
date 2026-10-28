#include <iostream>
using namespace std;

int main() {
    int Cant = 0;
    int repetidos = 0;
    int Dni, i;
    bool encont;
    struct Alumnos {
        int Dni;
        int repetidos;
    };

    Alumnos alumnos[100];


    // Inicializamos nuestro struct con sus variables

    for(i=0; i<100; i++){ 
        alumnos[i].Dni = 0;
        alumnos[i].repetidos = 0;
    }

    cout << "Ingrese el Dni del Alumno: ";
    cin >> Dni;
    while (Dni > 0)
    {
        Cant ++;
        i = 0;
        encont = false;

        while (!encont && i < Cant-1){ // Mientras la condicion no encuentre al numero y aun alla numeros por buscar en el struct seguira buscandolo
            if (Dni == alumnos[i].Dni){
                repetidos++;
                Cant--;
                alumnos[i].repetidos++;
                encont = true;
            }
            i++;
            }

        if (!encont){ // Si al final no encuentra coincidencia en el struct lo agrega
            alumnos[Cant-1].Dni = Dni;
        }

    cout << "Ingrese el Dni del Alumno: "; //Volvemos a ingresar otro Dni
    cin >> Dni;
    }

    for (i=0; i <Cant ; i++){ // Cout hasta la cantidad de posiciones que tengamos un valor, si tenemos 4 cantidad imprimimos hasta la pos 3
        if (alumnos[i].repetidos == 0){
    cout << "DNI: " << alumnos[i].Dni
         << " -> No se repite." << endl;
} else {
    cout << "DNI: " << alumnos[i].Dni
         << " -> Se repite " << alumnos[i].repetidos << " vez/veces." << endl;
}
    }
    cout << "La cantidad de veces que se intento ingresar un Dni repetidos fue de "<< repetidos;
    return 0;
}