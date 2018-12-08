#include<SFML/Graphics.hpp>
sf::Vector2f returnscreenvector(sf::Vector2i &position)
{
        sf::Vector2f pos;
        if (position.y==0)
        {
            pos.y=517;
            if (position.x==0) pos.x=365;
            else if (position.x==1) pos.x=443;
            else if (position.x==2) pos.x=522;
            else if (position.x==3) pos.x=603;
            else if (position.x==4) pos.x=687;
            else if (position.x==5) pos.x=768;
            else if (position.x==6) pos.x=851;
            else if (position.x==7) pos.x=933;
        }
        else if (position.y==1)
        {
            pos.y=459;
            if (position.x==0) pos.x=385;
            else if (position.x==1) pos.x=459;
            else if (position.x==2) pos.x=534;
            else if (position.x==3) pos.x=609;
            else if (position.x==4) pos.x=687;
            else if (position.x==5) pos.x=763;
            else if (position.x==6) pos.x=841;
            else if (position.x==7) pos.x=917;
        }
        else if (position.y==2)
        {
            pos.y=410;
            if (position.x==0) pos.x=403;
            else if (position.x==1) pos.x=473;
            else if (position.x==2) pos.x=543;
            else if (position.x==3) pos.x=614;
            else if (position.x==4) pos.x=686;
            else if (position.x==5) pos.x=758;
            else if (position.x==6) pos.x=832;
            else if (position.x==7) pos.x=902;
        }
        else if (position.y==3)
        {
            pos.y=362;
            if (position.x==0) pos.x=419;
            else if (position.x==1) pos.x=485;
            else if (position.x==2) pos.x=550;
            else if (position.x==3) pos.x=617;
            else if (position.x==4) pos.x=685;
            else if (position.x==5) pos.x=754;
            else if (position.x==6) pos.x=822;
            else if (position.x==7) pos.x=888;
        }
        else if (position.y==4)
        {
            pos.y=321;
            if (position.x==0) pos.x=435;
            else if (position.x==1) pos.x=497;
            else if (position.x==2) pos.x=559;
            else if (position.x==3) pos.x=621;
            else if (position.x==4) pos.x=685;
            else if (position.x==5) pos.x=750;
            else if (position.x==6) pos.x=814;
            else if (position.x==7) pos.x=877;
        }
        else if (position.y==5)
        {
            pos.y=284;
            if (position.x==0) pos.x=448;
            else if (position.x==1) pos.x=506;
            else if (position.x==2) pos.x=565;
            else if (position.x==3) pos.x=625;
            else if (position.x==4) pos.x=686;
            else if (position.x==5) pos.x=747;
            else if (position.x==6) pos.x=806;
            else if (position.x==7) pos.x=867;
            pos.x=pos.x+3;
        }
        else if (position.y==6)
        {
            pos.y=250;
            if (position.x==0) pos.x=462;
            else if (position.x==1) pos.x=515;
            else if (position.x==2) pos.x=572;
            else if (position.x==3) pos.x=631;
            else if (position.x==4) pos.x=687;
            else if (position.x==5) pos.x=746;
            else if (position.x==6) pos.x=803;
            else if (position.x==7) pos.x=860;
            pos.x=pos.x+2;
        }
        else if (position.y==7)
        {
            pos.y=222;
            if (position.x==0) pos.x=474;
            else if (position.x==1) pos.x=525;
            else if (position.x==2) pos.x=581;
            else if (position.x==3) pos.x=636;
            else if (position.x==4) pos.x=689;
            else if (position.x==5) pos.x=745;
            else if (position.x==6) pos.x=800;
            else if (position.x==7) pos.x=853;
            pos.x=pos.x+3;
        }
        else
        {
            pos.y=200;
            pos.x=100;
        }
        return pos;
}
