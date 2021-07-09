#include <stdlib.h>
#include "ishape.h"

void ishape_release(void** self)
{
    if(*self)
    {
        free(*self);
        *self = NULL;
    }        
}