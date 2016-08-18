#ifndef GRAPHICS_H
#define GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();

	SDL_Surface* loadImage(const std::string &filePath);
	void blitSurface(SDL_Texture* source, SDL_Rect* source, SDL_Rect* dest);
	void flip();
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	std::map<std::string, SDL_Surface*> _sprites;
};
#endif
