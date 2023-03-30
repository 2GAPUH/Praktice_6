#include <SDL.h>
#include <iostream>
#include "FirstLayer.h"
#include "SecondLayer.h"
#include "ThirdLayer.h"
#include "func.h"

int main(int argc, char* argv[])
{
	srand(time(NULL));
	SDL_Renderer* ren = NULL;
	SDL_Window* win = NULL;

	Init(&win, &ren, 600, 1000);

	while (1) {
		SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
		SDL_RenderClear(ren);
		//DrawFirstLayer(win, ren);
		//DrawSecondLayer(win, ren);
		DrawThirdLayer(win, ren);
		SDL_RenderPresent(ren);
		SDL_Delay(16);
	}

	DeInit(0, &win, &ren);
	return 0;
}