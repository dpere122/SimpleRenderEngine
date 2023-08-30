#include <iostream>
#include <string>
#include <SDL.h>
#include <stdio.h>

using namespace std;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
    //Window to be rendered to:
    SDL_Window* window = NULL;

    //The Surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize! SDL Error %s\n", SDL_GetError());
    }else{
        window = SDL_CreateWindow("Simple Render Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if(window ==  NULL){
            printf("Window could not be created! SDL_ERROR: %s\n",SDL_GetError());
        }else{
            //Get window Surface
            screenSurface = SDL_GetWindowSurface(window);
            //fill the surface white
            SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface ->format,0xFF,0xFF,0xFF));
            //Update the surface
            SDL_UpdateWindowSurface(window);
            //Hack the window to stay open
            SDL_Event e; bool quit = false; while(quit == false){while(SDL_PollEvent(&e)){if(e.type == SDL_QUIT) quit = true;}}

        }
    }

    return 0;
}