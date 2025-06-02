#include <iostream>
using namespace std;

char board[3][3] = {{'R','R','R'},
                    {'R','R','R'},
                    {'R','R','R'}};

char current_marker;
int current_player;

void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "-----------\n";
    }
    cout << "\n";
}

bool placeMarker(int row, int col) {
    if (board[row][col] == 'R') {
        board[row][col] = current_marker;
        return true;
    }
    return false;
}

bool checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

void switchPlayer() {
    if (current_marker == 'X') {
        current_marker = 'O';
        current_player = 2;
    } else {
        current_marker = 'X';
        current_player = 1;
    }
}

void game() {
    cout << "TIC TAC TOE GAME\n";
    cout << "Player 1, choose your marker (X or O): ";
    char marker;
    cin >> marker;

    current_player = 1;
    current_marker = marker;

    drawBoard();

    int winner = 0;
    for (int i = 0; i < 9; i++) {
        cout << "Player " << current_player << ", enter row and column (0-2 0-2): ";
        int row, col;
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Invalid position. Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(row, col)) {
            cout << "Cell already taken. Try again.\n";
            i--;
            continue;
        }

        drawBoard();

        if (checkWinner()) {
            winner = current_player;
            break;
        }

        switchPlayer();
    }

    if (winner != 0)
        cout << "Player " << winner << " wins!\n";
    else
        cout << "It's a draw!\n";
}

int main() {
    game();
    return 0;
}


