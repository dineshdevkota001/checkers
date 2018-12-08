#include<SFML/Graphics.hpp>

void displaytext(sf::RenderWindow &window, std::string str,int positionx,int positiony,sf::Font &font,int siz,int opacity)
{
    sf::Text text(str,font);
    text.setPosition(positionx,positiony);
    text.setCharacterSize(siz);
    text.setColor(sf::Color(255,255,255,opacity));
    window.draw(text);
}
