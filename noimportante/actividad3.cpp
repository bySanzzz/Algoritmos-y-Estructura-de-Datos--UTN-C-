using namespace std;
# include <iostream>
int main (){
    int numero;
    int sumnumero = 0;
    int x;
    for (x=1; x <=10 ; x++){
        cout << "Suma N* " << x << endl;
        cout << "Ingrese numero para sumar: ";
        cin >> numero;
        sumnumero = sumnumero + numero;
    }
    cout << "La suma de todos los numeros dio: " << sumnumero << endl;

    return 0;
} 