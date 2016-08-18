#ifndef GRAPHICS_H
#define GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();

	void flip();
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};
#endif
