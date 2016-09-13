#ifndef GRAPHICS_H
#define GRAPHICS_H
#ifdef __MACH__
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#else
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif
#include <GL/gl.h>
#include <string>
#include <map>
#include "Globals.h"

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();

	GLuint loadImage(const std::string &filePath);
	void blitSurface(GLuint &texture, int x, int y, int w, int h);
    void drawText(const std::string &text, int x, int y, bool temp);
    void setFont(const std::string &font, int size);
    void setColor(Uint8 r, Uint8 g, Uint8 b);
    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void flip();
	void clear();
	void drawLine(int x1, int y1, int x2, int y2);
	void drawRect(int x1, int y1, int w, int h);
	void fillRect(int x1, int y1, int w, int h);
	void normalizeVert(int x, int y);
private:
    SDL_Color _color;
	SDL_Window* _window;
	SDL_GLContext _context;
	std::map<std::string, GLuint> _textures;
	std::map<std::string, GLuint> _tempTextures;
    std::string currentFont;
    int fontSize;
    std::map<std::string, TTF_Font*> _fonts;
};
#endif
