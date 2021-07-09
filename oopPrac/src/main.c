#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "square.h"
#include "triangle.h"

int main(int argc,char* argv[])
{
    pSquare square = init_Square(10,4);
    pIShape ip_square = Square_to_IShape();

    pTriangle triangle = init_Triangle(3,4);
    pIShape ip_triangle = Triangle_to_IShape();

    pIShape ip_arr[2] = {ip_square,ip_triangle};
    void* obj_arr[2] = {(void*)square,(void*)triangle};

    for(int i = 0;i<2;++i)
    {
        printf("width:%d\n",ip_arr[i]->get_width(obj_arr[i]));
        printf("height:%d\n",ip_arr[i]->get_height(obj_arr[i]));
        printf("perimeter:%d\n",ip_arr[i]->get_perimeter(obj_arr[i]));
        printf("area:%d\n",ip_arr[i]->get_area(obj_arr[i]));
    }

    
    
    release_Square(&square);
    release_Triangle(&triangle);
    ishape_release((void*)&ip_square);
    ishape_release((void*)&ip_triangle);
    printf("square: %p \n",square);
    printf("&square: %p \n",&square);
    printf("triangle: %p \n",triangle);
    printf("&triangle: %p \n",&triangle);
    printf("ip_square: %p \n",ip_square);
    printf("&ip_square: %p \n",&ip_square);
    printf("ip_triangle: %p \n",ip_triangle);
     printf("&ip_triangle: %p \n",&ip_triangle);

    return 0;
}