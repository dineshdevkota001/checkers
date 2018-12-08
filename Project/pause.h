#ifndef PAUSE_H_INCLUDED
#define PAUSE_H_INCLUDED

#include<SFML/Graphics.hpp>
int getmouseposition();

void displaytext(sf::RenderWindow &window,std::string str,int positionx,int positiony,sf::Font &font,int siz,int opacity=255);

#endif // PAUSE_H_INCLUDED
