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
    Dock(Game *g, int x, int y, int w, int h);
    ~Dock();
    void move(int x, int y) override {}
    
    void draw(Graphics &g) override;
    void onMouse(bool b, int x, int y) override;
};

#endif /* Dock_hpp */
