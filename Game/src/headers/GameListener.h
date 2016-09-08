#ifndef GAMELISTENER_H
#define GAMELISTENER_H
#include <vector>
class Window;
class Game;
class Filesystem;
class GameListener{
public:
    void setGame(Game* g);
    void onFilesystemChange(Filesystem* f);
    std::vector<Window*> getWindows();
    Game* getGame();
private:
    Game* _g;
};


#endif // GAMELISTENER_H
