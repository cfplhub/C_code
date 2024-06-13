#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class Player {
public:
    std::string name;
    int health;

    Player(const std::string& _name) : name(_name), health(100) {}

    void Attack() {
        std::cout << name << " ����������" << std::endl;
    }

    void TakeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            std::cout << name << " �������ˣ�" << std::endl;
        }
        else {
            std::cout << name << " �ܵ� " << damage << " ���˺���ʣ������ֵ��" << health << std::endl;
        }
    }

    void Heal() {
        health += 20;
        if (health > 100) {
            health = 100;
        }
        std::cout << name << " ʹ�ûָ����ܣ��ָ��� 20 ������ֵ����ǰ����ֵ��" << health << std::endl;
    }
};

class Enemy {
public:
    std::string name;
    int health;

    Enemy(const std::string& _name) : name(_name), health(50) {}

    void Attack() {
        std::cout << name << " ����������" << std::endl;
    }

    void TakeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            std::cout << name << " �������ˣ�" << std::endl;
        }
        else {
            std::cout << name << " �ܵ� " << damage << " ���˺���ʣ������ֵ��" << health << std::endl;
        }
    }
};

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Player player("���A");

    std::vector<Enemy> enemies;
    enemies.push_back(Enemy("����1"));
    enemies.push_back(Enemy("����2"));
    enemies.push_back(Enemy("����3"));

    std::cout << "-- ��Ϸ��ʼ --" << std::endl;

    bool isGameOver = false;
    while (!isGameOver && player.health > 0 && !enemies.empty()) {
        player.Attack();

        int enemyIndex = std::rand() % enemies.size();
        Enemy& enemy = enemies[enemyIndex];

        enemy.TakeDamage(20);

        enemy.Attack();

        player.TakeDamage(10);

        if (player.health <= 0) {
            isGameOver = true;
            std::cout << "��ұ������ˣ���Ϸ������" << std::endl;
        }
        else if (enemies.empty()) {
            isGameOver = true;
            std::cout << "���е��˶��������ˣ����ʤ����" << std::endl;
        }
        else {
            player.Heal();

            if (enemy.health <= 0) {
                std::cout << "���� " << enemy.name << " �������ˣ�" << std::endl;
                enemies.erase(enemies.begin() + enemyIndex);
            }
        }
    }

    std::cout << "-- ��Ϸ���� --" << std::endl;

    return 0;
}