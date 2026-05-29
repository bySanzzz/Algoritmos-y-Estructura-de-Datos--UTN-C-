#include <iostream>
using namespace std;

int main() {

    const int CANT = 144; 
    float temperatura[CANT];

    float maxima, minima, suma = 0;
    int posMinima = 0;

    // Carga de temperaturas
    for (int i = 0; i < CANT; i++) {

        cout << "Ingrese temperatura #" << i + 1 << ": ";
        cin >> temperatura[i];

        // Primera temperatura
        if (i == 0) {
            maxima = temperatura[i];
            minima = temperatura[i];
        }

        // Máxima
        if (temperatura[i] > maxima) {
            maxima = temperatura[i];
        }

        // Mínima
        if (temperatura[i] < minima) {
            minima = temperatura[i];
            posMinima = i;
        }

        // Suma para promedio
        suma += temperatura[i];
    }

    // Promedio
    float promedio = suma / CANT;

    // Conversión de posición a hora
    int minutosTotales = posMinima * 10;

    int hora = minutosTotales / 60;
    int minutos = minutosTotales % 60;

    // Resultados
    cout << "\n--- RESULTADOS ---\n";

    cout << "Temperatura maxima: " << maxima << endl;

    cout << "Temperatura minima: " << minima << endl;

    cout << "Ocurrio a las ";

    // Para mostrar 02:50 en vez de 2:50
    if (hora < 10)
        cout << "0";

    cout << hora << ":";

    if (minutos < 10)
        cout << "0";

    cout << minutos << endl;

    cout << "Temperatura promedio: " << promedio << endl;

    return 0;
}