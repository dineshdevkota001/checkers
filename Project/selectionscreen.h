#ifndef SELECTIONSCREEN_H_INCLUDED
#define SELECTIONSCREEN_H_INCLUDED


#include<SFML/Graphics.hpp>

int getmouseposition();

void displaytext(sf::RenderWindow &window,std::string str,int positionx,int positiony,sf::Font &font,int siz,int opacity=255);


#endif // SELECTIONSCREEN_H_INCLUDED
