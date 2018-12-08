#include"mendisplay.h"
void displaymen(sf::RenderWindow &window,sf::Sprite &men,int type,sf::Vector2i &position)
{
    if (type!=0&&type!=5)
    {
        sf::Vector2f pos,scale;
        men.setTextureRect(sf::IntRect(75*((type-1)%2),53*((int)((type-1)/2)),75,53));

        scale.x=pow(0.92,position.y);
        scale.y=scale.x;

        pos=returnscreenvector(position);

        men.setScale(scale);
        men.setPosition(pos);

        window.draw(men);
    }
    else {}

}
