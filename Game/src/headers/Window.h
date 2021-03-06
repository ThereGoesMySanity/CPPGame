#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include "Graphics.h"
#include "GameListener.h"
class Filesystem;
class Window: public GameListener {
public:
    Window(const std::string &title, int x, int y, int w, int h);
    virtual ~Window();
    virtual void move(int x, int y);
    virtual void draw(Graphics &g);
    virtual void drawExtra(Graphics &g);
    virtual void update(float delta);
    virtual void onInput(const std::string &input);
    virtual void onSpecialKey(SDL_Scancode key);
    virtual void onFocus();
    virtual void onUnfocus();
    virtual void onFilesystemChange(Filesystem* f);
    void minimize(bool b);
    virtual void onMouse(bool b, int x, int y);
    void onMouseMotion(SDL_MouseMotionEvent m);
    std::string _title;
    int _x, _y, _w, _h;
protected:
    bool _minimized;
    bool _moving;
};

#endif
