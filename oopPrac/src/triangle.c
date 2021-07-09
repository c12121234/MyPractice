#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "triangle.h"

static int get_triangle_perimeter(void* self);
static int get_triangle_area(void* self);
static int get_triangle_width(void* self);
static int get_triangle_height(void* self);

static int get_triangle_perimeter(void* self)
{
    return get_triangle_perimeter_public((pTriangle)self);
}

static int get_triangle_area(void* self)
{
    return get_triangle_area_public((pTriangle)self);
}

static int get_triangle_width(void* self)
{
    return get_triangle_width_public((pTriangle)self);
}

static int get_triangle_height(void* self)
{
    return get_triangle_height_public((pTriangle)self);
}

pTriangle init_Triangle(int width,int height)
{
    pTriangle self = malloc(sizeof(Triangle));
    if (!self)
        return NULL;
    self->m_width = width;
    self->m_height = height;
    self->get_area = get_triangle_area_public;
    self->get_height = get_triangle_height_public;
    self->get_width = get_triangle_width_public;
    self->get_perimeter = get_triangle_perimeter_public;
    return self;
}

int get_triangle_perimeter_public(pTriangle self)
{
    double third_side = sqrt(pow(self->m_height,2)+pow(self->m_width,2));

    return third_side + self->m_height + self->m_width;
}

int get_triangle_area_public(pTriangle self)
{
    return (self->m_height * self->m_width)/2;
}

int get_triangle_width_public(pTriangle self)
{
    return self->m_width;
}
    
int get_triangle_height_public(pTriangle self)
{
    return self->m_height;
}

int release_Triangle(pTriangle* self)
{
    if(*self)
    {
        free(*self);
        *self = NULL;
    }
    return 0;
}

pIShape Triangle_to_IShape()
{
    pIShape ip = malloc(sizeof(IShape));
    ip->get_area = get_triangle_area;
    ip->get_height = get_triangle_height;
    ip->get_perimeter = get_triangle_perimeter;
    ip->get_width = get_triangle_width;
    return ip;
}