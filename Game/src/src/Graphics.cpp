/*
 * Graphics.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: Will
 */


#include "Graphics.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#ifdef __MACH__
#include <SDL2_image/SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
Graphics::Graphics(){
	_window = SDL_CreateWindow( "Game thing", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, globals::WIDTH, globals::HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );

	fontSize = 0;
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
    _context = SDL_GL_CreateContext(_window);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0.f,0.f,0.f,1.f);

}

Graphics::~Graphics(){
    for(std::map<std::string, GLuint>::iterator it = _textures.begin(); it != _textures.end(); it++){
        glDeleteTextures(1, &_textures[it->first]);
    }
	SDL_DestroyWindow(_window);
	SDL_GL_DeleteContext(_context);
}

GLuint Graphics::loadImage(const std::string &filePath){
	if(_textures.count("f:"+filePath) == 0){
        SDL_Surface* sur = IMG_Load(filePath.c_str());
        GLuint t;
        glGenTextures(1, &t);
        glBindTexture(GL_TEXTURE_2D, t);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sur->w, sur->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, sur->pixels);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		_textures["f:"+filePath] = t;
		SDL_FreeSurface(sur);
	}
	return _textures[filePath];
}
void Graphics::setFont(const std::string &font, int size){
    if(_fonts.count(font+globals::to_string(size))==0){
        TTF_Font* f = TTF_OpenFont(font.c_str(), size);
        if(!f){
            std::cout << TTF_GetError() << std::endl;
        }
        _fonts[font+globals::to_string(size)] = f;
    }
    currentFont = font+globals::to_string(size);
    fontSize = size;
}
void Graphics::drawText(const std::string &text, int x, int y, bool temp){
    if(currentFont=="")return;
    if(text=="")return;
    if(_fonts[currentFont]==NULL)return;
    GLuint t;
    if(_textures.count("t:"+text)==0){
        SDL_Surface* s = TTF_RenderText_Solid(_fonts[currentFont], text.c_str(), _color);
        glGenTextures(1, &t);
        if(!temp)_textures["t:"+text]=t;
        SDL_FreeSurface(s);
    }else{
        t=_textures["t:"+text];
    }
    blitSurface(t, x, y, 8*text.size(), 16);
}
void Graphics::setColor(Uint8 r, Uint8 g, Uint8 b){
    _color = {r, g, b, 255};
    glColor3ub(r, g, b);
}
void Graphics::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a){
    _color = {r, g, b, a};
    glColor4ub(r, g, b, a);
}
void Graphics::drawLine(int x1, int y1, int x2, int y2){
	glBegin(GL_LINE);
	normalizeVert(x1, y1);
	normalizeVert(x2, y2);
	glEnd();
}
void Graphics::drawRect(int x, int y, int w, int h){
	glBegin(GL_LINE_LOOP);
	normalizeVert(x, y);
	normalizeVert(x+w, y);
	normalizeVert(x+w, y+h);
	normalizeVert(x, y+h);
	glEnd();
}
void Graphics::fillRect(int x, int y, int w, int h){
	glBegin(GL_TRIANGLE_STRIP);
	normalizeVert(x, y);
	normalizeVert(x+w, y);
	normalizeVert(x, y+h);
	normalizeVert(x+w, y+h);
	glEnd();
}
void Graphics::blitSurface(GLuint &img, int x, int y, int w, int h){

	glBegin(GL_TRIANGLE_STRIP);
	glBindTexture(GL_TEXTURE_2D, img);
    glEnable(GL_TEXTURE_2D);
	glTexCoord2f(0,0);normalizeVert(x, y);
	glTexCoord2f(0,1);normalizeVert(x, y+h);
	glTexCoord2f(1,0);normalizeVert(x+w, y);
	glTexCoord2f(1,1);normalizeVert(x+w, y+h);
	glDisable(GL_TEXTURE_2D);
	glEnd();

}
void Graphics::flip(){
	SDL_GL_SwapWindow(_window);
}
void Graphics::clear(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}
void Graphics::normalizeVert(int x, int y){
    glVertex2f(2.f*x/globals::WIDTH-1, -2.f*y/globals::HEIGHT+1);
}
