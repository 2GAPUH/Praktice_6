#pragma once
#include <SDL.h> 

struct SnowFlakeParameters
{
	int x, y;
	float scale;
	float color_factor;
	bool isLightUp;
};


void DrawFirstLayer(SDL_Window* win, SDL_Renderer* ren);
void GenerateSnowFlakeArray(SnowFlakeParameters flakeArray[]);
void DrawSnowFlake(SDL_Renderer* ren, SDL_FPoint snowflake[], float size, SnowFlakeParameters flakeArray[]);
float getDistance(float x1, float y1, float x2, float y2);