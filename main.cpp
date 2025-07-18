#include <iostream>
#include <sstream>

using namespace std;

bool finished = false;
//true -> player 1
//false -> player 2
bool playerTurn = true;
int board[3][3];

void printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int ii = 0; ii < 3; ii++) {
            if (board[i][ii] == 0) {
                cout << "[ ]";
            }
            else {
                if (board[i][ii] == 1) {
                    cout << "[X]";
                }
                else {
                    cout << "[O]";
                }
            }
        }
        cout << "\n";
    }
}

bool markSpot(int row, int col) {
    if ((row >= 3 || col >=3) || (row < 0 || col < 0)) {
        return false;
    }
    if (board[row][col] == 0) {
        if (playerTurn) {
            board[row][col] = 1;
        }
        else {
            board[row][col] = 2;
        }
        return true;
    }
    return false;
}

bool checkBoard() {
    int mark;
    playerTurn ? mark = 1 : mark = 2;
    for (int r = 0; r < 3; r++) {
        if (board[r][0] == mark && board[r][1] == mark && board[r][2] == mark) {
            return true;
        }
    }
    for (int c = 0; c < 3; c++) {
        if (board[0][c] == mark && board[1][c] == mark && board[2][c] == mark) {
            return true;
        }
    }
    if (board[0][0] == mark && board[1][1] == mark && board [2][2] == mark) {
        return true;
    }
    if (board[0][2] == mark && board[1][1] == mark && board [2][0] == mark) {
        return true;
    }
    return false;
}

int getIntegerInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        string line;
        getline(cin, line);

        stringstream ss(line);
        if (ss >> value && ss.eof()) {
            return value;
        } else {
            cout << "Invalid input. Please enter an integer.\n";
        }
    }
}

int main() {
    cout << "TIC TAC TOE!\n";
    cout << "\n";
    while (!finished) {
        if (playerTurn) {
            printBoard();
            cout << "Player 1 turn";
            cout << "\n";
            cout << "Make your selection (Row then Column starting at 0 and going to 2)\n";

            int row = getIntegerInput("Enter row (0-2): ");
            int column = getIntegerInput("Enter column (0-2): ");


            if (!markSpot(row, column)) {
                cout << "Invalid selection, please select an empty space in the range of the board \n";
            }
            else {
                if (checkBoard()) {
                    finished = true;
                }
                else {
                    playerTurn = !playerTurn;
                }
            }
        }
        else {
            printBoard();
            cout << "Player 2 turn";
            cout << "\n";
            cout << "Make your selection (Row then Column starting at 0 and going to 2)\n";

            int row = getIntegerInput("Enter row (0-2): ");
            int column = getIntegerInput("Enter column (0-2): ");

            if (!markSpot(row, column)) {
                cout << "Invalid selection, please select an empty space in the range of the board \n";
            }
            else {
                if (checkBoard()) {
                    finished = true;
                }
                else {
                    playerTurn = !playerTurn;
                }
            }
        }
    }
    playerTurn ? cout << "Player 1 wins" : cout << "Player 2 wins";

}

