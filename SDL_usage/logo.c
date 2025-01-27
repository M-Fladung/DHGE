#include "sdlinterf.h"

#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[])
{
    if(SDL_X_SIZE < SDL_Y_SIZE) {
        int square[SDL_X_SIZE][SDL_X_SIZE];
    }else if(SDL_Y_SIZE < SDL_X_SIZE) {
        int square[SDL_Y_SIZE][SDL_Y_SIZE];
    }else{
        int square[SDL_X_SIZE][SDL_Y_SIZE];
    }
    
    sdlExit();

    exit(EXIT_SUCCESS);
}