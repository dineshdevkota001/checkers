#include"versuscomputer.h"

int vscomputer(sf::RenderWindow &window,sf::RectangleShape &rectangle,sf::RectangleShape &button,sf::Sprite &thumbnail)
{
    sf::Texture board_texture,men_texture;
    sf::Sprite board,men;
    sf::Event event;
    sf::Font font;


    assert(font.loadFromFile("fonts/calibri.ttf"));
    int initial_boardstate[8][8]= { 2,5,2,5,2,5,2,5,
                                    5,2,5,2,5,2,5,2,
                                    2,5,2,5,2,5,2,5,
                                    5,0,5,0,5,0,5,0,
                                    0,5,0,5,0,5,0,5,
                                    5,1,5,1,5,1,5,1,
                                    1,5,1,5,1,5,1,5,
                                    5,1,5,1,5,1,5,1 };

    int i,j,pause=0;
    int boardstate[8][8];
    for (i=0; i<8; i++)                 ///initial board condition
    {
        for (j=0; j<8; j++)
        {
            boardstate[i][j]=initial_boardstate[i][j];
        }
    }
    assert(board_texture.loadFromFile("images/board.png"));
    assert(men_texture.loadFromFile("images/men.png"));

    men_texture.setSmooth(true);

    board.setTexture(board_texture);
    board.setPosition(299,0);
    men.setTexture(men_texture);
    sf::Vector2i position,initial_position,final_position;
    int movevar=1,turn=0,variable=1;

     while (window.isOpen())
    {
        if (turn==0){
        while (window.pollEvent(event))
        {
            if (event.type==sf::Event::Closed)  window.close();
        }
        window.draw(board);
        window.draw(rectangle);
        selectionscreen(window,font,button,men);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) turn=getmouseposition()-1;
        window.display();
        window.clear();
        }
        else if (turn==-1) window.close();
        else if (turn==3)
        {
            turn=2;
            break;
        }
        else if (turn==2)
        {
            turn = 0;
        }
        else break;

    }
    variable=turn%2;
    while (window.isOpen())
    {
            while (window.pollEvent(event))
            {
                if (event.type==sf::Event::Closed)  window.close();
            }

            window.clear(sf::Color(230-230*variable,230-230*variable,230-230*variable));
            window.draw(board);
            for (j=0; j<8; j++)
            {
                for (i=0; i<8; i++)
                {
                    position.x=abs(7*variable-j);
                    position.y=abs(7*variable-i);
                    displaymen(window,men,boardstate[i][j],position);
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                position=getboardvector();
                if (position.y!=8)
                {
                    position.x=abs(7*variable-position.x);
                    position.y=abs(7*variable-position.y);
                    if (movevar==1)
                    {
                        if ((boardstate[position.x][position.y])==2-variable||(boardstate[position.x][position.y])==4-variable)
                        {
                            initial_position=position;
                            movevar=2;
                        }
                    }
                    else if (movevar==2)
                    {
                        if ((boardstate[position.x][position.y])==2-variable||(boardstate[position.x][position.y])==4-variable)
                        {
                            initial_position=position;
                        }
                        else if ((boardstate[position.x][position.y])==0)
                        {
                            movevar=1;
                            final_position=position;
                            boardstate[final_position.x][final_position.y]=boardstate[initial_position.x][initial_position.y];
                            boardstate[initial_position.x][initial_position.y]=0;
                            animation(window);
                        }

                    }
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))    pause=1;

            while (pause!=0)
            {
                window.clear();
                while (window.pollEvent(event))
                {
                    if (event.type==sf::Event::Closed)  window.close();
                }
                window.draw(board);
                switch(pausemenu(window,font,rectangle,button,thumbnail))
                {
                case 2:
                {
                    pause=0;
                    break;
                }
                case 3:
                {
                    if (exit(window,button,font,board)) window.close();
                    else break;
                }
                case 4:
                    return 4;
                default:
                    break;
                }
                window.display();
            }
            window.display();
    }
    return 0;
}
