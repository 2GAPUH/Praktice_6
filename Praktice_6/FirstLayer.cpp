#include <SDL.h>
#include <iostream>
#define WINDOW_HEIGTH 600
#define WINDOW_WIDTH 1000

struct SnowFlake
{
	int x, y;
	float scale;
	float color_factor;
	bool isLightUp;
};


void DrawSnowFlake(SDL_Renderer* ren ,SDL_FPoint snowflake[], float size)
{
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
	for (int i = 0; i < 4; i++)
		SDL_RenderDrawLine(ren, size * snowflake[i].x, size * snowflake[i].y, -size * snowflake[i].x, -size * snowflake[i].y);
}

//слой - падающий снег (снежинки разных размеров падают с разной скоростью, плавно покачиваясь влево - вправо)
void DrawFirstLayer(SDL_Window* win, SDL_Renderer* ren)
{
	SDL_SetRenderDrawColor(ren, 255, 255, 255, 0);
	SDL_RenderClear(ren);//Не забыть убрать
	
	SDL_FPoint snowflake[4] = { {-0.5, 0}, {-0.35, 0.35}, {0, 0.5}, {0.35, 0.35} };

	DrawSnowFlake(ren ,snowflake, 50);

	SDL_RenderPresent(ren); //Не забыть убрать

	system("pause");//Не забыть убрать
}