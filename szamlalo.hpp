#ifndef SZAMLALO_HPP_INCLUDED
#define SZAMLALO_HPP_INCLUDED
#include "graphics.hpp"


class Postit{
protected:
    int x, y, sx, sy;
    int v;
    bool fokusz;
    int minvalue, maxvalue;
public:
    Postit(int x0, int y0,int sx0,int sy0);
   virtual void rajzol();

};

class Number: public Postit{
protected:
    int boxszel;
    int boxmag;
public:
    static Postit& instance();
    Number( int x0, int y0,int sx0,int sy0, int boxszel0);
    void rajzol();
    bool rajtavanboxon(int ex, int ey);
    void handle(genv::event ev);
    bool felette(int ex, int ey);
    bool focused();
    int Getvalue();
};

#endif // SZAMLALO_HPP_INCLUDED
