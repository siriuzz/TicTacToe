// TicTacToeEDAII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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
            if (tablero[i][j] != '0' && tablero[i][j] != 'X') {
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
    char playerChar = 'O';
    int position;
    cout << "Bienvenido al juego Tic Tac Toe!" << endl;

    while (true) {
        DesplegarTablero();

        cin >> position;

        Jugada(playerChar, position);


        if (GameOver(playerChar)) {
            DesplegarTablero();
            cout << "El jugador de las " << playerChar << " es el ganador!" << endl;
            break;
        }

        if (JuegoBloqueado()) {
            DesplegarTablero();

            cout << "El juego es un empate (no mas jugadas validas)" << endl;
            break;
        }

        if (playerChar == 'O') playerChar = 'X';
        else if (playerChar == 'X') playerChar = 'O';


    }

}

