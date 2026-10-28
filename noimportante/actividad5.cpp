#include <iostream>
using namespace std;

int main() {
    int nro[27];
    int i;
    int mayor = 1,cant = 0;
    int goles;
    for (i=1; i <=26 ; i++){
        nro [i]=0;
    }
    
    cout << "Que camiseta tiene el jugador? : ";
    cin >> i;
    cout << "Cuantos goles metio ese jugador? : ";
    cin >> goles;
    while (goles > 0 && i > 0 && i-1<=26)
    {
        nro[i] = goles;
        cout << "Que camiseta tiene el jugador? : ";
        cin >> i;
        cout << "Cuantos goles metio ese jugador? : ";
        cin >> goles;
    }
    cout << "\n========================================\n";
    cout << "      RESUMEN DE GOLES DEL EQUIPO\n";
    cout << "========================================\n\n";

    for (i=1; i <=26 ; i++){
        if (nro[i] > nro[mayor]){
            mayor = i;
        } 
        if (nro[i] > 0){
            cout << "El nro " <<i<< " metio: "<< nro[i] <<" goles"<< endl;
            cant= cant + 1;
        } 
    }
    cout << "\n========================================\n";
    cout << "         RESULTADOS FINALES\n";
    cout << "========================================\n\n";

    cout << "El goleador del equipo fue en Nro: " << mayor << endl;
    cout << "Hubo en total : " << cant << " jugadores que metieron gol"<< endl;
    cout << "\n========================================\n";
    cout << "========================================\n\n";
    return 0;
}