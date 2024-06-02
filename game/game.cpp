#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//����ֲ����
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

//���彩ʬ��
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

//������Ϸ��
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
        //��ʼ��ֲ��
        plants.push_back(Plant("Peashooter", 100, 10, 5));
        plants.push_back(Plant("Sunflower", 50, 10, 2));

        srand(time(NULL));
    }

    bool isGameOver() {
        return zombies.size() > 0 && zombies[0].hp <= 0;
    }

    void generateZombies() {
        int randNum = rand() % 3; //�������1��3����ʬ

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

    vector<Plant> plants; //ֲ���б�
    vector<Zombie> zombies; //��ʬ�б�
    int wave = 1; //����
    int sun = 50; //̫����
};

int main() {
    Game game;
    game.start();

    return 0;
}