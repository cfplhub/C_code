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
        std::cout << name << " 发动攻击！" << std::endl;
    }

    void TakeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            std::cout << name << " 被击败了！" << std::endl;
        }
        else {
            std::cout << name << " 受到 " << damage << " 点伤害，剩余生命值：" << health << std::endl;
        }
    }

    void Heal() {
        health += 20;
        if (health > 100) {
            health = 100;
        }
        std::cout << name << " 使用恢复技能，恢复了 20 点生命值，当前生命值：" << health << std::endl;
    }
};

class Enemy {
public:
    std::string name;
    int health;

    Enemy(const std::string& _name) : name(_name), health(50) {}

    void Attack() {
        std::cout << name << " 发动攻击！" << std::endl;
    }

    void TakeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            std::cout << name << " 被击败了！" << std::endl;
        }
        else {
            std::cout << name << " 受到 " << damage << " 点伤害，剩余生命值：" << health << std::endl;
        }
    }
};

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Player player("玩家A");

    std::vector<Enemy> enemies;
    enemies.push_back(Enemy("敌人1"));
    enemies.push_back(Enemy("敌人2"));
    enemies.push_back(Enemy("敌人3"));

    std::cout << "-- 游戏开始 --" << std::endl;

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
            std::cout << "玩家被击败了！游戏结束！" << std::endl;
        }
        else if (enemies.empty()) {
            isGameOver = true;
            std::cout << "所有敌人都被击败了！玩家胜利！" << std::endl;
        }
        else {
            player.Heal();

            if (enemy.health <= 0) {
                std::cout << "敌人 " << enemy.name << " 被击败了！" << std::endl;
                enemies.erase(enemies.begin() + enemyIndex);
            }
        }
    }

    std::cout << "-- 游戏结束 --" << std::endl;

    return 0;
}