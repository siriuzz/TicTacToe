// TicTacToeEDAII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib> 
using namespace std;

char tablero[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
bool turno = true;

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

void Jugada(char playerChar, int position) {
    int counter = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (counter == position) {
                tablero[i][j] = playerChar;
                return;

            }
            counter++;
        }
    }
}

int main()
{
    char jugadorChar = 'O';
    int position;
    string jugador1_Name, jugador2_Name, currJugador;

    cout << "Bienvenido al juego Tic Tac Toe!" << endl;
    cout << "Inserte el nombre del jugador 1: ";
    cin >> jugador1_Name;

    cout << "Inserte el nombre del jugador 2: ";
    cin >> jugador2_Name;

    currJugador = jugador1_Name;

    system("CLS");

    while (true) {
        DesplegarTablero();


        cout << "Turno de " << currJugador << "(" << jugadorChar << "): ";
        cin >> position;

        Jugada(jugadorChar, position);

        if (GameOver(jugadorChar)) {
            DesplegarTablero();
            cout << "El jugador de las " << jugadorChar << " es el ganador!" << endl;
            break;
        }

        if (JuegoBloqueado()) {
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


