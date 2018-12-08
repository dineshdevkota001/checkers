#ifndef THIRDSCREEN_H_INCLUDED
#define THIRDSCREEN_H_INCLUDED

#include<SFML/Graphics.hpp>

sf::Vector2f returnscreenvector(sf::Vector2i &position);

int getmouseposition();

void animation(sf::RenderWindow &window);

bool exit(sf::RenderWindow &window,sf::RectangleShape &rectangle,sf::Font &font,sf::Sprite &background);

void displaytext(sf::RenderWindow &window,std::string str,int positionx,int positiony,sf::Font &font,int siz,int opacity=255);

#endif // THIRDSCREEN_H_INCLUDED
