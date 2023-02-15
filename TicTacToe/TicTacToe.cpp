// TicTacToeEDAII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib> 
#include <string>
using namespace std;

char tablero[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
bool turno = true;

bool ValidarNumero(string str)// metodo para comprobar si el dato introducido es entero
{
    int i = 0;
    while (str[i] != '\0') //'\0' es el character que marca el final del string
    {
        if (isdigit(str[i]) == false) // compara cada caracter de la cadena para saber si es numerico
        {
            return false;
        }
        i++;
    }
    return true;
}

void DesplegarTablero() {

    for (int i = 0; i < 3; i++) {
        cout << "  ";
        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j];
            if (j < 2) cout << "  |  ";
        }
        cout << endl;
        if (i < 2) {
            cout << "-----+-----+-----" << endl;
        }
    }
}

bool JuegoBloqueado() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] != 'O' && tablero[i][j] != 'X') {
                return false;
            }
        }
    }
    return true;
}

bool GameOver(char playerChar) {
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == playerChar && tablero[i][1] == playerChar && tablero[i][2] == playerChar) {
            return true;
        }
        else if (tablero[0][i] == playerChar && tablero[1][i] == playerChar && tablero[2][i] == playerChar) {
            return true;
        }
    }

    if (tablero[0][0] == playerChar && tablero[1][1] == playerChar && tablero[2][2] == playerChar) {
        return true;
    }
    else if (tablero[0][2] == playerChar && tablero[1][1] == playerChar && tablero[2][0] == playerChar) {
        return true;
    }

    return false;
}

bool Jugada(char playerChar, int position) {
    int counter = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (counter == position) {
                if (tablero[i][j] == 'O' || tablero[i][j] == 'X') {
                    return false;
                }
                tablero[i][j] = playerChar;
            }
            counter++;
        }
    }
    return true;
}

int main()
{
    char jugadorChar = 'O';
    string jugador1_Name, jugador2_Name, currJugador, position, seleccionXO;

    cout << "Bienvenido al juego Tic Tac Toe!" << endl;
    cout << "Inserte el nombre del jugador 1: ";
    cin >> jugador1_Name;

    cout << "Inserte el nombre del jugador 2: ";
    cin >> jugador2_Name;

    currJugador = jugador1_Name;

    while (true) {
        cout << "Seleccione el caracter que utilizara el jugador 1\n(1) \"O\"\n(2) \"X\"\n>>";
        cin >> seleccionXO;

        if (!ValidarNumero(seleccionXO)) {
            cout << "Opcion invalida, inserte 1 para O y 2 para X" << endl;
            continue;
        }
        else if (stoi(seleccionXO) < 1 || stoi(seleccionXO) > 2)  {
            cout << "Opcion fuera de rango, intente de nuevo" << endl;
            continue;
        }
        break;
    }

    if (seleccionXO == "1") jugadorChar = 'O';
    else jugadorChar = 'X';


    while (true) {
        system("CLS");
        DesplegarTablero();

        cout << "Turno de " << currJugador << "(" << jugadorChar << "): ";
        cin >> position;

        if (ValidarNumero(position) == false) {
            cout << "Posicion invalida, solo se permiten numeros, intente de nuevo" << endl;
            system("PAUSE");

            continue;
        }
        else if (stoi(position) > 9) {
            cout << "Posicion invalida, solo se permiten numeros del 1 al 9, intente de nuevo" << endl;
            system("PAUSE");

            continue;
        }

        bool jugadaValida = Jugada(jugadorChar, stoi(position));
        if (!jugadaValida) {
            cout << "Posicion ya ocupada (jugada invalida)" << endl;
            system("PAUSE");
            continue;
        }

        if (GameOver(jugadorChar)) {
            system("CLS");

            DesplegarTablero();
            cout << currJugador << " es el ganador!" << endl;
            break;
        }

        if (JuegoBloqueado()) {
            system("CLS");

            DesplegarTablero();

            cout << "El juego es un empate (no mas jugadas validas)" << endl;
            break;
        }

        if (jugadorChar == 'O') jugadorChar = 'X';
        else jugadorChar = 'O';

        if (currJugador == jugador1_Name) currJugador = jugador2_Name;
        else currJugador = jugador1_Name;

    }

}


