#include <iostream>
#include <vector>
#include <SDL.h>

using namespace std;

void draw_point(SDL_Renderer* render, int x, int y)
{
	SDL_RenderDrawPoint(render, x, y);
}

void it_horizontalLine(SDL_Renderer* render, int x, int y, int length)
{
	while (length != 0) {
		SDL_RenderDrawPoint(render, x + length, y);
		if (length > 0)
			length--;
		else
			length++;
	}
}

void it_verticalLine(SDL_Renderer* render, int x, int y, int length)
{
	while (length != 0) {
		SDL_RenderDrawPoint(render, x, y + length);
		if (length > 0)
			length--;
		else
			length++;
	}
}

void it_verticalDiagram(SDL_Renderer* render, vector<int>numbers)
{
	for (int i = 0; i < numbers.size(); i++) {
		it_verticalLine(render, 10 * i, 0, numbers[i]);
	}
}

void it_horizontalDiagram(SDL_Renderer* render, vector<int>numbers)
{
	for (int i = 0; i < numbers.size(); i++) {
		it_horizontalLine(render, 0, 10 * i + 10, numbers[i]);
	}
}

int main(int argc, char* argv[])
{
	SDL_Renderer* render;
	SDL_Window* window;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(1001, 1001, 0, &window, &render);
	SDL_SetRenderDrawColor(render, 255, 255, 255, 0);
	//draw_point(render, SDL_GetWindowSurface(window)->w / 2, SDL_GetWindowSurface(window)->h / 2);
	//it_horizontalLine(render, 500, 500, 50);
	//it_verticalLine(render, 500, 500, 50);
	vector <int> mass = { 70, 50, 20, 300, 780 };
	//it_verticalDiagram(render, mass);
	it_horizontalDiagram(render, mass);
	SDL_RenderPresent(render);
	SDL_Delay(3000);
	return 0;
}