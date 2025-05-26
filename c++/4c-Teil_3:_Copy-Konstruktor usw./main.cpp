#include <cstdlib>
#include <ctime>

#include "../sdlinterf.h"


#include "rectangle.h"

using namespace std;

const int objCnt = 40;

inline int randPos(int range, int dist)
{
  return dist + rand() % (range - 2 * dist);
}

int main(void)
{
  srand(time(nullptr));
  sdlInit();

  Rectangle *obj[objCnt];

  obj[0] = new Rectangle(Color(255, 255, 0),
                    SDL_X_SIZE / 2, SDL_Y_SIZE / 2,
                    SDL_X_SIZE / 5, SDL_Y_SIZE / 5);
  sdlUpdate();
  sdlMilliSleep(50);

  for (int i = 1; i < objCnt; ++i) {

    obj[i] = new Rectangle(*obj[i - 1]);

    obj[i]->setPos(randPos(SDL_X_SIZE, obj[i]->getW()),
                   randPos(SDL_Y_SIZE, obj[i]->getH()));
    sdlUpdate();
    sdlMilliSleep(50);
  }

  obj[objCnt - 1]->setPos(SDL_X_SIZE / 4, SDL_Y_SIZE / 2);
  sdlUpdate();
  sdlMilliSleep(50);
  for (int i = objCnt - 2; i >= 0; --i) {
    obj[i]->moveOnTop(*obj[i + 1]);
    sdlUpdate();
    sdlMilliSleep(50);
  }

  obj[0]->setPos(3 * SDL_X_SIZE / 4, SDL_Y_SIZE / 2);
  sdlUpdate();
  sdlMilliSleep(100);
  for (int i = 1; i < objCnt; ++i) {
    obj[i]->moveOnTop(*obj[i - 1]);
    sdlUpdate();
    sdlMilliSleep(50);
  }

  for (int i = objCnt - 1; i >= 0; --i) {
    delete obj[i];
    sdlUpdate();
    sdlMilliSleep(50);
  }

  sdlExit();

  exit(EXIT_SUCCESS);
}