#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");

    sf::CircleShape player(50.0f);
    player.setFillColor(sf::Color::Green);
    player.setPosition(400.0f, 300.0f);

    sf::RectangleShape enemy(sf::Vector2f(40.0f, 40.0f));
    enemy.setFillColor(sf::Color::Red);
    enemy.setPosition(100.0f, 100.0f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 移动敌人
        enemy.move(1.0f, 1.0f);

        // 如果敌人和玩家相撞则游戏结束
        if (player.getGlobalBounds().intersects(enemy.getGlobalBounds()))
        {
            std::cout << "Game over!" << std::endl;
            window.close();
        }

        window.clear();
        window.draw(player);
        window.draw(enemy);
        window.display();
    }

    return 0;
}