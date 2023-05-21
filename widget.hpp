#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

#include "graphics.hpp"

class widget {
protected:
    int _x, _y, _size_x, _size_y;
public:
    widget(int x, int y, int sx, int sy);
    virtual void rajzol() = 0;
    virtual void handle(genv::event ev) = 0;
};

#endif // WIDGET_H_INCLUDED
