#include <iostream>

const int SIZE = 3;
char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

// Function prototypes
void printBoard();
bool placeMark(int row, int col, char mark);
bool checkWin(char mark);
bool checkDraw();
void playGame();

int main() {
    playGame();
    return 0;
}

void printBoard() {
    std::cout << "  1 2 3\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

bool placeMark(int row, int col, char mark) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
        board[row][col] = mark;
        return true;
    }
    return false;
}

bool checkWin(char mark) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) || 
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void playGame() {
    int row, col;
    char currentPlayer = 'X';
    bool validMove;

    std::cout << "Tic-Tac-Toe Game!" << std::endl;

    while (true) {
        printBoard();
        std::cout << "Player " << currentPlayer << "'s turn. Enter row and column (1-3): ";
        std::cin >> row >> col;
        --row; --col; // Adjust for zero-based indexing

        validMove = placeMark(row, col, currentPlayer);

        if (validMove) {
            if (checkWin(currentPlayer)) {
                printBoard();
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                break;
            }
            if (checkDraw()) {
                printBoard();
                std::cout << "The game is a draw!" << std::endl;
                break;
            }
            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }
}
