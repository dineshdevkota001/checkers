#include"pause.h"
int pausemenu(sf::RenderWindow &window,sf::Font &font,sf::RectangleShape &rectangle,sf::RectangleShape &button,sf::Sprite &thumbnail)
{
        button.setSize(sf::Vector2f(442,250));
        button.setFillColor(sf::Color(0,0,0,150));

        window.draw(rectangle);

        for(int i=2;i>=0;i--)
        {
            button.setPosition(452*i+10,508);
            window.draw(button);
            thumbnail.setTextureRect(sf::IntRect(0,250*(2-i),442,250));
            thumbnail.setPosition(452*i+10,508);
            if (i==4-getmouseposition())
            {
                thumbnail.setScale(0.9,0.9);
                thumbnail.move(22,13);
            }
            else
            thumbnail.setScale(1,1);
            window.draw(thumbnail);
        }
        displaytext(window,"Back",1230,518,font,40,255);
        displaytext(window,"Exit",740,518,font,30,255);
        displaytext(window,"Main Menu",310,518,font,30,255);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
        return getmouseposition();
        }
        else return 1;
}
