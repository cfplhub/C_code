#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <conio.h>
#include <Windows.h>
#include <chrono> 
#include <thread> 
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>

using namespace std;

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;

const char BLOCK_CHAR = '#';
const char EMPTY_CHAR = ' ';

struct Point {
    int x{ 0 };
    int y{ 0 };
};

class Tetromino {
public:
    virtual vector<Point> getPoints() const = 0;
    virtual ~Tetromino() = default;

    void rotate(bool clockwise = true) {
        for (Point& p : m_points) {
            int temp = p.x;
            p.x = p.y * (clockwise ? -1 : 1);
            p.y = temp * (clockwise ? 1 : -1);
        }
    }

private:
    vector<Point> m_points;
};
//// Tetromino.h
//class Tetromino {
//public:
//    virtual ~Tetromino() = default;
//    virtual vector<Point> getPoints() = 0;
//};

// Tetromino.cpp
class MyTetromino : public Tetromino {
public:
    vector<Point> getPoints(int level) override 
    {
        vector<Point> points;
        // 基于子类的实现返回点集合
        return points;
    }
};

// 使用 MyTetromino 的示例代码
shared_ptr<Tetromino> myTetromino = make_shared<MyTetromino>();


class IBlock : public Tetromino {
public:
    IBlock() {
        m_points = {
            {0, 0},
            {1, 0},
            {2, 0},
            {3, 0}
        };
    }

    vector<Point> getPoints() const override {
        return m_points;
    }

private:
    vector<Point> m_points;
};

class TBlock : public Tetromino {
public:
    TBlock() {
        m_points = {
            {1, 0},
            {0, 1},
            {1, 1},
            {2, 1}
        };
    }

    vector<Point> getPoints() const override {
        return m_points;
    }

private:
    vector<Point> m_points;
};

class ZBlock : public Tetromino {
public:
    ZBlock() {
        m_points = {
            {0, 0},
            {1, 0},
            {1, 1},
            {2, 1}
        };
    }

    vector<Point> getPoints() const override {
        return m_points;
    }

private:
    vector<Point> m_points;
};

class Board {
public:
    Board() {
        m_data.resize(BOARD_HEIGHT);
        for (int i = 0; i < BOARD_HEIGHT; ++i) {
            m_data[i].resize(BOARD_WIDTH, EMPTY_CHAR);
        }
    }

    void draw() const {
        system("cls");
        for (int i = 0; i < BOARD_HEIGHT; ++i) {
            for (int j = 0; j < BOARD_WIDTH; ++j) {
                cout << m_data[i][j];
            }
            cout << endl;
        }
    }

    bool canMove(const vector<Point>& points) const {
        for (const Point& p : points) {
            if (p.x < 0 || p.x >= BOARD_WIDTH || p.y < 0 || p.y >= BOARD_HEIGHT) {
                return false;
            }
            if (m_data[p.y][p.x] != EMPTY_CHAR) {
                return false;
            }
        }
        return true;
    }

    void setPoints(const vector<Point>& points, char c) {
        for (const Point& p : points) {
            m_data[p.y][p.x] = c;
        }
    }

    int clearLines() {
        int linesCleared = 0;
        for (int i = BOARD_HEIGHT - 1; i >= 0; --i) {
            bool isFull = true;
            for (int j = 0; j < BOARD_WIDTH; ++j) {
                if (m_data[i][j] == EMPTY_CHAR) {
                    isFull = false;
                    break;
                }
            }
            if (isFull) {
                ++linesCleared;
                for (int y = i; y > 0; --y) {
                    for (int x = 0; x < BOARD_WIDTH; ++x) {
                        m_data[y][x] = m_data[y - 1][x];
                    }
                }
                for (int x = 0; x < BOARD_WIDTH; ++x) {
                    m_data[0][x] = EMPTY_CHAR;
                }
                ++i;
            }
        }
        return linesCleared;
    }

private:
    vector<vector<char>> m_data;
};

class Game {
public:
    Game() {
        m_board.draw();
    }

    void loop() {
        while (true) {
            bool isGameOver = !spawnTetromino();
            while (!isGameOver) {
                if (!moveTetromino(0, 1)) {
                    isGameOver = !finishTetromino();
                }
                this_thread::sleep_for(250ms);
            }
            gameOver();
        }
    }

private:
    bool spawnTetromino() {
        static random_device rd;
        switch (rd()) {
        case 0:
            m_tetromino = make_shared<IBlock>();
            break;
        case 1:
            m_tetromino = make_shared<TBlock>();
            break;
        case 2:
            m_tetromino = make_shared<ZBlock>();
            break;
        }
        m_tetrominoPosition = { BOARD_WIDTH / 2, 0 };
        return m_board.canMove(getCurrentPoints());
    }

   
    vector<Point> getCurrentPoints() {
        
        std::shared_ptr<Tetromino> m_tetromino = std::make_shared<Tetromino>();

        if (m_tetromino != nullptr) {
            vector<Point> points = m_tetromino->getPoints();
            // ...
        }

        vector<Point> points = m_tetromino->getPoints() ;
        for (Point& p : points) {
            p.x += m_tetrominoPosition.x;
            p.y += m_tetrominoPosition.y;
        }
        return points;
    }

    bool moveTetromino(int dx, int dy) {
        m_board.setPoints(getCurrentPoints(), EMPTY_CHAR);
        m_tetrominoPosition.x += dx;
        m_tetrominoPosition.y += dy;
        if (!m_board.canMove(getCurrentPoints())) {
            m_tetrominoPosition.x -= dx;
            m_tetrominoPosition.y -= dy;
            m_board.setPoints(getCurrentPoints(), BLOCK_CHAR);
            return false;
        }
        m_board.setPoints(getCurrentPoints(), BLOCK_CHAR);
        return true;
    }

    bool finishTetromino() {
        m_board.setPoints(getCurrentPoints(), BLOCK_CHAR);
        int linesCleared = m_board.clearLines();
        m_score += linesCleared * linesCleared;
        m_board.draw();
        return spawnTetromino();
    }

    void gameOver() {
        cout << "Game over!" << endl;
        cout << "Final score: " << m_score << endl;
        cout << "Press any key to restart." << endl;
        int ch;
        ch = _getch();
        m_score = 0;
        m_board = Board();
    }

private:
    shared_ptr<Tetromino> m_tetromino;
    Point m_tetrominoPosition;
    Board m_board;
    int m_score{ 0 };
};

int main() {
    Game game;
    game.loop();
    return 0;
}
