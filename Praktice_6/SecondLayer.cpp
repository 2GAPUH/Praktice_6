#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL.h>
#include <math.h>


int win_width = 1000, win_height = 600;


//#1_2 Квадрат с большой снежинкой (3 палки) 
//ездит по периметру окна, начиная от центра верха то по часовой, то против часовой стрелки, 
//то ускоряясь, то замедляясь (время рандомно и уск и замедл тоже).


void Right(SDL_Renderer* ren, int x, int y, int speed, int& x1, int& y1)
{
	speed = rand() % 10;
	for (int i = x; i <= win_width - 200; i += 10 + speed)
	{
		SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
		SDL_RenderClear(ren);

		SDL_SetRenderDrawColor(ren, 255, 0, 0, 0);
		SDL_Rect target = { i, y, 200, 100 };
		SDL_RenderFillRect(ren, &target);
		SDL_RenderPresent(ren);
		SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);

		SDL_RenderDrawLine(ren, i + 149, y, i + 49, y + 100);
		SDL_RenderDrawLine(ren, i + 150, y, i + 50, y + 100);
		SDL_RenderDrawLine(ren, i + 151, y, i + 51, y + 100);

		SDL_RenderDrawLine(ren, i + 50, y + 49, i + 150, y + 49);
		SDL_RenderDrawLine(ren, i + 50, y + 50, i + 150, y + 50);
		SDL_RenderDrawLine(ren, i + 50, y + 51, i + 150, y + 51);

		SDL_RenderDrawLine(ren, i + 49, y, i + 149, y + 100);
		SDL_RenderDrawLine(ren, i + 50, y, i + 150, y + 100);
		SDL_RenderDrawLine(ren, i + 51, y, i + 151, y + 100);

		SDL_RenderPresent(ren);
		SDL_Delay(16);
		x1 = i;
		y1 = y;
	}
}

void Down(SDL_Renderer* ren, int x, int y, int speed, int& x1, int& y1)
{
	speed = rand() % 10;
	for (int i = y; i <= win_height - 100; i += 10 + speed)
	{
		SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
		SDL_RenderClear(ren);

		SDL_SetRenderDrawColor(ren, 255, 0, 0, 0);
		SDL_Rect target = { x, i, 200, 100 };
		SDL_RenderFillRect(ren, &target);
		SDL_RenderPresent(ren);
		SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);

		SDL_RenderDrawLine(ren, x + 49, i, x + 149, 100 + i);
		SDL_RenderDrawLine(ren, x + 50, i, x + 150, 100 + i);
		SDL_RenderDrawLine(ren, x + 51, i, x + 151, 100 + i);


		SDL_RenderDrawLine(ren, x + 50, i + 49, x + 150, i + 49);
		SDL_RenderDrawLine(ren, x + 50, i + 50, x + 150, i + 50);
		SDL_RenderDrawLine(ren, x + 50, i + 51, x + 150, i + 51);

		SDL_RenderDrawLine(ren, x + 149, i, x + 49, 100 + i);
		SDL_RenderDrawLine(ren, x + 150, i, x + 50, 100 + i);
		SDL_RenderDrawLine(ren, x + 151, i, x + 51, 100 + i);

		SDL_RenderPresent(ren);
		SDL_Delay(16);

		x1 = x;
		y1 = i;
	}
}

void Left(SDL_Renderer* ren, int x, int y, int speed, int& x1, int& y1)
{
	speed = rand() % 10;
	for (int i = x; i > 0; i -= 10 + speed)
	{
		SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
		SDL_RenderClear(ren);

		SDL_SetRenderDrawColor(ren, 255, 0, 0, 0);
		SDL_Rect target = { i, y, 200, 100 };
		SDL_RenderFillRect(ren, &target);
		SDL_RenderPresent(ren);
		SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);

		SDL_RenderDrawLine(ren, i + 149, y, i + 49, y + 100);
		SDL_RenderDrawLine(ren, i + 150, y, i + 50, y + 100);
		SDL_RenderDrawLine(ren, i + 151, y, i + 51, y + 100);

		SDL_RenderDrawLine(ren, i + 50, y + 49, i + 150, y + 49);
		SDL_RenderDrawLine(ren, i + 50, y + 50, i + 150, y + 50);
		SDL_RenderDrawLine(ren, i + 50, y + 51, i + 150, y + 51);

		SDL_RenderDrawLine(ren, i + 49, y, i + 149, y + 100);
		SDL_RenderDrawLine(ren, i + 50, y, i + 150, y + 100);
		SDL_RenderDrawLine(ren, i + 51, y, i + 151, y + 100);

		SDL_RenderPresent(ren);
		SDL_Delay(16);

		x1 = i;
		y1 = y;
	}
}


void Up(SDL_Renderer* ren, int x, int y, int speed, int& x1, int& y1)
{
	
	speed = rand() % 10;
	for (int i = y; i > 0; i -= 10 + speed)
	{
		SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
		SDL_RenderClear(ren);

		SDL_SetRenderDrawColor(ren, 255, 0, 0, 0);
		SDL_Rect target = { x, i, 200, 100 };
		SDL_RenderFillRect(ren, &target);
		SDL_RenderPresent(ren);
		SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);

		SDL_RenderDrawLine(ren, x + 49, i, x + 149, 100 + i);
		SDL_RenderDrawLine(ren, x + 50, i, x + 150, 100 + i);
		SDL_RenderDrawLine(ren, x + 51, i, x + 151, 100 + i);


		SDL_RenderDrawLine(ren, x + 50, i + 49, x + 150, i + 49);
		SDL_RenderDrawLine(ren, x + 50, i + 50, x + 150, i + 50);
		SDL_RenderDrawLine(ren, x + 50, i + 51, x + 150, i + 51);

		SDL_RenderDrawLine(ren, x + 149, i, x + 49, 100 + i);
		SDL_RenderDrawLine(ren, x + 150, i, x + 50, 100 + i);
		SDL_RenderDrawLine(ren, x + 151, i, x + 51, 100 + i);

		SDL_RenderPresent(ren);
		SDL_Delay(16);

		x1 = x;
		y1 = i;
	}
}

void DrawSecondLayer(SDL_Window* win, SDL_Renderer* ren)
{
	int x, y, speed, x1, y1;
	system("chcp 1251");
	srand(time(NULL));

	Right(ren, 400, 0, 0, x1, y1);
	while (x1 != 900)
	{
		if (x1 > 780 && y1 < 20)
		{
			if (rand() % 10 >= 4)
				Down(ren, 800, 0, 0, x1, y1);
			else
				Left(ren, 800, 0, 0, x1, y1);
		}
		if (x1 > 780 && y1 > 480)
		{
			if (rand() % 10 >= 4)
				Left(ren, 800, 500, 0, x1, y1);
			else
				Up(ren, 800, 500, 0, x1, y1);
		}
		if (x1 < 20 && y1 > 480)
		{
			if (rand() % 10 >= 4)
				Up(ren, 0, 500, 0, x1, y1);
			else
				Right(ren, 0, 500, 0, x1, y1);
		}
		if (x1 < 20 && y1 < 20)
		{
			if (rand() % 10 >= 4)
				Right(ren, 0, 0, 0, x1, y1);
			else
				Down(ren, 0, 0, 0, x1, y1);
		}
	}

}
