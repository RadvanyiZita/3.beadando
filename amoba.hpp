#ifndef AMOBA_HPP_INCLUDED
#define AMOBA_HPP_INCLUDED
#include <string>

using namespace std;

struct elem{
protected:
    int x0,y0,height, width,allapot;
public:
   elem(int x, int y, int H, int W, int state);
};

class Jatekter
{
protected:
    int XX,YY,panelheight;
    string aktuals;
       int meret;

public:
    Jatekter(int xx,int yy, int panelh);
    void kirajzol();
    void startmenu();
    void panelrajz();
    void elemrajz();
    void lepesrajz();
    void uzenet();

};

class Jatekmester:Jatekter
{
public:

    static Jatekter& instace();
    Jatekmester(int xx,int yy, int panelh);
    bool rajtavanboxon(int ex, int ey,int bx0,int by0, int bx1, int by1);
    bool szabalyose();
    bool nyerte();
    void run();

};



#endif // AMOBA_HPP_INCLUDED
