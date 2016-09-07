#ifndef FOCUSABLE_H
#define FOCUSABLE_H
#include "Graphics.h"
class Focusable{
public:
    virtual void render(Graphics* g);
    bool focus();
    bool unfocus();
private:
    bool _focused;
};


#endif // FOCUSABLE_H
