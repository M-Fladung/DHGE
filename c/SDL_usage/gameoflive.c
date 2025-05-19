#include "sdlinterf.h"

#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char feld[SDL_X_SIZE][SDL_Y_SIZE];
int nachbar[SDL_X_SIZE][SDL_Y_SIZE];

void caculateneighbours()
{
  for (int i = 1; i < SDL_X_SIZE-1; i++)
  {
    for (int j = 1; j < SDL_Y_SIZE-1; j++)
    {
      nachbar[i][j] =  feld[i + 1][j] + feld[i + 1][j + 1] + feld[i + 1][j - 1] + feld[i][j + 1] + 
                       feld[i - 1][j] + feld[i - 1][j - 1] + feld[i - 1][j + 1] + feld[i][j - 1];
    }
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, "Error, bitte gib nur einen Bevölkerungsfaktor an!");
    return 1;
  }
  srand(time(NULL));
  int mutationsfaktor = atoi(argv[1]);
  sdlInit();
  // felder random vergeben genau 1x
  for (int i = 1; i < SDL_X_SIZE - 1; i++)
  {
    for (int j = 1; j < SDL_Y_SIZE - 1; j++)
    {
      if (i == 0 || j == 0 || i == (SDL_X_SIZE - 1) || j == (SDL_Y_SIZE - 1))
      {
        feld[i][j] = 0;
      }
      else
      {
        feld[i][j] = rand() % 2;
      }
    }
  }


  while (1)
  {
    sdlSetBlack();
    caculateneighbours();
    for (int i = 1; i < SDL_X_SIZE - 1; i++)
    {
      for (int j = 1; j < SDL_Y_SIZE - 1; j++)
      {
        if (feld[i][j] == 1)
        {
          if (nachbar[i][j] == 2 || nachbar[i][j] == 3)
          {
            sdlDrawPoint(i, j, 255, 0, 0);
          }
          else
          {
            feld[i][j] = 0;
          }
        }
        else
        {
          if (nachbar[i][j] == 3 || (mutationsfaktor > 0) && (rand() % mutationsfaktor == 0))
          {
            feld[i][j] = 1;
            sdlDrawPoint(i, j, 255, 255, 0);
          }
        }
      }
    }
    sdlUpdate();
  sdlMilliSleep(100);
  }
  sdlExit();

  exit(EXIT_SUCCESS);
}