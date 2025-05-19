#include <stdbool.h>

bool foo(int parameter)
{
    if((parameter % 5) == 0) {return true;}
    if ((parameter % 3) == 0) {return true;}
    if ((parameter % 7) == 0) {return true;} 
}