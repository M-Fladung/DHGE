#include <cstdlib>
#include <ctime>


#include "../sdlinterf.h"
#include "rectangle.h"

using namespace std;

const int ARRSIZE = 10;

int number_of_objects = 0;

int main(void)
{
    srand(time(nullptr));
    sdlInit();

    {

        Rectangle *p[ARRSIZE];

        for (int i = 0; i < ARRSIZE; i++)
        {
            p[i] = new Rectangle(
                       Color(rand() % 192 + 64, rand() % 192 + 64, rand() % 192 + 64),
                       SDL_X_SIZE / 2, SDL_Y_SIZE / 2,
                       rand() % 30 + 1, rand() % 30 + 1,
                       ((rand() % 10) + 1 - ((rand() % 2) * (10 + 1))), (((rand() % 10) + 1) - ((rand() % 2) * (10 + 1)))
                    );

            number_of_objects++;
        }

        while (number_of_objects != 0)
        {
            sdlMilliSleep(2);
            sdlUpdate();
            for (int i = 0; i < ARRSIZE; i++)
            {
                if (p[i] == nullptr)
                {
                    continue;
                }
                else
                {
                    
                    if (!p[i]->fly(true))
                    {

                        p[i]->scale(0.90, 0.90);

                        if ((p[i]->getsizeX()) <= 0 || (p[i]->getsizeY()) <= 0)
                        {
                            delete (p[i]);
                            p[i] = nullptr;
                            number_of_objects--;
                        }
                    }
                }
            }
        }
    }

    sdlExit();

    exit(EXIT_SUCCESS);
}