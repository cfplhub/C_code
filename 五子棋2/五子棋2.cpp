
#include <iostream>
#include <cstring>

using namespace std;

const int BOARD_SIZE = 15;

//����������
class Chessboard {
public:
    Chessboard();
    void display();
    void set(int row, int col, char piece);
    bool check_win(int row, int col, char piece);
private:
    char board[BOARD_SIZE][BOARD_SIZE];
};

Chessboard::Chessboard() {
    memset(board, ' ', sizeof(board));
}

void Chessboard::display() {
    cout << "  ";
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void Chessboard::set(int row, int col, char piece) {
    board[row][col] = piece;
}

bool Chessboard::check_win(int row, int col, char piece) {
    int count;
    //������
    count = 1;
    for (int i = col + 1; i < BOARD_SIZE && board[row][i] == piece; i++) {
        count++;
    }
    for (int i = col - 1; i >= 0 && board[row][i] == piece; i--) {
        count++;
    }
    if (count >= 5) {
        return true;
    }
    //�������
    count = 1;
    for (int i = row + 1; i < BOARD_SIZE && board[i][col] == piece; i++) {
        count++;
    }
    for (int i = row - 1; i >= 0 && board[i][col] == piece; i--) {
        count++;
    }
    if (count >= 5) {
        return true;
    }
    //�����б��
    count = 1;
    for (int i = row + 1, j = col + 1; i < BOARD_SIZE && j < BOARD_SIZE && board[i][j] == piece; i++, j++) {
        count++;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0 && board[i][j] == piece; i--, j--) {
        count++;
    }
    if (count >= 5) {
        return true;
    }
    //��鷴б��
    count = 1;
    for (int i = row - 1, j = col + 1; i >= 0 && j < BOARD_SIZE && board[i][j] == piece; i--, j++) {
        count++;
    }
    for (int i = row + 1, j = col - 1; i < BOARD_SIZE && j >= 0 && board[i][j] == piece; i++, j--) {
        count++;
    }
    if (count >= 5) {
        return true;
    }
    return false;
}

//������Ϸ��
class Gomoku {
public:
    void play();
private:
    Chessboard chessboard;
};

void Gomoku::play() {
    int row, col;
    char piece = 'X';
    while (true) {
        chessboard.display();
        cout << "��" << piece << "�����壬�����к��кţ��ÿո�ָ�����" << endl;
        cin >> row >> col;
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            cout << "���Ϸ������룡" << endl;
            continue;
        }
        if (chessboard.check_win(row, col, piece)) {
            cout << piece << "����ʤ��" << endl;
            chessboard.display();
            break;
        }
        chessboard.set(row, col, piece);
        piece = (piece == 'X') ? 'O' : 'X';
    }
}

int main() {
    Gomoku game;
    game.play();
    return 0;
}
