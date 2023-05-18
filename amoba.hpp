#ifndef AMOBA_HPP_INCLUDED
#define AMOBA_HPP_INCLUDED
#include <string>

using namespace std;

struct elem{

    int x0,y0,height, width,allapot;

 //  elem(int x, int y, int H, int W, int state);
};

class Jatekter
{
protected:
    int XX,YY,panelheight,xkezd,ykezd,szel;
    string aktuals;
       int meret;
       elem ter[30][30];

public:
    Jatekter(int xx,int yy, int panelh);
    void kirajzol();
    void startmenu();
    void panelrajz();
    bool rajtavanboxon(int ex, int ey,int bx0,int by0, int bx1, int by1);
    void elemrajz();
    void lepesrajz(int i, int j);
    void uzenet();

};

class Jatekmester:Jatekter
{
public:

    static Jatekter& instace();
    Jatekmester(int xx,int yy, int panelh);
    bool szabalyose(int ex,int ey);
    bool nyerte(int i, int j);
    void run();

};



#endif // AMOBA_HPP_INCLUDED
