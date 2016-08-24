#ifndef GRAPHICS_H
#define GRAPHICS_H
#ifdef __MACH__
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#else
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
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
    void drawText(const std::string &text, int x, int y);
    void setFont(const std::string &font, int size);
    void setColor(Uint8 r, Uint8 g, Uint8 b);
	void flip();
	void clear();
	void drawLine(int x1, int y1, int x2, int y2);
	void drawRect(int x1, int y1, int x2, int y2);
	void fillRect(int x1, int y1, int x2, int y2);
	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
    SDL_Color _color = {0,0,0,255};
	std::map<std::string, SDL_Surface*> _sprites;
    std::string currentFont;
    int fontSize;
    std::map<std::string, TTF_Font*> _fonts;
};
#endif
