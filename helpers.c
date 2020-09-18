#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

int int_random(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}
