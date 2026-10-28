#include <iostream>

int main() {
    int golesPrimerP1, golesSegundoP1;
    int golesPrimerP2, golesSegundoP2;
    int resultado1, resultado2;

    std::cout << "Ingrese los goles del Equipo1 en la Ida: ";
    std::cin >> golesPrimerP1;

    std::cout << "Goles en la vuelta: ";
    std::cin >> golesSegundoP1;

    std::cout << "Ingrese los goles del Equipo2 en la Ida: ";
    std::cin >> golesPrimerP2;

    std::cout << "Goles en la vuelta: ";
    std::cin >> golesSegundoP2;

    resultado1 = golesPrimerP1 + golesSegundoP1;
    resultado2 = golesPrimerP2 + golesSegundoP2;

    if (resultado1 == resultado2) {
    std::cout << "Penales";
        } else {
            if (resultado1 > resultado2) {
                std::cout << "Gana equipo1";
            } else {
            std::cout << "Gana equipo2";
            }
}


    return 0;
}