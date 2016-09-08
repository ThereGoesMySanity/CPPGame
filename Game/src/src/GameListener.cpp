#include "GameListener.h"
#include "Game.h"


void GameListener::setGame(Game* g){
    _g=g;
}
void GameListener::onFilesystemChange(Filesystem* f){

}
std::vector<Window*> GameListener::getWindows(){
    return _g->_windows;
}
Game* GameListener::getGame(){
    return _g;
}
