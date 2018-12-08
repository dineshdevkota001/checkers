#include"secondscreen.h"

int screen2(sf::RenderWindow &window,sf::Font &font,sf::RectangleShape &button,sf::Sprite &thumbnail,sf::Sprite &instruction,sf::Sprite &close)
{
    int x=2,status=1;
    animation(window);
    sf::Texture menu;
    sf::Sprite menubackground;
    assert( menu.loadFromFile("images/menupage.png"));
    menubackground.setTexture(menu);
    sf::Texture texture;
    texture.loadFromFile("images/spinningcoin.png");
    texture.setSmooth(true);

    sf::IntRect rectSourceSprite(0 , 0, 171, 171);
    sf::Sprite sprite(texture,rectSourceSprite);
    sf::Clock clock;
    sprite.setPosition(528,100);
    sprite.setScale(2,2);

    button.setSize(sf::Vector2f(442,250));
    sf::Event event;

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
        displaytext(window,"Play",1230,518,font,40,255);
        displaytext(window,"Instructions",740,518,font,30,255);
        displaytext(window,"Exit",340,518,font,30,255);
        window.draw(close);


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            status=getmouseposition();
            if (status==2)
                {
                    x=(screen3(window,font,button,thumbnail,menubackground,close,sprite));
                    switch (x)
                    {
                    case 1:
                        break;
                    default:
                        return x;
                    }
                }
            else if (status== 3)
                instructions(window,instruction,menubackground);

            else if (status==0||status==4)
                {
                    if (exit(window,button,font,menubackground))
                    {
                        window.close();
                    }
                }
            else
                status=1;
        }
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
