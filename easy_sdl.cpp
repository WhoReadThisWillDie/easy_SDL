#include <iostream> 
#include <SDL.h> 
#include <vector> 
#define WINDOW_SIZE 1000
#define round(x) floor(x + 0.5f)

using namespace std;

void draw_point(SDL_Renderer* renderer, int x, int y)
{
    SDL_RenderDrawPoint(renderer, x, y);
}

void it_horizontalLine(SDL_Renderer* renderer, int x, int y, int length)
{
    while (length != 0) {
        SDL_RenderDrawPoint(renderer, x + length, y);
        if (length > 0)
            length--;
        else
            length++;
    }
}

void it_verticalLine(SDL_Renderer* renderer, int x, int y, int length)
{
    while (length != 0) {
        SDL_RenderDrawPoint(renderer, x, y + length);
        if (length > 0)
            length--;
        else
            length++;
    }
}

void it_verticalDiagram(SDL_Renderer* renderer, vector<int>numbers)
{
    for (int i = 0; i < numbers.size(); i++) {
        it_verticalLine(renderer, 10 * i, 0, numbers[i]);
    }
}

void it_horizontalDiagram(SDL_Renderer* renderer, vector<int>numbers)
{
    for (int i = 0; i < numbers.size(); i++) {
        it_horizontalLine(renderer, 0, 10 * i + 10, numbers[i]);
    }
}

void line(SDL_Renderer* renderer, int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    float k = dy / dx;
    int x = x1;
    int y = y1;
    while (x <= x2) {
        SDL_RenderDrawPoint(renderer, x, y);
        if (dx < 0)
            x--;
        else
            x++;
        y += int(k);
    }
    SDL_RenderPresent(renderer);
}

void line_SDL(SDL_Renderer* renderer, float x1, float y1, float x2, float y2)
{
    int iX1 = roundf(x1);
    int iY1 = roundf(y1);
    int iX2 = roundf(x2);
    int iY2 = roundf(y2);
    int deltaX = abs(iX1 - iX2);
    int deltaY = abs(iY1 - iY2);
    int len = fmax(deltaX, deltaY);
    if (len == 0) {
        SDL_RenderDrawPoint(renderer, iX1, iY1);
        return;
    }
    double dx = (x2 - x1) / len;
    double dy = (y2 - y1) / len;
    double x = x1;
    double y = y1;
    len++;
    while (len--) {
        x += dx;
        y += dy;
        SDL_RenderDrawPoint(renderer, roundf(x), roundf(y));
    }
}

int main(int argc, char* args[])
{
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(WINDOW_SIZE, WINDOW_SIZE, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 139, 0, 255, 0);
    /*line(renderer, 500, 100, 600, 500);
    line(renderer, 400, 500, 500, 100);
    it_horizontalLine(renderer, 300, 200, 400);
    line(renderer, 300, 200, 600, 500);
    line(renderer, 400, 500, 700, 200);*/
    line_SDL(renderer, 500, 500, 400, 500);
    line_SDL(renderer, 500, 500, 600, 500);
    line_SDL(renderer, 500, 500, 500, 400);
    line_SDL(renderer, 500, 500, 500, 600);
    line_SDL(renderer, 500, 500, 430, 470);
    line_SDL(renderer, 500, 500, 570, 530);
    line_SDL(renderer, 500, 500, 470, 430);
    line_SDL(renderer, 500, 500, 530, 570);
    line_SDL(renderer, 500, 500, 530, 430);
    line_SDL(renderer, 500, 500, 470, 570);
    line_SDL(renderer, 500, 500, 430, 530);
    line_SDL(renderer, 500, 500, 570, 470);

    SDL_RenderPresent(renderer);
    SDL_Delay(10000);
    return 0;
}