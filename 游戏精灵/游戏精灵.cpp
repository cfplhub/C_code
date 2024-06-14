#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#inclue"game.hpp"

using namespace sf;

const int GAME_WIDTH = 800;
const int GAME_HEIGHT = 600;
const float PLAYER_SPEED = 0.2f;
const float ENEMY_SPEED = 0.1f;

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    RenderWindow window(VideoMode(GAME_WIDTH, GAME_HEIGHT), "Sprite Game");
    window.setVerticalSyncEnabled(true);

    Texture playerTexture;
    if (!playerTexture.loadFromFile("resources/player.png"))
    {
        return EXIT_FAILURE;
    }
    Sprite player(playerTexture);
    player.setScale(0.5f, 0.5f);
    player.setPosition(200.0f, 200.0f);

    Texture enemyTexture;
    if (!enemyTexture.loadFromFile("resources/enemy.png"))
    {
        return EXIT_FAILURE;
    }
    Sprite enemy(enemyTexture);
    enemy.setScale(0.2f, 0.2f);
    enemy.setColor(Color::Red);
    enemy.setPosition(400.0f, 300.0f);
    Vector2f enemyVelocity(-ENEMY_SPEED, ENEMY_SPEED);

    Clock clock;
    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            player.move(-PLAYER_SPEED * deltaTime, 0.0f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            player.move(PLAYER_SPEED * deltaTime, 0.0f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            player.move(0.0f, -PLAYER_SPEED * deltaTime);
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            player.move(0.0f, PLAYER_SPEED * deltaTime);
        }

        enemy.move(enemyVelocity.x * deltaTime, enemyVelocity.y * deltaTime);
        if (enemy.getPosition().x < 0.0f || enemy.getPosition().x > GAME_WIDTH - enemy.getLocalBounds().width)
        {
            enemyVelocity.x = -enemyVelocity.x;
        }
        if (enemy.getPosition().y < 0.0f || enemy.getPosition().y > GAME_HEIGHT - enemy.getLocalBounds().height)
        {
            enemyVelocity.y = -enemyVelocity.y;
        }

        if (player.getGlobalBounds().intersects(enemy.getGlobalBounds()))
        {
            window.close();
        }

        window.clear(Color::White);

        window.draw(player);
        window.draw(enemy);

        window.display();
    }

    return EXIT_SUCCESS;
}