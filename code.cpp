#include <iostream>
#include <vector>

using namespace std;


void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------" << endl;
        }
    }
}


bool isGameOver(const vector<vector<char>>& board, char player) {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; 
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; 
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; 
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; 
    }


    bool draw = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                draw = false;
                break;
            }
        }
    }
    return draw;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); 
    char currentPlayer = 'X'; 
    int row, col;
cout<<endl;
    cout << "  Welcome to Tic-Tac-Toe!" << endl;

    while (true) {
        cout << endl<<" Current board:" << endl<<endl;;
        printBoard(board);

        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

       
        board[row - 1][col - 1] = currentPlayer;

        
        if (isGameOver(board, currentPlayer)) {
            cout << "Current board:" << endl;
            printBoard(board);
            if (isGameOver(board, 'X')) {
                cout << "Player X wins!" << endl;
            } else if (isGameOver(board, 'O')) {
                cout << "Player O wins!" << endl;
            } else {
                cout << "It's a draw!" << endl;
            }
            break;
        }

        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}