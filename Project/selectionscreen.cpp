#include"selectionscreen.h"

void selectionscreen(sf::RenderWindow &window,sf::Font &font,sf::RectangleShape &button,sf::Sprite &thumbnail)
{

    button.setSize(sf::Vector2f(442,250));
    button.setFillColor(sf::Color(75,75,75,205));
    for(int i=1;i>=0;i--)
    {
        button.setPosition(904*i+10,508);
        window.draw(button);
        thumbnail.setTextureRect(sf::IntRect(75*(1-i),0,75,53));
        thumbnail.setPosition(904*i+40,540);
        if (4-2*i==getmouseposition())
        {
            thumbnail.setScale(380/75,215/52);
            thumbnail.move(16,15);
        }
        else
        thumbnail.setScale(442/75,248/52);
        window.draw(thumbnail);
    }
    displaytext(window,"Play As",530,218,font,150,255);
    displaytext(window,"Black",1230,518,font,40,255);
    displaytext(window,"OR",580,558,font,120,255);
    displaytext(window,"White",310,518,font,40,255);
}

