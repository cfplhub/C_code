#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>


using namespace std;

// ������Ϸ���ڵĴ�С
const int WIDTH = 20;
const int HEIGHT = 20;

// �����ߵ���󳤶�
const int MAX_LENGTH = WIDTH * HEIGHT;

// �����ߡ�ʳ��ͷ���Ľṹ��
struct Point
{
    int x;
    int y;
};
enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

// ������Ϸ״̬ȫ�ֱ���
int score = 0;  // ��Ϸ�÷�
int length = 0; // �ߵĳ���
Point snake[MAX_LENGTH]; // �ߵ�����
Point food; // ʳ�������
Direction direction; // �ߵ��ƶ�����

// ����һ�������ʳ��λ��
void generateFood()
{
    srand((unsigned)time(NULL));
    food.x = rand() % WIDTH;
    food.y = rand() % HEIGHT;
}

// ��ʼ����Ϸ״̬
void init()
{
    // ��ʼ���ߵ�����
    length = 3;
    snake[0].x = 3;
    snake[0].y = 1;
    snake[1].x = 2;
    snake[1].y = 1;
    snake[2].x = 1;
    snake[2].y = 1;

    // ��ʼ������͵÷�
    direction = RIGHT;
    score = 0;

    // ���ɵ�һ��ʳ��
    generateFood();
}

// �ж���ͷ�Ƿ������߽��������
bool isGameOver()
{
    int x = snake[0].x;
    int y = snake[0].y;
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return true;
    }
    for (int i = 1; i < length; i++) {
        if (snake[i].x == x && snake[i].y == y) {
            return true;
        }
    }
    return false;
}

// �����û����룬�ı��ߵ��ƶ�����
void handleInput()
{
    if (_kbhit()) {
        char ch = _getch();
        switch (ch) {
        case 'w':
            if (direction != DOWN) {
                direction = UP;
            }
            break;
        case 's':
            if (direction != UP) {
                direction = DOWN;
            }
            break;
        case 'a':
            if (direction != RIGHT) {
                direction = LEFT;
            }
            break;
        case 'd':
            if (direction != LEFT) {
                direction = RIGHT;
            }
            break;
        }
    }
}

// ���ݵ�ǰ���򣬸�����ͷλ��
void move()
{
    for (int i = length; i > 0; i--) {
        snake[i].x = snake[i - 1].x;
        snake[i].y = snake[i - 1].y;
    }
    switch (direction) {
    case UP:
        snake[0].y--;
        break;
    case DOWN:
        snake[0].y++;
        break;
    case LEFT:
        snake[0].x--;
        break;
    case RIGHT:
        snake[0].x++;
        break;
    }
}

// �ж���ͷ�Ƿ�Ե���ʳ����������ӵ÷֣������ߵĳ��ȣ���������ʳ��λ��
void checkFood()
{
    if (snake[0].x == food.x && snake[0].y == food.y) {
        score += 10;
        length++;
        generateFood();
    }
}

// ��ӡ��Ϸ����
void print()
{
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++) {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < HEIGHT; i++) {
        cout << "#";
        for (int j = 0; j < WIDTH; j++) {
            if (i == snake[0].y && j == snake[0].x) {
                cout << "0";
            }
            else if (i == food.y && j == food.x) {
                cout << "$";
            }
            else {
                bool isBody = false;
                for (int k = 1; k < length; k++) {
                    if (snake[k].y == i && snake[k].x == j) {
                        isBody = true;
                        break;
                    }
                }
                if (isBody) {
                    cout << "o";
                }
                else {
                    cout << " ";
                }
            }
        }
        cout << "#" << endl;
    }
    for (int i = 0; i < WIDTH + 2; i++) {
        cout << "#";
    }
    cout << endl;
    cout << "Score: " << score << endl;
}

int main()
{
    init();
    while (!isGameOver()) {
        handleInput();
        move();
        checkFood();
        print();
        Sleep(150);
    }
    cout << "Game Over! Your score is " << score << endl;
    return 0;
}
