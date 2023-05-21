#include "szamlalo.hpp"
#include "graphics.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace genv;

Postit::Postit(int x0, int y0,int sx0,int sy0):widget(x0, y0, sx0, sy0)
{
        sx = sx0;
        sy = sy0;
        x = x0;;
        y = y0;
        v = 20;
        fokusz=false;
}

void Postit::rajzol()
{
    gout << color(255, 255, 255) << move_to(x, y)
             << box(sx, sy)
             << color(100, 100, 100) << move_to(x+2, y+2)
             << box(sx-4, sy-4);
}

Number::Number ( int x0, int y0,int sx0,int sy0, int boxszel0):Postit(x0,y0,sx0,sy0){
        boxszel=boxszel0;
        boxmag=sy0/2;
        minvalue=15;
        maxvalue=30;

}
void Number::rajzol()
{
    string plusz="+";
    string minusz="-";
    gout << color(255, 255, 255) << move_to(x, y)
             << box(sx, sy)
             << color(100, 100, 100) << move_to(x+2, y+2)
             << box(sx-4, sy-4);
        string s = to_string(v);
        gout << color(255, 255, 255) << move_to(2+x+sx/2-gout.twidth(s)/2,
                2+y+sy/2-(gout.cascent()+gout.cdescent())/2)    << text(s)
                << move_to(x+sx,y) << color(175, 238,238)<< box(boxszel,boxmag)<< color(0,0,0)
                << move_to(x+sx+boxszel/2-5,y+boxmag/4)<< text(plusz)<<
                move_to(x+sx,y+boxmag) <<color(255,218,185)<< box(boxszel,boxmag)<<
                move_to(x+sx,y+boxmag)<< color(0,0,0) << line(boxszel,0)<< move_to(x+sx+boxszel/2-3,y+boxmag+5)
                << text(minusz);
}

bool Number::rajtavanboxon(int ex, int ey)
    {
        bool rajta=false;
        int bx1=x;
        int bx2=x+sx+boxszel;
        int by1=y;
        int by2=y+sy;
        if(bx1<=ex && bx2>=ex && by1 <=ey&& by2 >=ey)
        {
            rajta=true;
        }
        return rajta;
    }

void Number::handle(genv::event ev){
        if(ev.button==btn_left )
        {

            fokusz = rajtavanboxon(ev.pos_x, ev.pos_y);
            if(ev.pos_x >= x+sx && ev.pos_y >= y && ev.pos_x < x+sx+boxszel && ev.pos_y < y + sy/2)
            {
                if(v<maxvalue)
                {
                    v++;
                }

            }
            if(ev.pos_x >= x+sx && ev.pos_y >= y+ sy/2 && ev.pos_x < x+sx+boxszel && ev.pos_y < y + sy)
            {
                if(v>minvalue)
                {
                    v--;
                }

            }
        }
        if(fokusz && ev.keycode==key_up ){
            if(v<maxvalue)
                {
                    v++;
                }
        }
        if(fokusz && ev.keycode==key_down){
           if(v>minvalue)
                {
                    v--;
                }
        }
         if(fokusz && ev.keycode==key_pgup){
                if(v<maxvalue-10)
                {
                    v=v+10;
                }

        }
        if(fokusz && ev.keycode==key_pgdn){
                if(v>minvalue+10)
                {
                    v=v-10;
                }

        }
        rajzol();
    }

    int Number::Getvalue()
    {
        return v;
    }

bool Number::felette(int ex, int ey){
        return (ex >= x+sx && ey >= y && ex < x+sx+boxszel && ey < y + sy);

    }
bool Number::focused(){
    return fokusz;
}
