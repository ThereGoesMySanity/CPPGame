//
//  Dock.hpp
//  Game
//
//  Created by Willem Kennedy on 2016-08-24.
//  Copyright © 2016 Willem Kennedy. All rights reserved.
//

#ifndef Dock_h
#define Dock_h

#include "Game.h"
#include "Graphics.h"
#include "Window.h"

class Dock: public Window {
public:
    Dock(Game g);
    ~Dock();
    void move(int x, int y) {}
    
    void draw(Graphics &g);
    void onMouse(bool b, int x, int y);
};

#endif /* Dock_hpp */
