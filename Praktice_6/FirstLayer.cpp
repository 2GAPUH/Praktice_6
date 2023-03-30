#include <SDL.h>
#include <iostream>
#define WINDOW_HEIGTH 600
#define WINDOW_WIDTH 1000
#define SNOWFLAKE_COUNT 150


struct SnowFlakeParameters
{
	int x, y;
	float scaleX, scaleY;
	SDL_Color color_factor;
	int size;
	int stepToReverse;
	bool isLightUp;
};

float getDistance(float x1, float y1, float x2, float y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void DrawSnowFlake(SDL_Renderer* ren, SDL_FPoint snowflake[], SnowFlakeParameters flakeArray[])
{
	
	for (int n = 0; n < SNOWFLAKE_COUNT; n++)
	{
		SDL_SetRenderDrawColor(ren, 192, 192, 192, 255);
		for (int i = 0; i < 4; i++)
		{	
			float x = 0, y = 0;
			SDL_RenderDrawLine(ren, (x = flakeArray[n].size * snowflake[i].x) + flakeArray[n].x,
									(y = flakeArray[n].size * snowflake[i].y) + flakeArray[n].y,
									-x + flakeArray[n].x,
									-y + flakeArray[n].y) ;
		}
	}
}

void GenerateSnowFlakeArray(SnowFlakeParameters flakeArray[])
{
	int color;
	for (int i = 0; i < SNOWFLAKE_COUNT;i++)
	{
		flakeArray[i].x = rand() % (WINDOW_WIDTH - 0 + 1) + 0;
		flakeArray[i].y = rand() % (WINDOW_HEIGTH - 0 + 1) + 0;
		flakeArray[i].scaleX = rand() % (2 - 1 + 1) + 1;
		flakeArray[i].scaleY = rand() % (2 - 1 + 1) + 1;
		flakeArray[i].size = rand() % (25 - 15 + 1) + 15;
		flakeArray[i].stepToReverse = rand() % (40 - 25 + 1) + 25;
		flakeArray[i].color_factor.a = color = rand() % (40 - 25 + 1) + 25;
		flakeArray[i].color_factor.r = color;
		flakeArray[i].color_factor.g = color;
		flakeArray[i].color_factor.b = color;
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

void GenerateSnowFlake(SnowFlakeParameters flakeArray[], int index)
{
	flakeArray[index].y = -flakeArray[index].size;
	flakeArray[index].x = rand() % ((WINDOW_WIDTH - 50) + 50 + 1) + 50;
	flakeArray[index].size = rand() % (25 - 15 + 1) + 15;
	if (rand() % 2 == 0)
	{
		flakeArray[index].scaleX *= -1;
		flakeArray[index].scaleX = rand() % (2 - 1 + 1) + 1;
		flakeArray[index].scaleY = rand() % (2 - 1 + 1) + 1;
	}
}

void MoveSnowFlake(SnowFlakeParameters flakeArray[])
{
	for (int i = 0; i < SNOWFLAKE_COUNT; i++)
	{

		flakeArray[i].x += flakeArray[i].scaleX;
		flakeArray[i].y += flakeArray[i].scaleY;
		if (flakeArray[i].stepToReverse <= 0)
		{
			flakeArray[i].scaleX *= -1;
			flakeArray[i].stepToReverse = rand() % (40 - 25 + 1) + 25;
		}
		else flakeArray[i].stepToReverse--;
		if (getDistance(flakeArray[i].x, flakeArray[i].y, flakeArray[i].x, WINDOW_HEIGTH + 25) < 25)
			GenerateSnowFlake(flakeArray, i);
	}
}

void ReColorSnowFlake(SnowFlakeParameters flakeArray[])
{
	//int color;
	//flakeArray[i].color_factor.a += flakeArray[i].isLightup;
	//flakeArray[i].color_factor.r
	//flakeArray[i].color_factor.g
	//flakeArray[i].color_factor.b
	 
	// flakeArray[i].color_factor.a = color = rand() % (40 - 25 + 1) + 25;
	// flakeArray[i].color_factor.r = color;
	//flakeArray[i].color_factor.g = color;
	//flakeArray[i].color_factor.b = color;
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

	MoveSnowFlake(flakeArray);

	DrawSnowFlake(ren ,snowflake, flakeArray);	
}