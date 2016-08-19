#ifndef GRAPHICS_H
#define GRAPHICS_H
#ifdef _WIN32
#include <SDL2/SDL_image.h>
#else
#include <SDL2_image/SDL_image.h>
#endif
#include <string>
#include <map>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();

	SDL_Surface* loadImage(const std::string &filePath);
	void blitSurface(SDL_Texture* img, SDL_Rect* src, SDL_Rect* dest);
	void flip();
	void clear();
	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, SDL_Surface*> _sprites;
};
#endif
