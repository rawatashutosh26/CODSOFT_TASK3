#include <iostream>

using namespace std;

char board[3][3]; 
char currentPlayer = 'X'; 


void Board() {
    int counter = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '0' + counter; 
            counter++;
        }
    }
}


void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') {
                cout << "\033[31m" << " " << board[i][j] << "\033[0m";
            } else if (board[i][j] == 'O') {
                cout << "\033[34m" << " " << board[i][j] << "\033[0m";
            } else if (board[i][j] >= '1' && board[i][j] <= '9') {
                cout << "\033[32m" << " " << board[i][j] << "\033[0m";
            }
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}


void Move() {
    int move;
    cout << "Player " << currentPlayer << ", Choose your move (1-9): ";
    cin >> move;

    if (move < 1 || move > 9) {
        cout << "Invalid move. Choose again.\n";
        Move();
        return;
    }

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Cell already taken. Choose again.\n";
        Move();
    } else {
        board[row][col] = currentPlayer;
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }

    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

bool Draw_check() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; 
            }
        }
    }
    return true;
}


void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}


void playGame() {
    Board(); 

    while (true) {
        displayBoard(); 
        Move(); 

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break; 
        } else if (Draw_check()) {
            displayBoard();
            cout << "The game is a draw!\n";
            break; 
        }

        switchPlayer(); 
    }
}

int main() {
    char playAgain;
    do {
        playGame(); 
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
