#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[9]; // Character array to represent the board

public:
    TicTacToe() {
        // Initialize the board with empty spaces
        for (int i = 0; i < 9; ++i) {
            board[i] = ' ';
        }
    }

    void printBoard() {
        // Print the current state of the board
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
        cout << "---+---+---" << endl;
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
        cout << "---+---+---" << endl;
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
    }

    bool isMoveValid(int position) {
        // Check if the move is valid (position within range and the square is empty)
        return (position >= 0 && position < 9 && board[position] == ' ');
    }

    bool checkWin(char symbol) {
        // Check all possible winning combinations
        return (
            (board[0] == symbol && board[1] == symbol && board[2] == symbol) ||
            (board[3] == symbol && board[4] == symbol && board[5] == symbol) ||
            (board[6] == symbol && board[7] == symbol && board[8] == symbol) ||
            (board[0] == symbol && board[3] == symbol && board[6] == symbol) ||
            (board[1] == symbol && board[4] == symbol && board[7] == symbol) ||
            (board[2] == symbol && board[5] == symbol && board[8] == symbol) ||
            (board[0] == symbol && board[4] == symbol && board[8] == symbol) ||
            (board[2] == symbol && board[4] == symbol && board[6] == symbol)
        );
    }

    bool isBoardFull() {
        // Check if the board is full (no empty squares left)
        for (int i = 0; i < 9; ++i) {
            if (board[i] == ' ') {
                return false;
            }
        }
        return true;
    }

    void play() {
        int player = 1; // Player 1 starts with 'X'
        int position;
        bool gameover = false;

        while (!gameover) {
            // Print the board
            cout << endl << "Current board:" << endl;
            printBoard();

            // Determine current player's symbol
            char symbol = (player == 1) ? 'X' : 'O';

            // Ask for player's move
            cout << "Player " << player << ", enter your move (1-9): ";
            cin >> position;
            position--; // Convert to zero-indexed position

            // Validate the move
            if (!isMoveValid(position)) {
                cout << "Invalid move! Try again." << endl;
                continue;
            }

            // Make the move
            board[position] = symbol;

            // Check if the game is won
            if (checkWin(symbol)) {
                cout << endl << "Congratulations! Player " << player << " wins!" << endl;
                gameover = true;
            }
            // Check if the game is a draw
            else if (isBoardFull()) {
                cout << endl << "It's a draw!" << endl;
                gameover = true;
            }

            // Switch to the other player
            player = (player == 1) ? 2 : 1;
        }

        // Print the final board
        cout << endl << "Final board:" << endl;
        printBoard();
    }
};

int main() {
    TicTacToe game;
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    game.play();
    return 0;
}
