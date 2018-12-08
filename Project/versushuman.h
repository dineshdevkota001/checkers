#ifndef VERSUSHUMAN_H_INCLUDED
#define VERSUSHUMAN_H_INCLUDED

#include<SFML/Graphics.hpp>
#include<cassert>
#include<SFML/Audio.hpp>
#include<SFML/Window/Keyboard.hpp>

void displaymen(sf::RenderWindow &window,sf::Sprite &men,int type,sf::Vector2i &position);

int islegal(int ix,int iy,int fx,int fy,int board[][8]);

void animation(sf::RenderWindow &window);

int getmouseposition();

void selectionscreen(sf::RenderWindow &window,sf::Font &font,sf::RectangleShape &button,sf::Sprite &thumbnail);

int pausemenu(sf::RenderWindow &window,sf::Font &font,sf::RectangleShape &rectangle,sf::RectangleShape &button,sf::Sprite &thumbnail);

bool exit(sf::RenderWindow &window,sf::RectangleShape &rectangle,sf::Font &font,sf::Sprite &background);

sf::Vector2i getboardvector();

#endif // VERSUSHUMAN_H_INCLUDED
