#ifndef SECONDSCREEN_H_INCLUDED
#define SECONDSCREEN_H_INCLUDED

#include<SFML/Graphics.hpp>
#include<cassert>

int getmouseposition();

int screen3(sf::RenderWindow &window,sf::Font &font,sf::RectangleShape &button,sf::Sprite &thumbnail,sf::Sprite &menubackground,sf::Sprite &close,sf::Sprite &sprite);

int instructions(sf::RenderWindow &window,sf::Sprite &instruction,sf::Sprite &menubackground);

void statistics();

void animation(sf::RenderWindow &window);

bool exit(sf::RenderWindow &window,sf::RectangleShape &rectangle,sf::Font &font,sf::Sprite &background);

void displaytext(sf::RenderWindow &window,std::string str,int positionx,int positiony,sf::Font &font,int siz,int opacity=255);
#endif // SECONDSCREEN_H_INCLUDED
