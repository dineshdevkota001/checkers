#include<SFML/Graphics.hpp>

animation(sf::RenderWindow &window)
{

    int radius=5;
    sf::CircleShape circle;
    int x=sf::Mouse::getPosition().x;
    int y=sf::Mouse::getPosition().y;
    circle.setFillColor(sf::Color(9, 9,9));
    while (radius<1400)
    {
        circle.setPosition(x-radius,y-radius);
        circle.setRadius(radius);
        window.draw(circle);
        window.display();
        radius=radius+60;
    }

}
