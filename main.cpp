#include <iostream>
#include <SDL2/SDL.h>
#include "./include/Rect.h"
#include <vector>
#include <time.h>
#include <stdlib.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using std::cout;
using std::endl;
using std::string;


int main(int argc, char * argv[]){
	srand(time(NULL));
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("My project in SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	
	int row_amount = WINDOW_WIDTH / 6;
	std::vector<Rect> rects;
	for(int i = 0; i < row_amount; i++){
		Rect rect(i * 6, rand() % WINDOW_HEIGHT, 5, 10);
		rects.push_back(rect);
	}



	bool is_running = true;
	while(is_running){
		while(SDL_PollEvent(&event) != 0){
			if(event.type == SDL_QUIT){
				is_running = false;
			}
		}

		
		
		SDL_RenderClear(renderer);
		
		for(int i = 0; i < rects.size(); i++){
			rects[i].draw(renderer);
			rects[i].update(WINDOW_HEIGHT);
		}
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 0,0,0);
		SDL_Delay(10);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	window = NULL;
	renderer = NULL;
	SDL_Quit();

	return 0;
}
