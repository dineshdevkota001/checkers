#include"versushuman.h"

bool ispossible(int ix,int iy,int board[][8])
{
    int type=board[ix][iy];
    int var=type%2;
    iy=abs(7*var-iy);

    if (ix+2<8&&iy+2<8&&board[ix+2][iy+2]==0&&(board[ix+1][iy+1]==1+var||board[ix+1][iy+1]==1+var)) return true;
    else if (ix+2<8&&iy+2<8&&board[ix-2][iy+2]==0&&(board[ix-1][iy+1]==1+var||board[ix-1][iy+1]==1+var)) return true;
    else if ((type==3||type==4)&&ix+2<8&&iy+2<8&&board[ix+2][iy-2]==0&&(board[ix+1][iy-1]==1+var||board[ix+1][iy-1]==3+var)) return true;
    else if ((type==3||type==4)&&ix+2<8&&iy+2<8&&board[ix-2][iy-2]==0&&(board[ix-1][iy-1]==1+var||board[ix-1][iy-1]==3+var)) return true;
    else return false;

}

int vshuman(sf::RenderWindow &window,sf::RectangleShape &rectangle,sf::RectangleShape &button,sf::Sprite &thumbnail)
{
    int i,j,pause=0,turn=0,variable,movevar=1,player1,movetype=1,win=1;
    int boardstate[8][8];
    sf::Texture board_texture,men_texture;
    sf::Sprite board,men;
    sf::Event event;
    sf::Font font;
    assert(font.loadFromFile("fonts/calibri.ttf"));

    assert(board_texture.loadFromFile("images/board.png"));
    assert(men_texture.loadFromFile("images/men.png"));

    int initial_boardstate[8][8]= { 2,5,2,5,2,5,2,5,
                                    5,2,5,2,5,2,5,2,
                                    2,5,2,5,2,5,2,5,
                                    5,0,5,0,5,0,5,0,
                                    0,5,0,5,0,5,0,5,
                                    5,1,5,1,5,1,5,1,
                                    1,5,1,5,1,5,1,5,
                                    5,1,5,1,5,1,5,1 };

    for (i=0; i<8; i++)                 ///initial board condition
    {
        for (j=0; j<8; j++)
        {
            boardstate[i][j]=initial_boardstate[i][j];
        }
    }

    men_texture.setSmooth(true);

    board.setTexture(board_texture);
    board.setPosition(299,0);
    men.setTexture(men_texture);
    sf::Vector2i position,initial_position,final_position;


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
        else if (turn==-1) {if (exit(window,button,font,board)) window.close();}
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
    player1=turn;




    while (window.isOpen())
    {
        win=1;
            while (window.pollEvent(event))
            {
                if (event.type==sf::Event::Closed)  window.close();
            }
            variable=turn%2;
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
                    else if (movevar==2||movevar==3)
                    {
                        if (((boardstate[position.x][position.y])==2-variable||(boardstate[position.x][position.y])==4-variable)&&movevar==2)
                        {
                            initial_position=position;
                        }
                        else if ((boardstate[position.x][position.y])==0)
                        {
                            switch (islegal(initial_position.x,initial_position.y,position.x,position.y,boardstate))
                            {
                                case 1:
                                {
                                    if (movetype!=1) break;
                                    final_position=position;
                                    boardstate[final_position.x][final_position.y]=boardstate[initial_position.x][initial_position.y];
                                    if (abs(7*variable-final_position.x)==7) boardstate[final_position.x][final_position.y]=4-variable;
                                    boardstate[initial_position.x][initial_position.y]=0;
                                    turn++;
                                    animation(window);
                                    movevar=1;
                                    break;
                                }
                                case 2:
                                {
                                    movetype=2;
                                    movevar=3;
                                    final_position=position;
                                    boardstate[final_position.x][final_position.y]=boardstate[initial_position.x][initial_position.y];
                                    if (abs(7*variable-final_position.x)==7) boardstate[final_position.x][final_position.y]=4-variable;
                                    boardstate[initial_position.x][initial_position.y]=0;
                                    initial_position=final_position;
                                    if (!ispossible(initial_position.x,initial_position.y,boardstate))
                                    {
                                        turn++;
                                        animation(window);
                                        movevar=1;
                                        movetype=1;
                                    }
                                    break;
                                }
                                default: break;
                            }
                        }
                    }
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)&&movetype==2)
            {
                turn++;
                animation(window);
                movevar=1;
                movetype=1;
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

                for (j=0; j<8; j++)
                {
                for (i=0; i<8; i++)
                {
                    if (boardstate[i][j]==2-variable||boardstate[i][j]==4-variable)
                    {
                        if (!ispossible(i,j,boardstate))
                        {
                            win=0;
                            break;
                        }
                    }
                }
                }

            if (win==1&&2-variable==player1) return 2;
            else if (win==1&&2-variable!=player1) return 1;

    }
}
