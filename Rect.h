#ifndef RECT_H
#define RECT_H
#include <SDL2/SDL.h>

class Rect{
public:
	Rect(int x, int y, int w, int h);
	void draw(SDL_Renderer*& renderer);
	void update(int WINDOW_HEIGHT);

	int x_pos = 0;
	int y_pos = 0;
	int width;
	int height;

	struct{
		int x = 6;
		int y = 6;
	}velocity;

	SDL_Rect pos_rect;


};

#endif //RECT_H
