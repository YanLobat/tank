#include <enemy.h>
#include <time.h>
#include <cstdlib>

int Enemy::movement()
{
    srand(time(NULL));
    int val = rand()%5 + 1;
    return val;
}
