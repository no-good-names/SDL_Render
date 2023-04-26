#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

deftype enum {false, true} bool;

const int WINDOW_WIDTH = 1640;
const int WINDOW_HEIGHT = 1480;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int main( int argc, char* args[] )
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Event event;
	window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	bool quit = false;
	
	SDL_Event event;
	while(!quit) {
		while(SDL_PollEvent(&event) != 0) {
			switch(event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			}
		}
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
  	SDL_DestroyWindow(window);
  	SDL_Quit();

	return 0;
}
