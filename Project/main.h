#include<iostream>
#include<SFML/Graphics.hpp>
#include<cassert>

void logo(sf::RenderWindow &window, sf::Sprite &sprite,float scale);

void jumpinglogo(sf::RenderWindow &window, sf::Sprite &sprite);

void screen1(sf::RenderWindow &window, sf::Sprite &background,sf::RectangleShape &rectangle, sf::Font &font,float i);

int screen2(sf::RenderWindow &window,sf::Font &font,sf::RectangleShape &button,sf::Sprite &thumbnail,sf::Sprite &instruction,sf::Sprite &close);

int vscomputer(sf::RenderWindow &window,sf::RectangleShape &rectangle,sf::RectangleShape &button,sf::Sprite &thumbnail);

int vshuman(sf::RenderWindow &window,sf::RectangleShape &rectangle,sf::RectangleShape &button,sf::Sprite &thumbnail);

void animation(sf::RenderWindow &window);

bool exit(sf::RenderWindow &window,sf::RectangleShape &rectangle,sf::Font &font,sf::Sprite &background);

void displaytext(sf::RenderWindow &window,std::string str,int positionx,int positiony,sf::Font &font,int siz,int opacity=255);


