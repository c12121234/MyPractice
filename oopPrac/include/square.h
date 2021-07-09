#ifndef SQUARE_H
#define SQUARE_H
#include "ishape.h"

typedef struct _Square Square,*pSquare;

struct _Square
{
//public:
    int (*get_perimeter)(pSquare);
    int (*get_area)(pSquare);
    int (*get_width)(pSquare);
    int (*get_height)(pSquare);
//private:
    int m_width;
    int m_height;

};

pSquare init_Square(int width,int height);
int release_Square(pSquare* self);

int get_perimeter(pSquare self);
int get_area(pSquare self);
int get_width(pSquare self);
int get_height(pSquare self);

pIShape Square_to_IShape();

#endif //SQUARE_H