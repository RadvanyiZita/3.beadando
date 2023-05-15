#include <iostream>
#include "amoba.hpp"
#include "graphics.hpp"
#include "kivalaszto.hpp"
#include "szamlalo.hpp"
#include <ctime>
#include <vector>
#include <fstream>
#include <string>

using namespace genv;
using namespace std;


 elem::elem(int x, int y, int H, int W, int state)
    {
        x0=x;
        y0=y;
        height=H;
        width=W;
        allapot=state;
    }


Jatekter::Jatekter(int xx,int yy, int panelh, int darab)
{
    XX=xx;
    YY=yy;
    panelheight=panelh;
    db=darab;

}
void Jatekter::kirajzol()
{
   gout.open(XX,YY);
   gout << font("LiberationSans-Regular.ttf",14);
   gout<< refresh;

}

void Jatekter::startmenu()
{
    gout << move_to(0,0)<< color(100,100,100)<<box(XX,panelheight)
    << move_to(50,30)<< color(255,255,255)<< text("Válassz jelet:")<<
    move_to(400,30)<< text("A pálya mérete:")<<
    move_to(650,30)<< color(0,255,0)<< box(100,50)<< move_to(680,50)<<
    color(0,0,0)<< text("START");

}

void Jatekter::panelrajz()
{
    gout << move_to(0,0)<< color(253,179,223)<<box(XX,panelheight);



}
void Jatekter::elemrajz()
{

}
void Jatekter::lepesrajz()
{

}
void Jatekter::uzenet()
{

}



    Jatekmester::Jatekmester(int xx,int yy, int panelh, int darab):Jatekter(xx, yy,  panelh, darab)
    {

    }
    bool Jatekmester::szabalyose()
    {

    }
    bool Jatekmester::nyerte()
    {

    }

    void Jatekmester::run()
    {
       kirajzol();
       event ev;
       Number n1 = Number(550,30,50,40,30);
       vector<string> jelek;
       jelek.push_back("X");
       jelek.push_back("O");
       beviteliEX jel=beviteliEX(200,30,jelek);
        startmenu();
       jel.rajzol();
       n1.rajzol();
       while(gin >> ev && ev.keycode != key_escape)
       {

           jel.handle(ev);
           n1.handle(ev);

           gout << refresh;
       }
    }


