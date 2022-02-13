#include <iostream> 
#include <SDL.h> 
#include <vector> 
#define WINDOW_SIZE 1000

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

//void line(SDL_Renderer* renderer, int x1, int y1, int x2, int y2)
//{
//    int x, y;
//    int dx = x2 - x1;
//    int dy = y2 - y1;
//    int d = (dy * 2) - dx;
//    int d1 = dy * 2;
//    int d2 = (dy - dx) * 4;
//    x = x1;
//    y = y1;
//    SDL_RenderDrawPoint(renderer, x1, y1);
//    SDL_RenderDrawPoint(renderer, x2, y2);
//    while (x < x2) {
//        x++;
//        if (d < 0)
//            d += d1;
//        else {
//            y++;
//            d += d2;
//        }
//        SDL_RenderDrawPoint(renderer, x, y);
//    }
//}

int main(int argc, char* args[])
{
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(WINDOW_SIZE, WINDOW_SIZE, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    line(renderer, 500, 100, 600, 500);
    line(renderer, 400, 500, 500, 100);
    it_horizontalLine(renderer, 300, 200, 400);
    line(renderer, 300, 200, 600, 500);
    line(renderer, 400, 500, 700, 200);

    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    return 0;
}