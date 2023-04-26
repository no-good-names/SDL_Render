#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

const int WINDOW_WIDTH = 680;
const int WINDOW_HEIGHT = 480;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int main( int argc, char* args[] ) {

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	bool quit = false;
	// FPS cap v;
	int fps = 60;
  	int frameDelay = 1000 / fps;
  	Uint32 frameStart;
  	int frameTime;
	
	SDL_Event event;
	while(!quit) {
		frameStart = SDL_GetTicks();
		while(SDL_PollEvent(&event) != 0) {
			switch(event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			}
		}
		SDL_RenderPresent(renderer);

		// FPS cap;
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
		SDL_Delay(frameDelay - frameTime);
		}
	}
	SDL_DestroyRenderer(renderer);
  	SDL_DestroyWindow(window);
  	SDL_Quit();

	return 0;
}
