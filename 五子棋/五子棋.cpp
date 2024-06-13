#include <iostream>
#include <vector>

const int BOARD_SIZE = 15;
const char EMPTY = '-';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

std::vector<std::vector<char>> board(BOARD_SIZE, std::vector<char>(BOARD_SIZE, EMPTY));

bool isFull() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

bool hasWon(char player) {
    // 检查行
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j <= BOARD_SIZE - 5; ++j) {
            bool win = true;
            for (int k = 0; k < 5; ++k) {
                if (board[i][j + k] != player) {
                    win = false;
                    break;
                }
            }
            if (win) {
                return true;
            }
        }
    }

    // 检查列
    for (int j = 0; j < BOARD_SIZE; ++j) {
        for (int i = 0; i <= BOARD_SIZE - 5; ++i) {
            bool win = true;
            for (int k = 0; k < 5; ++k) {
                if (board[i + k][j] != player) {
                    win = false;
                    break;
                }
            }
            if (win) {
                return true;
            }
        }
    }

    // 检查对角线
    for (int i = 0; i <= BOARD_SIZE - 5; ++i) {
        for (int j = 0; j <= BOARD_SIZE - 5; ++j) {
            bool win = true;
            for (int k = 0; k < 5; ++k) {
                if (board[i + k][j + k] != player) {
                    win = false;
                    break;
                }
            }
            if (win) {
                return true;
            }
        }
    }

    // 检查反对角线
    for (int i = 0; i <= BOARD_SIZE - 5; ++i) {
        for (int j = BOARD_SIZE - 1; j >= 4; --j) {
            bool win = true;
            for (int k = 0; k < 5; ++k) {
                if (board[i + k][j - k] != player) {
                    win = false;
                    break;
                }
            }
            if (win) {
                return true;
            }
        }
    }

    return false;
}

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    char currentPlayer = PLAYER_X;

    while (true) {
        printBoard();

        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row column): ";
        std::cin >> row >> col;

        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != EMPTY) {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        board[row][col] = currentPlayer;

        if (hasWon(currentPlayer)) {
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            break;
        }
        else if (isFull()) {
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    return 0;
}
