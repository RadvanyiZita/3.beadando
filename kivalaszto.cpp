#include "graphics.hpp"
#include "kivalaszto.hpp"
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace genv;

_lista::_lista(vector<string> elemek)
{
    items = elemek;
    itemindex = 0;
    lX = 0;
    lY = 0;
    height = 12;
    width = 100;
    topitemindex = 0;
    maxitem = 5;
    fontmeret = 12;
    font = "LiberationSans-Regular.ttf";
    _lenyitva = false;
    sormagassag = gout.cascent()+gout.cdescent();
    focus = false;
    gorgetes = false;
}

int _lista::Get_lX()
    {
        return lX;
    }

void _lista::Set_lX(int x)
    {
        lX = x;
    }

int _lista::Get_lY()
    {
        return lY;
    }

void _lista::Set_lY(int y)
    {
        lY = y;
    }

int _lista::Get_height()
    {
        return height;
    }

void _lista::Set_height(int Height)
    {
        height = Height;
    }

int _lista::Get_width()
    {
        return width;
    }

void _lista::Set_width(int Width)
    {
        width = Width;
    }

void _lista::Set_Items(vector<string> elemek)
    {
        items = elemek;
    }

void _lista::Set_maxitem(int Maxitem)
    {
        // számoljuk ki a maxitem értékét a lista elemei alapján
        maxitem = Maxitem;
    }

int _lista::Get_maxitem()
    {
        return maxitem;
    }

bool _lista::Get_lenyitva()
    {
        return _lenyitva;
    }

void _lista::Rajzol()
    {
        height = maxitem * sormagassag+4;
        if (gorgetes)
        {
                gout << color(255, 255, 255) << move_to(lX, lY)
             << box_to(lX+width, lY+height)
             << color(100, 100, 100) << move_to(lX+1, lY+1)
             << box_to(lX+width-2, lY+height-2);
              _lenyitva = true;
             gout << refresh;
        }
        else
        {
            if (!_lenyitva)
            {
                gout << color(255, 255, 255) << move_to(lX, lY)
             << box_to(lX+width, lY+height)
             << color(100, 100, 100) << move_to(lX+1, lY+1)
             << box_to(lX+width-2, lY+height-2);
              _lenyitva = true;
             gout << refresh;
            }
            else
            {
              _lenyitva = false;
               gout << color(0, 0, 0) << move_to(lX, lY)
             << box_to(lX+width, lY+height);

             gout << refresh;
            }
        }


    }

void _lista::intoItems()
    {

        int fh = 0;
        if (items.size()-topitemindex  > maxitem)
        {
            fh = maxitem;
        }
        else
        {
            fh = items.size() - topitemindex;
        }
        if (!_lenyitva)
        {
            r=0;
            g=0;
            b=0;
        }
        else
        {
            r=255;
            g=255;
            b=255;
        }
        for (int i=topitemindex; i < topitemindex+fh; i++)
        {
                gout << color(r,g,b) << move_to(lX+2, lY+(i-topitemindex)*sormagassag+3) << text(items[i]);
        }

    }
//****************************************************

beviteliEX::beviteliEX(int x, int y, vector<string> elemek): _lista(elemek)
    {
        posX = x;
        posY = y;
       // list_items = elemek;
        Text = "";
        fontmeret = 12;
        font = "LiberationSans-Regular.ttf";
        bevheight = 15;
        bevwidth = 100;
        tok = 0;
    }

bool beviteliEX::Focused()
    {
      return focus;
    }
bool beviteliEX::Get_nyitva()
    {
      //  return Lista.Get_lenyitva();
    }
void beviteliEX::Set_list_items(vector<string> items)
    {
     //   list_items = items;
    }
void beviteliEX::rajzol()
    {
        r = 220;
        g = 220;
        b = 220;

        gout << move_to(0,0) << color(r, g, b) << move_to(posX, posY)
             << box_to(posX+bevwidth, posY+bevheight) <<
             move_to(posX+bevwidth, posY) << color(r, 3*g/4, b) << box_to(posX+bevwidth+bevheight, posY+bevheight);

        gout << color(0,0,0) << move_to(posX+bevwidth+bevheight/4, posY+bevheight/5) << line_to(posX+bevwidth+3*bevheight/4, posY+bevheight/5) <<
            line_to(posX+bevwidth+bevheight/2, posY+4*bevheight/5) << line_to(posX+bevwidth+bevheight/4, posY+bevheight/5);

        //listaRajzol();
    }
void beviteliEX::listaRajzol()
    {
        Set_lX(posX);
        Set_lY(posY+bevheight);
        Set_height(Get_maxitem()*bevheight);
        Set_width(bevwidth);
        Set_Items(items);

        Rajzol();
        intoItems();
    }


void beviteliEX::Set_bevwidth(int w)
    {
        bevwidth = w;
    }
void beviteliEX::Set_bevheigth(int h)
    {
        bevheight = h;
    }
void beviteliEX::TextKiir()
    {
        string s = Text;
        gout << color(0,0,0);
        gout << move_to(posX, posY);
        gout << text(s);
    }
string beviteliEX::Get_Text()
    {
        return Text;
    }
void beviteliEX::TextTorol()
    {
       rajzol();
    }
int beviteliEX::rajtavan_listaelemen(int ex, int ey)
    {
        int hatar = 0;
        int box1x = 0;
        int box1y = 0;
        int box2x = 0;
        int box2y = 0;
        itemindex = -1;
        if (items.size() <= maxitem)
        {
            hatar = items.size();
        }
        else
        {
            hatar  = maxitem;
        }
        for (int i=0; i < hatar; i++)
        {
            box1x = lX;
            box2x = lX+width;
            box1y = lY+sormagassag*i;
            box2y = lY+sormagassag*(i+1)+2;
            if(ex<=box2x && ex>=box1x && ey<=box2y && ey>=box1y)
            {
                itemindex = i+topitemindex;
                Text = items[itemindex];
                TextTorol();
                TextKiir();
            }
        }
    }
bool beviteliEX::rajtavan_lenyiton(int ex, int ey)
    {
        int box1x = posX+bevwidth;
        int box1y = posY;
        int box2x = posX+bevwidth+bevheight;
        int box2y = posY+bevheight;
        bool rajta=false;
        if(ex<=box2x && ex>=box1x && ey<=box2y && ey>=box1y)
        {
            rajta=true;
        }
        return rajta;
    }
bool beviteliEX::rajtavanlistan(int ex,int ey)
    {
        int box1x = lX;
        int box1y = lY;
        int box2x = lX+width;
        int box2y = lY+height;
        bool rajta=false;
        if(ex<=box2x && ex>=box1x && ey<=box2y && ey>=box1y)
        {
            rajta=true;
        }
        return rajta;
    }

void beviteliEX::handle(genv::event e)
    {
        if (rajtavan_lenyiton(e.pos_x, e.pos_y) && e.button == btn_left)
        {
            gorgetes = false;
            listaRajzol();
        }

        if (e.button == btn_left)
        {
            gorgetes = false;
            focus = rajtavanlistan(e.pos_x, e.pos_y) || rajtavan_lenyiton(e.pos_x, e.pos_y) ;
            itemindex = rajtavan_listaelemen(e.pos_x, e.pos_y);

        }
        if (focus && e.button == btn_wheeldown)
        {
            gorgetes = true;
            topitemindex++;

            if (topitemindex > items.size()) topitemindex = items.size();
            listaRajzol();

        }
        if (focus && e.button == btn_wheelup)
        {
            gorgetes = true;
            topitemindex--;
            if (topitemindex < 0) topitemindex = 0;
            listaRajzol();
        }
//

    }

bool beviteliEX::rajtavan(int box1x, int box1y,int box2x, int box2y, int ex, int ey)
{
    bool rajta=false;
    if(ex<=box2x && ex>=box1x && ey<=box2y && ey>=box1y)
    {
        rajta=true;
    }
    return rajta;
}
