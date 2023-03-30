#include <SDL.h>
#include <iostream>
#define RECT_WIDTH 200
#define RECT_HEIGHT 100

int win_width = 1000, win_height = 600;


//#1_2 Квадрат с большой снежинкой (3 палки) 
//ездит по периметру окна, начиная от центра верха то по часовой, то против часовой стрелки, 
//то ускоряясь, то замедляясь (время рандомно и уск и замедл тоже).



void Draw(SDL_Renderer* ren, int x, int y)
{
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 0);
	SDL_Rect target = { x, y, RECT_WIDTH, RECT_HEIGHT };
	SDL_RenderFillRect(ren, &target);

	SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
	
	SDL_RenderDrawLine(ren, x + 149, y, x + 49, y + 100);
	SDL_RenderDrawLine(ren, x + 150, y, x + 50, y + 100);
	SDL_RenderDrawLine(ren, x + 151, y, x + 51, y + 100);
	SDL_RenderDrawLine(ren, x + 50, y + 49, x + 150, y + 49);
	SDL_RenderDrawLine(ren, x + 50, y + 50, x + 150, y + 50);
	SDL_RenderDrawLine(ren, x + 50, y + 51, x + 150, y + 51);
	SDL_RenderDrawLine(ren, x + 49, y, x + 149, y + 100);
	SDL_RenderDrawLine(ren, x + 50, y, x + 150, y + 100);
	SDL_RenderDrawLine(ren, x + 51, y, x + 151, y + 100);
}



void DrawSecondLayer(SDL_Window* win, SDL_Renderer* ren)
{
	static int x = 500, y = 0, xMove = 10, yMove = 0, clockwise = 1, cnt = 0;
	int speed, swap;
	static int type = 3;
	srand(time(NULL));

	Draw(ren, x, y);

	if (x > 10 && y >= 0)
	{
		swap = 5;
	}
	else if (x >= 790 && y <= 10)
	{
		swap = rand() % 10;
	}
	else if (x <= 790 && y >= 490)
	{
		swap = rand() % 10;
	}
	else if (x >= 10 && y >= 490)
	{
		swap = rand() % 10;
	}
	else if (x <=10 && x< 500 && y >= 0)
	{
		swap = rand() % 10;
	}
	

	do
	{
		speed = rand() % 10+1;
	}while (speed == 0);

		x += xMove * speed;
		y += yMove * speed;

		if ( x >= 0 && y <= 10 && y+RECT_HEIGHT>=0)
		{
			if (swap >= 5)
			{
				xMove = 1;
				yMove = 0;	
			}
			else
			{
				xMove = 0;
				yMove = 1;
			}
		}
		if (x >= 790 && y <= 10 && x + RECT_WIDTH <= win_width)
		{
			if (swap >= 5)
			{
				xMove = 0;
				yMove = 1;
			}
			else
			{
				xMove = -1;
				yMove = 0;
			}
		}
		if (x >= 790 && y >= 490 && y + RECT_HEIGHT <= win_height)
		{
			if (swap >= 5)
			{
				xMove = -1;
				yMove = 0;
			}
			else
			{
				xMove = 0;
				yMove = -1;
			}
		}
		if (x <= 10 && y >= 490 && x + RECT_WIDTH >= 0)
		{
			if (swap >= 4)
			{
				xMove = 0;
				yMove = -1;
			}
			else
			{
				xMove = 1;
				yMove = 0;
			}
		}
		
}
