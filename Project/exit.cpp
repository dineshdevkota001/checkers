#include<SFML/Graphics.hpp>
void displaytext(sf::RenderWindow &window,std::string str,int positionx,int positiony,sf::Font &font,int siz,int opacity);
void animation(sf::RenderWindow &window);
bool exit(sf::RenderWindow &window,sf::RectangleShape &rectangle,sf::Font &font,sf::Sprite &background)
{
    animation(window);
    window.clear(sf::Color(75,75,75,200));
    rectangle.setFillColor(sf::Color(0,0,0,180));
    rectangle.setSize(sf::Vector2f(1366,768));
    rectangle.setPosition(0,0);
    window.draw(background);
    window.draw(rectangle);
    rectangle.setSize(sf::Vector2f(442,250));
    rectangle.setFillColor(sf::Color(75,75,75,100));
    rectangle.setPosition(462,250);

    window.draw(rectangle);
    displaytext(window,"Click to Exit",472,300,font,80,255);
    window.display();

    while (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {}

    if (sf::Mouse::getPosition().x>590&&sf::Mouse::getPosition().y>250&&sf::Mouse::getPosition().x<904&&sf::Mouse::getPosition().y<500)
        return true;

    else
    {
        rectangle.setSize(sf::Vector2f(442,250));
        rectangle.setFillColor(sf::Color(0,0,0,160));
        return false;
    }
}
