#ifndef VERSUSCOMPUTER_H_INCLUDED
#define VERSUSCOMPUTER_H_INCLUDED

#include<SFML/Graphics.hpp>
#include<cassert>
#include<SFML/Audio.hpp>

void displaymen(sf::RenderWindow &window,sf::Sprite &men,int type,sf::Vector2i &position);

void animation(sf::RenderWindow &window);

sf::Vector2i getboardvector();

void selectionscreen(sf::RenderWindow &window,sf::Font &font,sf::RectangleShape &button,sf::Sprite &thumbnail);

int getmouseposition();

bool exit(sf::RenderWindow &window,sf::RectangleShape &rectangle,sf::Font &font,sf::Sprite &background);

int pausemenu(sf::RenderWindow &window,sf::Font &font,sf::RectangleShape &rectangle,sf::RectangleShape &button,sf::Sprite &thumbnail);


#endif // VERSUSCOMPUTER_H_INCLUDED
