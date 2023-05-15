#ifndef AMOBA_HPP_INCLUDED
#define AMOBA_HPP_INCLUDED

struct elem{
protected:
    int x0,y0,height, width,allapot;
public:
   elem(int x, int y, int H, int W, int state);
};

class Jatekter
{
protected: int XX,YY,panelheight, db;

public:
    Jatekter(int xx,int yy, int panelh, int darab);
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
    Jatekmester(int xx,int yy, int panelh, int darab);
    bool szabalyose();
    bool nyerte();
    void run();

};



#endif // AMOBA_HPP_INCLUDED
