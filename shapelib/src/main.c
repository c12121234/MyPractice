#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shape.h"

int main(int argc,char* argv[])
{
    Shape* arr[3] = {0};
    arr[0] = shape_item_init(7.0,7.0,"square");
    arr[1] = shape_item_init(10.0,10.0,"circle");
    arr[2] = shape_item_init(3.0,4.0,"righttriangle");

    for(int i = 0;i<3;++i)
    {
        char* temp_buf = NULL;
        temp_buf = shape_item_get_type(arr[i]);
        printf("type :%s\n",temp_buf);
        printf("area :%f\n",shape_item_get_area(arr[i]));
        printf("perimeter :%f\n",shape_item_get_perimeter(arr[i]));
        printf("length :%f\n",shape_item_get_length(arr[i]));
        printf("height :%f\n",shape_item_get_height(arr[i]));

        shape_item_release(arr[i]);
    }

    return 0;
}