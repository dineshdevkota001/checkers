#include<SFML/Window/Mouse.hpp>

int getmouseposition()
{
    int x,y;
    x=sf::Mouse::getPosition().x;
    y=sf::Mouse::getPosition().y;
    if (x>914&&x<1356&&y<758&&y>508) return 2;
    else if (x>462&&x<904&&y<758&&y>508) return 3;
    else if (x>10&&x<452&&y<758&&y>508) return 4;
    else if (x>1346&&x<1366&&y<20&&y>0) return 0;
    else return 1;

}
sf::Vector2i getboardvector()
{
    int m,n,r;
    m=sf::Mouse::getPosition().x;
    n=sf::Mouse::getPosition().y;
    if (n<580&&n>517)
        {
            if (m>365&&m<443) r=0;
            else if (m>443&&m<522) r=1;
            else if (m>522&&m<603) r=2;
            else if (m>603&&m<687) r=3;
            else if (m>687&&m<768) r=4;
            else if (m>768&&m<851) r=5;
            else if (m>851&&m<933) r=6;
            else if (m>933&&m<1010) r=7;
            else r=64;
        }
        else if (n<517&&n>459)
        {
            if (m>385&&m<459) r=8;
            else if (m>459&&m<534) r=9;
            else if (m>534&&m<609) r=10;
            else if (m>609&&m<687) r=11;
            else if (m>687&&m<763) r=12;
            else if (m>763&&m<841) r=13;
            else if (m>841&&m<917) r=14;
            else if (m>917&&m<990) r=15;
            else r=64;
        }
        else if (n<459&&n>410)
        {
            if (m>403&&m<473) r=16;
            else if (m>473&&m<543) r=17;
            else if (m>543&&m<614) r=18;
            else if (m>614&&m<686) r=19;
            else if (m>686&&m<758) r=20;
            else if (m>758&&m<832) r=21;
            else if (m>832&&m<902) r=22;
            else if (m>902&&m<968) r=23;
            else r=64;
        }
        else if (n<410&&n>362)
        {
            if (m>419&&m<485) r=24;
            else if (m>485&&m<550) r=25;
            else if (m>550&&m<617) r=26;
            else if (m>617&&m<685) r=27;
            else if (m>685&&m<754) r=28;
            else if (m>754&&m<822) r=29;
            else if (m>822&&m<888) r=30;
            else if (m>888&&m<950) r=31;
            else r=64;
        }
        else if (n<362&&n>321)
        {
            if (m>435&&m<497) r=32;
            else if (m>497&&m<559) r=33;
            else if (m>559&&m<621) r=34;
            else if (m>621&&m<685) r=35;
            else if (m>685&&m<750) r=36;
            else if (m>750&&m<814) r=37;
            else if (m>814&&m<877) r=38;
            else if (m>877&&m<936) r=39;
            else r=64;
        }
        else if (n<321&&n>284)
        {
            if (m>448&&m<506) r=40;
            else if (m>506&&m<565) r=41;
            else if (m>565&&m<625) r=42;
            else if (m>625&&m<686) r=43;
            else if (m>686&&m<747) r=44;
            else if (m>747&&m<806) r=45;
            else if (m>806&&m<867) r=46;
            else if (m>867&&m<922) r=47;
            else r=64;
        }
        else if (n<284&&n>250)
        {
             if (m>462&&m<515) r=48;
            else if (m>515&&m<572) r=49;
            else if (m>572&&m<631) r=50;
            else if (m>631&&m<687) r=51;
            else if (m>687&&m<746) r=52;
            else if (m>746&&m<803) r=53;
            else if (m>803&&m<860) r=54;
            else if (m>860&&m<912) r=55;
            else r=64;
        }
        else if (n<250&&n>222)
        {
            if (m>474&&m<525) r=56;
            else if (m>525&&m<581) r=57;
            else if (m>581&&m<636) r=58;
            else if (m>636&&m<689) r=59;
            else if (m>689&&m<745) r=60;
            else if (m>745&&m<800) r=61;
            else if (m>800&&m<853) r=62;
            else if (m>853&&m<902) r=63;
            else r=64;
        }
        else r=64;
        return sf::Vector2i(r/8,r%8);
}
