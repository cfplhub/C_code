#include <SFML/Graphics.hpp>


int main()
{
    // 创建一个窗口
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Console Application");

    // 创建一个圆形
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(400, 300);

    // 游戏循环，持续更新窗口和渲染图形
    while (window.isOpen())
    {
        // 处理窗口事件
        sf::Event event;
        while (window.pollEvent(event))
        {
            // 关闭窗口事件
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 清空窗口并用白色填充
        window.clear(sf::Color::White);

        // 绘制圆形
        window.draw(shape);

        // 显示窗口中的内容
        window.display();
    }

    return 0;
}