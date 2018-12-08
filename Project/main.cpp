/***********************************
*****    ******    ******   ********
***        ***   *   ****   ********
**   * *    **      *****   *    ***
**   * *    **   *   ****      *   *
***        ***  ***   ***        ***
************************************
************************************
*
*########BY team ORB###################
*
*******CHECKERS V 0.9********************
*
*************************************
the following program is open sourced the recipient may change
iy in any way he neeeds if it doesnot violate fair usage law***/





///function remaining rotateboard function
///function remaining move men function
///                 spining coin


#include "main.h"
#include<SFML/Audio.hpp>


int main()
{
    ///declare variables and drawables

    int gametype=4;
    float j=0;
    sf::RenderWindow window(sf::VideoMode(1366,768),"Checkers Version 0.9",sf::Style::Fullscreen);
    sf::Event event;
    sf::Texture logo1_texture,logo2_texture,menubackground_texture,menuthumbnail_texture,close_texture,instruction_texture,pause_texture;
    pause_texture.loadFromFile("images/pauseasset.png");
    sf::Sprite logo1,logo3,logo2,menubackground,menuthumbnail,close,instruction,pause(pause_texture);
    sf::Font font;
    sf::RectangleShape rectangle,button;
    sf::Music menusound,pendulum;

    ///setting frame limit
    window.setFramerateLimit(60);

    assert(font.loadFromFile("fonts/arial.ttf"));                           ///loading every variable from files
    assert(logo1_texture.loadFromFile("images/logo1.png"));
    assert(logo2_texture.loadFromFile("images/splash_1312.png"));
    assert(menubackground_texture.loadFromFile("images/menupage.png"));
    assert(menuthumbnail_texture.loadFromFile("images/screen32asset.png"));
    assert(close_texture.loadFromFile("images/close.png"));
    assert(instruction_texture.loadFromFile("images/instruction.png"));
    assert(menusound.openFromFile("sounds/menusound.ogg"));
    assert(pendulum.openFromFile("sounds/gamesound.ogg"));


    logo1_texture.setSmooth(true);
    logo2_texture.setSmooth(true);

    logo1.setTexture(logo1_texture);                                ///set texture to sprites
    logo2.setTexture(logo2_texture);
    logo3.setTexture(logo1_texture);
    close.setTexture(close_texture);
    menubackground.setTexture(menubackground_texture);
    menuthumbnail.setTexture(menuthumbnail_texture);
    instruction.setTexture(instruction_texture);


    close.setPosition(1346,0);                                         ///setting sizes for various drawables
    rectangle.setSize(sf::Vector2f(1366,768));
    button.setSize(sf::Vector2f(442,250));
    rectangle.setFillColor(sf::Color(0,0,0,220));
    button.setFillColor(sf::Color(0,0,0,160));

	pendulum.setVolume(160);
    menusound.setLoop(true);
    pendulum.setLoop(true);

    jumpinglogo(window,logo3);

    logo(window , logo1,0.60);

    logo(window,logo2,1);

    window.clear();


    while (window.isOpen())
    {
        while(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)       window.close();
            }
            window.clear();
            j=j+0.03;
            screen1(window,menubackground,rectangle,font,j);

            window.display();
        }
        break;
    }




    while (gametype==4)
    {
        pendulum.stop();
        menusound.play();
        gametype=screen2(window,font,button,menuthumbnail,instruction,close);
        animation(window);

        if (gametype==2)
        {
            menusound.stop();
            pendulum.play();
            pendulum.setLoop(true);
            gametype= vscomputer(window,rectangle,button,pause);
		}
        else if (gametype==3)
        {
            menusound.stop();
            pendulum.play();
            pendulum.setLoop(true);
            gametype = vshuman(window,rectangle,button,pause);
        }
        window.clear();
         if (gametype==1)
        displaytext(window,"player1 wins",300,200,font,150,255);
        else if (gametype==2)
        displaytext(window,"player1 wins",300,200,font,150,255);
        window.display();
        while(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
        }
        window.clear();
        gametype=4;
    }

}
