#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "ishape.h"

typedef struct _Triangle Triangle,*pTriangle;

//right triangle
struct _Triangle
{
//public:
    int (*get_perimeter)(pTriangle);
    int (*get_area)(pTriangle);
    int (*get_width)(pTriangle);
    int (*get_height)(pTriangle);
//private:
    int m_width;
    int m_height;
};

pTriangle init_Triangle(int width,int height);
int release_Triangle(pTriangle* self);

int get_triangle_perimeter_public(pTriangle self);
int get_triangle_area_public(pTriangle self);
int get_triangle_width_public(pTriangle self);
int get_triangle_height_public(pTriangle self);

pIShape Triangle_to_IShape();


#endif //TRIANGLE_H