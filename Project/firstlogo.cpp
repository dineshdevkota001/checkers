///handles the first 10 seconds of the game
#include<SFML/Graphics.hpp>


void logo(sf::RenderWindow &window, sf::Sprite &sprite,float scale)
{
    int i=0;
    while(i<150)
    {
    window.clear(sf::Color::White);
    sprite.setScale(scale,scale);
    sprite.setPosition(window.getSize().x/2-sprite.getTexture()->getSize().x*scale/2,window.getSize().y/2-sprite.getTexture()->getSize().y*scale/2);
    window.draw(sprite);
    window.display();
    i++;
    }
}



void jumpinglogo(sf::RenderWindow &window,sf::Sprite &logo)
{
    int i=0;
    float theta=0;
    logo.setTextureRect(sf::IntRect(103,0,95,88));
    logo.setScale(0.6,0.6);
    logo.setPosition(0,670);


     while(i<648)
    {
        window.clear(sf::Color::White);
        logo.setPosition(i,648-648*sin(theta));
        window.draw(logo);
        theta = theta+4*0.00403;
        window.display();
        i=i+4;
    }
    i=88;
    logo.setPosition(593,328);
    while(i<200)
    {
        window.clear(sf::Color::White);
        logo.setTextureRect(sf::IntRect(0,0,300,i));
        window.draw(logo);
        window.display();
        i=i+5;
    }
}
