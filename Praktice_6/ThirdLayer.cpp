#include<iostream>
#include<SDL.h>
#include "ThirdLayer.h"
#include<time.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 600

void sex(SDL_Renderer* ren, SDL_Point* pos, unsigned int radius) 
{
	SDL_SetRenderDrawColor(ren, 0, 0, 200, 255);
	float degree = M_PI / 180;
	static int fin = 0;
	static int start = 0;
	static int scale = 1;
	int x, y, c;
	for (float i = start; i <= fin; i += 1 / ((float)radius / 25)) 
	{
		SDL_RenderDrawLine(ren, x, y, x = pos->x + radius * cosf(i * degree), y = pos->y + radius * sinf(i * degree));
		SDL_RenderDrawLine(ren, x, y, x = pos->x + (radius + 1) * cosf(i * degree), y = pos->y + (radius + 1) * sinf(i * degree));
		SDL_RenderDrawLine(ren, x, y, x = pos->x + (radius + 2) * cosf(i * degree), y = pos->y + (radius + 2) * sinf(i * degree));
		SDL_RenderDrawLine(ren, x, y, x = pos->x + (radius + 3) * cosf(i * degree), y = pos->y + (radius + 3) * sinf(i * degree));
		SDL_RenderDrawLine(ren, x, y, x = pos->x + (radius + 4) * cosf(i * degree), y = pos->y + (radius + 4) * sinf(i * degree));
	}
	if (fin > 359)
	{
		c = rand() % 8 + 4;
		c = 1 + c / 10;
		start += c;
	}
	else {
		c = rand() % 8 + 4;
		c = 1 + c / 10;
		fin += c;
	}
	if (start > 359)
	{
		fin = 0;
		start = 0;
	}
}


void DrawThirdLayer(SDL_Window* win, SDL_Renderer* ren)
{
	SDL_Point pos = { WINDOW_WIDTH/2, WINDOW_HEIGHT/2 };
	
	sex(ren, &pos, 100);
}