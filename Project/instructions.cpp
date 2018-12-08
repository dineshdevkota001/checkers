#include<SFML/Graphics.hpp>
void animation(sf::RenderWindow &window);
int instructions(sf::RenderWindow &window,sf::Sprite &instruction,sf::Sprite &menubackground)
{
    animation(window);
    window.clear();
    sf::RectangleShape rectangle;
    sf::Event event;
    rectangle.setSize(sf::Vector2f(1366,768));
    rectangle.setFillColor(sf::Color(0,0,0,200));

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type==sf::Event::Closed)  window.close();
        }
        window.clear();
        window.draw(menubackground);
        window.draw(rectangle);
        window.draw(instruction);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            animation(window);
            return 0;
        }
        window.display();
    }
}
