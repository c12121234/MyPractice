#include <iostream>
#include "shape.h"

using namespace std;

int main(int argc,char* argv[])
{
    Circle circle(5.0,5.0,"circle");
    Square square(10.0,10.0,"square");
    RightTriangle rtriangle(3.0,4.0,"righttriangle");

    Shape* arr[3] = {0};
    
    Shape* p1 = &circle;
    Shape* p2 = &square;
    Shape* p3 = &rtriangle;
    arr[0] = p1;
    arr[1] = p2;
    arr[2] = p3;

    for(int i = 0; i<3;++i)
    {
        cout<<"get area:"<<arr[i]->getArea()<<endl;
        cout<<"get perimeter:"<<arr[i]->getPerimeter()<<endl;
        cout<<"get height:"<<arr[i]->getHeight()<<endl;
        cout<<"get length:"<<arr[i]->getLength()<<endl;
        cout<<"get type:"<<arr[i]->getType()<<endl;
    }

    return 0;
}