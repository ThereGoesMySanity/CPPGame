#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

#include <string>
#include <vector>

class Graphics;
class Sprite {
public:
	Sprite();
	Sprite(Graphics &graphics, const std::vector<std::string> &filePaths, int sourceX, int sourceY, int width, int height,
			float posX, float posY);
	virtual ~Sprite();
	virtual void update();
	void draw(Graphics &graphics, int x, int y);
	void scale(float f);
	void next();
	void sprite(int i);

protected:
	SDL_Rect _sourceRect;
	std::vector<SDL_Texture*> _sprite;

	float _x, _y, _scale, _currentSprite;
private:
};


#endif
