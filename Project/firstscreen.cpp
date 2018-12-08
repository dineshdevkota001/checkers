#include"firstscreen.h"

void screen1(sf::RenderWindow &window, sf::Sprite &background,sf::RectangleShape &rectangle, sf::Font &font,float i)
{
    window.draw(background);
    window.draw(rectangle);
    displaytext(window,"Checkers",350,window.getSize().y/4,font,120,255);
    displaytext(window,"V0.9",860,window.getSize().y/4+80,font,40,255);
    displaytext(window,"Click Anywhere...",980,window.getSize().y/1.2,font,50,254*sin(i)*sin(i));

}
