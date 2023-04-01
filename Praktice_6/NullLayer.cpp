#include <SDL.h>
#include <iostream>
#define WIN_WIDTH 1000
#define WIN_HEIGHT 600


void add_SDL_DrawFractalKoch(SDL_Renderer* renderer, float Ax, float Ay, float Bx, float By, int n)
{
	float a1x, a1y, b1x, b1y, Cx, Cy, distanse, angle;

	if (n < 1)
	{
		SDL_RenderDrawLineF(renderer, Ax, Ay, Bx, By);
	}
	else
	{
		a1x = Ax + (Bx - Ax) / 3.f;
		a1y = Ay + (By - Ay) / 3.f;
		b1x = Ax + 2 * (Bx - Ax) / 3.f;
		b1y = Ay + 2 * (By - Ay) / 3.f;

		distanse = sqrtf((a1x - b1x) * (a1x - b1x) + (a1y - b1y) * (a1y - b1y));

		angle = atan2f(Ay - By, Bx - Ax) + M_PI / 3;

		Cx = a1x + distanse * cosf(angle);
		Cy = a1y - distanse * sinf(angle);

		add_SDL_DrawFractalKoch(renderer, Ax, Ay, a1x, a1y, n - 1);
		add_SDL_DrawFractalKoch(renderer, a1x, a1y, Cx, Cy, n - 1);
		add_SDL_DrawFractalKoch(renderer, Cx, Cy, b1x, b1y, n - 1);
		add_SDL_DrawFractalKoch(renderer, b1x, b1y, Bx, By, n - 1);
	}
}


void add_SDL_DrawSnowflakeKoch(SDL_Renderer* renderer, float x, float y, int n, float scale)
{
	add_SDL_DrawFractalKoch(renderer, x + scale * 1.f / 2.f, y + scale * sqrtf(3) / 6.f, x + scale * -1.f / 2.f, y + scale * sqrtf(3) / 6.f, n);
	add_SDL_DrawFractalKoch(renderer, x + scale * -1.f / 2.f, y + scale * sqrtf(3) / 6.f, x, y + scale * -sqrtf(3) / 3.f, n);
	add_SDL_DrawFractalKoch(renderer, x, y + scale * -sqrtf(3) / 3.f, x + scale * 1.f / 2.f, y + scale * sqrtf(3) / 6.f, n);
}

void DrawNullLayer(SDL_Window* window, SDL_Renderer* renderer)
{
	static int sign_i = 1;
	static int i = 110;
	static int gradient = 3, count = 0, gradienMove = 1;
	
	SDL_SetRenderDrawColor(renderer, 2, 0, 120, 0);

	//Второй цвет постепенно уменьшеается на всю длину
	// 0 20 168
	// 75 0 130
	
	for (int r = 0, g = 20, b = 188, k = 0;k < WIN_HEIGHT;k++)
	{
		if (k % (WIN_HEIGHT / 75) == 0)
			r++;
		if (k % (WIN_HEIGHT / 20) == 0)
			g--;
		if (k % (WIN_HEIGHT / 58) == 0)
			b--;
		SDL_SetRenderDrawColor(renderer, r + gradient, g + gradient, b + gradient, 255);
		SDL_RenderDrawLine(renderer, 0, k, WIN_WIDTH, k);
	}


	SDL_SetRenderDrawColor(renderer, i, i, i, 0);
	add_SDL_DrawSnowflakeKoch(renderer, WIN_WIDTH /2, WIN_HEIGHT/2, 3, 170);

	if (i >= 222)
	{
		sign_i *= -1;
		i = 220;
	}
	else if (i <= 110)
	{
		sign_i *= -1;
		i = 112;
	}
	i += sign_i;

	count++;
	if (count % 5 == 0)
	{
		gradient += gradienMove;
		if (gradient >= 50)
			gradienMove *= -1;
		if (gradient <= 2)
			gradienMove *= -1;
	}
}