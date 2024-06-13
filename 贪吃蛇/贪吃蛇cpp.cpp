#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>


using namespace std;

// 定义游戏窗口的大小
const int WIDTH = 20;
const int HEIGHT = 20;

// 定义蛇的最大长度
const int MAX_LENGTH = WIDTH * HEIGHT;

// 定义蛇、食物和方向的结构体
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

// 定义游戏状态全局变量
int score = 0;  // 游戏得分
int length = 0; // 蛇的长度
Point snake[MAX_LENGTH]; // 蛇的坐标
Point food; // 食物的坐标
Direction direction; // 蛇的移动方向

// 生成一个随机的食物位置
void generateFood()
{
    srand((unsigned)time(NULL));
    food.x = rand() % WIDTH;
    food.y = rand() % HEIGHT;
}

// 初始化游戏状态
void init()
{
    // 初始化蛇的坐标
    length = 3;
    snake[0].x = 3;
    snake[0].y = 1;
    snake[1].x = 2;
    snake[1].y = 1;
    snake[2].x = 1;
    snake[2].y = 1;

    // 初始化方向和得分
    direction = RIGHT;
    score = 0;

    // 生成第一个食物
    generateFood();
}

// 判断蛇头是否碰到边界或者蛇身
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

// 处理用户输入，改变蛇的移动方向
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

// 根据当前方向，更新蛇头位置
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

// 判断蛇头是否吃到了食物，如是则增加得分，增加蛇的长度，重新生成食物位置
void checkFood()
{
    if (snake[0].x == food.x && snake[0].y == food.y) {
        score += 10;
        length++;
        generateFood();
    }
}

// 打印游戏窗口
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
