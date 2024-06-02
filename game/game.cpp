#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//定义植物类
class Plant {
public:
    Plant(string name, int cost, int hp, int attack) {
        this->name = name;
        this->cost = cost;
        this->hp = hp;
        this->attack = attack;
    }

    void show() {
        cout << "Plant: " << name << ", Cost: " << cost << ", HP: " << hp << ", Attack: " << attack << endl;
    }

private:
    string name;
    int cost;
    int hp;
    int attack;
};

//定义僵尸类
class Zombie {
public:
    Zombie(string name, int speed, int hp, int attack) {
        this->name = name;
        this->speed = speed;
        this->hp = hp;
        this->attack = attack;
    }

    void show() {
        cout << "Zombie: " << name << ", Speed: " << speed << ", HP: " << hp << ", Attack: " << attack << endl;
    }

private:
    string name;
    int speed;
    int hp;
    int attack;
};

//定义游戏类
class Game {
public:
    Game() {
        init();
    }

    void start() {
        while (true) {
            if (isGameOver()) {
                cout << "Game Over!" << endl;
                break;
            }

            cout << "----------- Wave " << wave << " ------------" << endl;
            cout << "Sun: " << sun << endl;
            cout << "1. Plant 2. Skip" << endl;

            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Select plant: " << endl;
                for (int i = 0; i < plants.size(); i++) {
                    Plant p = plants[i];
                    cout << i << ". ";
                    p.show();
                }

                int plantIndex;
                cin >> plantIndex;

                Plant p = plants[plantIndex];
                if (sun >= p.cost) {
                    cout << "Plant successful!" << endl;
                    sun -= p.cost;
                }
                else {
                    cout << "Sun not enough!" << endl;
                }

                break;
            case 2:
                cout << "Next wave!" << endl;
                wave++;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }

            generateZombies();
            for (int i = 0; i < zombies.size(); i++) {
                Zombie z = zombies[i];
                cout << "Zombie entered! ";
                z.show();
            }

            cout << "----------------------------------" << endl;
        }
    }

private:
    void init() {
        //初始化植物
        plants.push_back(Plant("Peashooter", 100, 10, 5));
        plants.push_back(Plant("Sunflower", 50, 10, 2));

        srand(time(NULL));
    }

    bool isGameOver() {
        return zombies.size() > 0 && zombies[0].hp <= 0;
    }

    void generateZombies() {
        int randNum = rand() % 3; //随机生成1到3个僵尸

        switch (randNum) {
        case 0:
            zombies.push_back(Zombie("Common Zombie", 1, 10, 2));
            break;
        case 1:
            zombies.push_back(Zombie("Bucket Zombie", 1, 20, 3));
            break;
        case 2:
            zombies.push_back(Zombie("Conehead Zombie", 1, 30, 4));
            break;
        default:
            break;
        }
    }

    vector<Plant> plants; //植物列表
    vector<Zombie> zombies; //僵尸列表
    int wave = 1; //波数
    int sun = 50; //太阳数
};

int main() {
    Game game;
    game.start();

    return 0;
}