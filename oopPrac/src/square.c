#include <stdio.h>
#include <stdlib.h>
#include "square.h"

static int get_square_perimeter(void* self);
static int get_square_area(void* self);
static int get_square_width(void* self);
static int get_square_height(void* self);

static int get_square_perimeter(void* self)
{
    return get_perimeter((pSquare)self);
}

static int get_square_area(void* self)
{
    return get_area((pSquare)self);
}

static int get_square_width(void* self)
{
    return get_width((pSquare)self);
}

static int get_square_height(void* self)
{
    return get_height((pSquare)self);
}

pSquare init_Square(int width,int height)
{
    pSquare self = malloc(sizeof(Square));
    if (!self)
        return NULL;
    self->m_width = width;
    self->m_height = height;
    self->get_area = get_area;
    self->get_height = get_height;
    self->get_width = get_width;
    self->get_perimeter = get_perimeter;
    return self;
}

int get_perimeter(pSquare self)
{
    return (self->m_height+self->m_width)*2;
}

int get_area(pSquare self)
{
    return self->m_height * self->m_width;
}

int get_width(pSquare self)
{
    return self->m_width;
}
    
int get_height(pSquare self)
{
    return self->m_height;
}

int release_Square(pSquare* self)
{
    if(*self)
    {
        free(*self);
        *self = NULL;
    }
    return 0;
}

pIShape Square_to_IShape()
{
    pIShape ip = malloc(sizeof(IShape));
    ip->get_area = get_square_area;
    ip->get_height = get_square_height;
    ip->get_perimeter = get_square_perimeter;
    ip->get_width = get_square_width;
    return ip;
}