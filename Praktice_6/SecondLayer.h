#pragma once
#include <SDL.h>

void Right(SDL_Renderer* ren, int x, int y, int speed, int& x1, int& y1);
void Down(SDL_Renderer* ren, int x, int y, int speed, int& x1, int& y1);
void Left(SDL_Renderer* ren, int x, int y, int speed, int& x1, int& y1);
void Up(SDL_Renderer* ren, int x, int y, int speed, int& x1, int& y1);
void DrawSecondLayer(SDL_Window* win, SDL_Renderer* ren );