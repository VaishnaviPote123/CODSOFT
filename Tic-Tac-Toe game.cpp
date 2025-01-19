#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
void displayBoard(const vector<vector<char> >& board);
bool isWinner(const vector<vector<char> >& board, char player);
bool isDraw(const vector<vector<char> >& board);
void resetBoard(vector<vector<char> >& board);
void displayWelcomeMessage();
void displayGoodbyeMessage();

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed random for fun extras
    vector<vector<char> > board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameOngoing = true;
    char playAgain;

    displayWelcomeMessage();

    do {
        resetBoard(board);
        gameOngoing = true;
        currentPlayer = (rand() % 2 == 0) ? 'X' : 'O'; // Randomize who starts

        cout << "The starting player is: " << currentPlayer << "\n\n";

        while (gameOngoing) {
            displayBoard(board);

            int row, col;
            cout << "Player " << currentPlayer << "'s turn.\n";
            cout << "Enter your move (row and column: 1-3): ";
            cin >> row >> col;

            // Validate input
            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                cout << "Invalid move. Try again.\n\n";
                continue;
            }

            // Update the board
            board[row - 1][col - 1] = currentPlayer;

            // Check for win or draw
            if (isWinner(board, currentPlayer)) {
                displayBoard(board);
                cout << "Congratulations! Player " << currentPlayer << " wins!\n\n";
                gameOngoing = false;
            } else if (isDraw(board)) {
                displayBoard(board);
                cout << "It's a draw! Well played both!\n\n";
                gameOngoing = false;
            } else {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        cout << endl;
    } while (playAgain == 'y' || playAgain == 'Y');

    displayGoodbyeMessage();
    return 0;
}

void displayWelcomeMessage() {
    cout << "**********************************************\n";
    cout << "        WELCOME TO THE TIC-TAC-TOE GAME!       \n";
    cout << "**********************************************\n\n";
    cout << "Rules:\n";
    cout << "1. The board is 3x3.\n";
    cout << "2. Players take turns to place their marker (X or O).\n";
    cout << "3. The first player to get 3 in a row wins.\n";
    cout << "4. If the board is full and no one wins, it's a draw.\n\n";
    cout << "Good luck and have fun!\n\n";
}

void displayGoodbyeMessage() {
    cout << "**********************************************\n";
    cout << "      THANK YOU FOR PLAYING TIC-TAC-TOE!      \n";
    cout << "**********************************************\n\n";
    cout << "We hope you had a great time. Come back soon!\n";
}

void displayBoard(const vector<vector<char> >& board) {
    cout << "\nCurrent Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << (board[i][j] == ' ' ? '_' : board[i][j]);
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << endl;
}

bool isWinner(const vector<vector<char> >& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool isDraw(const vector<vector<char> >& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void resetBoard(vector<vector<char> >& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

