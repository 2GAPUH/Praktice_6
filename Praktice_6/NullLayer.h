#pragma once
#include <SDL.h>

void add_SDL_DrawSnowflakeKoch(SDL_Renderer* renderer, float x, float y, int n, float scale);
void add_SDL_DrawFractalKoch(SDL_Renderer* renderer, float Ax, float Ay, float Bx, float By, int n);
void DrawNullLayer(SDL_Window* window, SDL_Renderer* renderer);