#ifndef GAMELISTENER_H
#define GAMELISTENER_H
class Filesystem;
class GameListener{
public:
    void onFilesystemChange(Filesystem* f){}
};


#endif // GAMELISTENER_H
