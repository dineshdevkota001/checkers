#include"thirdscreen.h"

int screen3(sf::RenderWindow &window,sf::Font &font,sf::RectangleShape &button,sf::Sprite &thumbnail,sf::Sprite &menubackground,sf::Sprite &close,sf::Sprite &sprite)
{
    animation(window);
    window.clear();
    sf::Event event;
    sf::Clock clock;
    sf::IntRect rectSourceSprite(0 , 0, 171, 171);
    int status;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type==sf::Event::Closed)  window.close();
        }
        window.clear();
        window.draw(menubackground);

        for(int i=2;i>=0;i--)
        {
            button.setPosition(452*i+10,508);
            window.draw(button);
            thumbnail.setTextureRect(sf::IntRect(442,250*(2-i),442,250));
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

        displaytext(window,"Computer",1180,518,font,40,255);
        displaytext(window,"Human",740,518,font,40,255);
        displaytext(window,"Main Menu",280,518,font,30,255);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            status=getmouseposition();
            switch (status)
            {
            case 2:
                return 2;
            case 3:
                return 3;
            case 4:
                return 4;
            case 0:
               {
                   if (exit(window,button,font,menubackground)) window.close();
                   else break;
               }
            default:
                break;
            }
        }
        window.draw(close);
        if (clock.getElapsedTime().asSeconds() > 0.1f)
        {
            if (rectSourceSprite.left >2200)
                rectSourceSprite.left = 0;
            else
                rectSourceSprite.left += 171;

            sprite.setTextureRect(rectSourceSprite);
        clock.restart();
        }
        window.draw(sprite);

        window.display();
    }
}
