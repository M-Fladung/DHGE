#include "sdlinterf.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[])
{
    if(argc != 9/*noch mal schauen*/){
        fprintf(stderr, "Eroor, bitte gib genau ... Werte an");
        return 1;
    }
    for(int i = 1; i < SDL_X_SIZE - 1; i++){
        for(int j = 1; j < SDL_Y_SIZE - 1; j++){
            
        }
    }
    return 0;
}