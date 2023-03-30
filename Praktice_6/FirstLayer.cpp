#include <SDL.h>
#include <iostream>
#define WINDOW_HEIGTH 600
#define WINDOW_WIDTH 1000
#define SNOWFLAKE_COUNT 100


struct SnowFlakeParameters
{
	int x, y;
	float scale;
	float color_factor;
	bool isLightUp;
};

float getDistance(float x1, float y1, float x2, float y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void DrawSnowFlake(SDL_Renderer* ren, SDL_FPoint snowflake[], float size, SnowFlakeParameters flakeArray[])
{
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
	for (int n = 0; n < SNOWFLAKE_COUNT; n++)
	{
		for (int i = 0; i < 4; i++)
			SDL_RenderDrawLine(ren, size * snowflake[i].x + flakeArray[n].x, size * snowflake[i].y + flakeArray[n].y, -size * snowflake[i].x + flakeArray[n].x, -size * snowflake[i].y + flakeArray[n].y);
	}
}

void GenerateSnowFlakeArray(SnowFlakeParameters flakeArray[])
{
	for (int i = 0; i < SNOWFLAKE_COUNT;i++)
	{
		flakeArray[i].x = rand() % (WINDOW_WIDTH - 0 + 1) + 0;
		flakeArray[i].y = rand() % (WINDOW_HEIGTH - 0 + 1) + 0;
		for (int n = 0;n < i; n++)
		{
			if (getDistance(flakeArray[n].x, flakeArray[n].y, flakeArray[i].x, flakeArray[i].y) < 50)
			{
				i--;
				break;
			}
		}
	}
}

//слой - падающий снег (снежинки разных размеров падают с разной скоростью, плавно покачиваясь влево - вправо)
void DrawFirstLayer(SDL_Window* win, SDL_Renderer* ren)
{
	SDL_SetRenderDrawColor(ren, 255, 255, 255, 0);

	static bool check = 1;

	SDL_FPoint snowflake[4] = { {-0.5, 0}, {-0.35, 0.35}, {0, 0.5}, {0.35, 0.35} };

	static SnowFlakeParameters flakeArray[SNOWFLAKE_COUNT];

	if (check)
	{
		GenerateSnowFlakeArray(flakeArray);
		check = 0;
	}

	DrawSnowFlake(ren ,snowflake, 20, flakeArray);	
}