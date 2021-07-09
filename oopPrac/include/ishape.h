#ifndef I_SHAPE_H
#define I_SHAPE_H

typedef struct _IShape
{
    int (*get_area)();
    int (*get_perimeter)();
    int (*get_width)();
    int (*get_height)();
}IShape,*pIShape;

void ishape_release(void** self);

#endif //I_SHAPE_H