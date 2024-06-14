#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void update(sf::Time deltaTime);
    void render();

private:
    static const int GAME_WIDTH = 800;
    static const int GAME_HEIGHT = 600;
    static const float PLAYER_SPEED;
    static const float ENEMY_SPEED;

    sf::RenderWindow mWindow;
    sf::Texture mPlayerTexture;
    sf::Sprite mPlayer;
    sf::Texture mEnemyTexture;
    sf::Sprite mEnemy;
    sf::Vector2f mEnemyVelocity;
    bool mIsMovingUp = false;
    bool mIsMovingDown = false;
    bool mIsMovingLeft = false;
    bool mIsMovingRight = false;
};

#endif // GAME_HPP