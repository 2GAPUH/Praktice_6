#pragma once
#include <SDL.h> 
struct SnowFlakeParameters
{
	int x, y;
	float scaleX, scaleY;
	SDL_Color color_factor;
	int size;
	int stepToReverse;
	int isLightUp;
};

void DrawFirstLayer(SDL_Window* win, SDL_Renderer* ren);
void GenerateSnowFlakeArray(SnowFlakeParameters flakeArray[]);
void DrawSnowFlake(SDL_Renderer* ren, SDL_FPoint snowflake[], SnowFlakeParameters flakeArray[]);
float getDistance(float x1, float y1, float x2, float y2);
void GenerateSnowFlake(SnowFlakeParameters flakeArray[], int index);
void ReColorSnowFlake(SnowFlakeParameters flakeArray[]);