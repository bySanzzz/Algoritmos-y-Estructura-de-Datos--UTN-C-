using namespace std;
# include <iostream>
int main (){
    int golesA, golesB;
    int ganadorA = 0, ganadorB = 0, empate=0;
    int i;
    for (i=1; i <= 5; i+=1){
        cout << "Partido" << i << endl;
        cout << "Goles A: ";
        cin >> golesA;
        cout << "Goles B: ";
        cin >> golesB;
        if (golesA == golesB) {
            empate = empate + 1;
        } else {
            if (golesA > golesB) {
                ganadorA = ganadorA + 1;
            } else {
            ganadorB = ganadorB + 1;
            }
    
        }
    }
    cout << "Ganador A: " << ganadorA << endl;
    cout << "Ganador B: " << ganadorB << endl;
    cout << "Empates: " << empate << endl;

    return 0;
}


