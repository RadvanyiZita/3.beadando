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


// elem::elem(int x, int y, int H, int W, int state)
//    {
//        x0=x;
//        y0=y;
//        height=H;
//        width=W;
//        allapot=state;
//    }


Jatekter::Jatekter(int xx,int yy, int panelh)
{
    XX=xx;
    YY=yy;
    panelheight=panelh;
    meret=0;
    aktuals="";
    xkezd=0;
    ykezd=0;
    szel=0;

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
    << move_to(50,30)<< color(255,255,255)<< text("Valassz jelet:")<<
    move_to(400,30)<< text("A palya merete:")<<
    move_to(650,30)<< color(0,255,0)<< box(100,50)<< move_to(680,50)<<
    color(0,0,0)<< text("START");

}

void Jatekter::panelrajz()
{
    gout << move_to(0,0)<< color(253,179,223)<<box(XX,panelheight)<<
    move_to(50,30)<< color(0,0,0)<< text("A kovetkezo jatekos:");

}
bool Jatekter::rajtavanboxon(int ex, int ey,int bx0,int by0, int bx1, int by1)
    {
        bool rajta=false;
        if(bx0<=ex && bx1>=ex && by0 <=ey&& by1 >=ey)
        {
            rajta=true;
        }
        return rajta;
    }
void Jatekter::elemrajz()
{
    szel=(YY-panelheight)/meret;
    xkezd=((int)(XX-szel*meret)/2.0);
    ykezd=panelheight;
//    cout << szel << " "<< xkezd<<endl;

    for(int i=0;i<meret;i++)
    {
        for(int j=0;j<meret;j++)
        {
            ter[i][j].x0=xkezd+i*szel;
            ter[i][j].y0=ykezd+j*szel;
            ter[i][j].height=szel;
            ter[i][j].width=szel;
            ter[i][j].allapot=0;

            gout<< move_to(ter[i][j].x0,ter[i][j].y0)<< color(255,255,255)<<
            line_to(ter[i][j].x0+szel,ter[i][j].y0)
            << line_to(ter[i][j].x0+szel,ter[i][j].y0+szel)<<line_to(ter[i][j].x0,ter[i][j].y0+szel)
            <<line_to(ter[i][j].x0,ter[i][j].y0);
        }
    }
}
void Jatekter::lepesrajz(int i, int j)
{
    gout << font("LiberationSans-Regular.ttf",2*szel/3);
    if(aktuals=="X")
    {
        ter[i][j].allapot=1;
        aktuals="O";
        gout << move_to(ter[i][j].x0+szel/6,ter[i][j].y0+szel/6)<<color(255,255,255)<<
        text("X");
    }
    else
    {
        aktuals="X";
        ter[i][j].allapot=2;
        gout << move_to(ter[i][j].x0+szel/6,ter[i][j].y0+szel/6)<<color(255,255,255)<< text("O");
    }

}
void Jatekter::uzenet()
{

}



    Jatekmester::Jatekmester(int xx,int yy, int panelh):Jatekter(xx, yy,  panelh)
    {

    }

    bool Jatekmester::szabalyose(int ex,int ey)
    {
        for(int i=0;i<meret;i++)
    {
        for(int j=0;j<meret;j++)
        {
            if(rajtavanboxon(ex,ey,ter[i][j].x0,ter[i][j].y0,ter[i][j].x0+szel,ter[i][j].y0+szel))
            {
                if(ter[i][j].allapot==0)
                {
                    lepesrajz(i, j);
                    nyerte(i,j);
                }

            }
        }
    }
    }

    bool Jatekmester::nyerte(int i, int j)
    {
        int mini=0;
        int maxi=meret;
        int minj=0;
        int maxj=meret;
        int szorzat=1;
        bool vannyert=false;

        if(i-4<0) mini=0;
        else mini=i-4;

        if(i+4>meret)maxi=meret;
        else maxi=i+4;

 //       cout << mini << " " << maxi << endl;

        int ah=mini;
        int fh=mini+4;

        while(fh<=maxi && !vannyert)
        {
            szorzat=1;
            for(int k=ah; k<=fh; k++)
            {
                szorzat=szorzat*ter[k][j].allapot;
  //              cout << szorzat<< endl;
            }
            ah++;
            fh++;
            vannyert=((szorzat==1) || (szorzat==32));

        }


        if(j-4<0) mini=0;
        else mini=j-4;

        if(j+4>meret)maxi=meret;
        else maxi=j+4;
        ah=mini;
        fh=mini+4;

        while(fh<=maxi && !vannyert)
        {
            szorzat=1;
            for(int k=ah; k<=fh; k++)
            {
                szorzat=szorzat*ter[i][k].allapot;
  //              cout << szorzat<< endl;
            }
            ah++;
            fh++;
            vannyert=((szorzat==1) || (szorzat==32));
        }



        if(i-4<0) mini=0;
        else mini=i-4;

        if(i+4>meret)maxi=meret;
        else maxi=i+4;

        if(j-4<0) minj=0;
        else minj=j-4;

        if(j+4>meret)maxj=meret;
        else maxj=j+4;

        if(mini<minj) ah=mini;
        else ah=minj;
        fh=ah+4;


       while(fh<=maxi && !vannyert)
        {
            szorzat=1;
            for(int k=ah; k<=fh; k++)
            {
                szorzat=szorzat*ter[k][k].allapot;
  //              cout << szorzat<< endl;
            }
            ah++;
            fh++;
            vannyert=((szorzat==1) || (szorzat==32));

        }


        if(i-4<0) mini=0;
        else mini=i-4;

        if(i+4>meret)maxi=meret;
        else maxi=i+4;

        if(j-4<0) minj=0;
        else minj=j-4;

        if(j+4>meret)maxj=meret;
        else maxj=j+4;

        if(mini<minj) ah=mini;
        else ah=minj;
        fh=ah+4;

        while(fh<=maxi && !vannyert)
        {
            szorzat=1;
            for(int k=ah; k<=fh; k++)
            {
                szorzat=szorzat*ter[fh-k+ah][k].allapot;
               // cout << szorzat<< endl;
            }
            ah++;
            fh++;
            vannyert=((szorzat==1) || (szorzat==32));

        }





        if(vannyert)
        {
            cout << "nyert" <<endl;
        }


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
       jel.Set_maxitem(2);
        startmenu();
       jel.rajzol();
       n1.rajzol();
        bool valaszt=true;
        bool megye=false;
       while(gin >> ev && ev.keycode != key_escape)
       {
            if(valaszt)
            {
                jel.handle(ev);
                n1.handle(ev);

            }

           if(ev.button==btn_left && rajtavanboxon(ev.pos_x,ev.pos_y,650,30,750,80))
           {
               valaszt=false;
               aktuals=jel.Get_Text();
               meret=n1.Getvalue();
               panelrajz();
               elemrajz();
               megye=true;
     //          cout << meret<< aktuals<< endl;
           }
           if(ev.button==btn_left && megye && rajtavanboxon(ev.pos_x,ev.pos_y,xkezd,ykezd,xkezd+szel*meret,ykezd+szel*meret))
            {
                szabalyose(ev.pos_x,ev.pos_y);
            }

           gout << refresh;
       }
    }


