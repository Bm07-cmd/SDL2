#include "../include/Rect.h"

Rect::Rect(int x, int y, int w, int h){
	x_pos = x;
	y_pos = y;
	width = w;
	height = h;
	
	pos_rect.x = x_pos;
	pos_rect.y = y_pos;
	pos_rect.w = width;
	pos_rect.h = height;
}


void Rect::draw(SDL_Renderer*& renderer){
	SDL_SetRenderDrawColor(renderer, 255, 0,0,0);
	SDL_RenderDrawRect(renderer, &pos_rect);
}