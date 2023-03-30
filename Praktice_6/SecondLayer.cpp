#include <SDL.h>
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
	static int x = win_width/2, y = 0, speed = 8, xMove = 1, yMove = 0, clockwise = 1;
	static int type = 3;
	
	Draw(ren, x, y);
	
	x += xMove * speed;
	y += yMove * speed;
	if (clockwise == 1)
	{
		if (xMove == 1 && yMove == 0 && x + RECT_WIDTH >= win_width)
		{
			yMove = 1;
			xMove = 0;
		}
		else if (xMove == 0 && yMove == 1 && y + RECT_HEIGHT >= win_height)
		{
			yMove = 0;
			xMove = -1;
		}
		else if (xMove == -1 && yMove == 0 && x <= 0)
		{
			yMove = -1;
			xMove = 0;
		}
		else if (xMove == 0 && yMove == -1 && y <= 0)
		{
			yMove = 0;
			xMove = 1;
		}
	}
	else
	{
		if (xMove == -1 && yMove == 0 && x <= 0)
		{
			yMove = 1;
			xMove = 0;
		}
		else if (xMove == 0 && yMove == 1 && y + RECT_HEIGHT >= win_height)
		{
			yMove = 0;
			xMove = 1;
		}
		else if (xMove == 1 && yMove == 0 && x + RECT_WIDTH >= win_width)
		{
			yMove = -1;
			xMove = 0;
		}
		else if (xMove == 0 && yMove == -1 && y <= 0)
		{
			yMove = 0;
			xMove = -1;
		}
	
	}
}
