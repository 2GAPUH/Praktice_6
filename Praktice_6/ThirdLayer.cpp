#include<iostream>
#include<SDL.h>
#include "ThirdLayer.h"
#include<time.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 600

void sex(SDL_Renderer* ren, SDL_Point* pos, unsigned int radius) 
{
	static int delay =10;
	static int lBord = 10, rBord = 20;
	static int lBord1 = 1000, rBord1 = 2000;
								
	static float degree = M_PI / 180;
	static int n=0;
	static int timer=100;
	static float i = 0; 
	i += 1 / (float)radius; n++;
	{
		if (timer--==0)
		{

			delay = rand() % (rBord - lBord + 1) + lBord;
			timer = rand() % (rBord1 - lBord1 + 1) + lBord1;
		}
		SDL_RenderDrawPoint(ren, pos->x + radius * cosf(i * degree), pos->y + radius * sinf(i * degree));
		SDL_RenderDrawPoint(ren, pos->x + (radius +1) * cosf(i * degree), pos->y + (radius +1) * sinf(i * degree));
		SDL_RenderDrawPoint(ren, pos->x + (radius +2) * cosf(i * degree), pos->y + (radius +2) * sinf(i * degree));
		SDL_RenderDrawPoint(ren, pos->x + (radius +3) * cosf(i * degree), pos->y + (radius +3) * sinf(i * degree));
		SDL_RenderDrawPoint(ren, pos->x + (radius +4) * cosf(i * degree), pos->y + (radius +4) * sinf(i * degree));
		if (n % delay == 0) {
			SDL_RenderPresent(ren);
			SDL_Delay(3);
		}
	}
}

void DrawThirdLayer(SDL_Window* win, SDL_Renderer* ren)
{
	int n = 1;
	int c, c1, c2;
	
	SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
	SDL_Point pos = { WINDOW_WIDTH/2, WINDOW_HEIGHT/2 };
	
	sex(ren, &pos, 100);
	if (n == 1)
	{
		n *= -1;
		SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
	}
	else
	{
		n *= -1;
		c = rand() % (255 - 0 + 1) + 0;
		c1 = rand() % (255 - 0 + 1) + 0;
		c2 = rand() % (255 - 0 + 1) + 0;
		SDL_SetRenderDrawColor(ren, c, c1, c2, 255);
	}
	
}