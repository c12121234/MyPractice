#include <cmath>
#include <iostream>
#include <string>
#include "shape.h"

using namespace std;

Shape::Shape(int length,int height,string type):m_length(length),
    m_height(height),m_type(type)
{
    cout<<"shape ctor"<<endl;
}

float Shape::getArea()
{
    return 0;
}

float Shape::getPerimeter()
{
    return 0;
}

float Shape::getLength()
{
    return m_length;
}

float Shape::getHeight()
{
    return m_height;
}

string Shape::getType()
{
    return m_type;
}

Shape::~Shape()
{
    cout<<"shape dtor"<<endl;
}

Square::Square(int length,int height,string type):Shape(length,height,type)
{
    cout<<"Square ctor"<<endl;
}

float Square::getArea()
{
    return m_length*m_length;
}

float Square::getPerimeter()
{
    return (m_length+m_height)*2;
}

Square::~Square()
{
    cout<<"Square dtor"<<endl;
    //this->Shape::~Shape();
}

Circle::Circle(int length,int height,string type):Shape(length,height,type)
{
    cout<<"Circle ctor"<<endl;
}

float Circle::getArea()
{
    return (m_length/2)*(m_length/2)*3.14;
}

float Circle::getPerimeter()
{
    return m_length*3.14;
}

Circle::~Circle()
{
    cout<<"Circle dtor"<<endl;
    //this->Shape::~Shape();
}

RightTriangle::RightTriangle(int length,int height,string type):Shape(length,height,type)
{
    cout<<"RightTriangle ctor"<<endl;
}

float RightTriangle::getArea()
{
    return m_length*m_height/2;
}

float RightTriangle::getPerimeter()
{
    float side = sqrt(pow(m_length,2)+pow(m_height,2));
    return m_length+m_height+side;
}

RightTriangle::~RightTriangle()
{
    cout<<"RightTriangle dtor"<<endl;
    //this->Shape::~Shape();
}


Shape* shape_item_init(float length,float height,const char* strtype)
{
    string strText(strtype);
    Shape* p_shape = nullptr;
    if(strText == "square")
    {
        p_shape = new Square(length,height,strText);
    }
    else if(strText == "circle")
    {
        p_shape = new Circle(length,height,strText);
    }
    else if(strText == "righttriangle")
    {
        p_shape = new RightTriangle(length,height,strText);
    }

    return p_shape;
}

float shape_item_get_area(Shape* self)
{
    return self->getArea();
}

float shape_item_get_perimeter(Shape* self)
{
    return self->getPerimeter();
}

float shape_item_get_length(Shape* self)
{
    return self->getLength();
}

float shape_item_get_height(Shape* self)
{
    return self->getHeight();
}

const char* shape_item_get_type(Shape* self)
{
    string temp = self->getType();
    return temp.c_str();
}

void shape_item_release(Shape* self)
{
    if(self)
    {
        delete self;
        self = nullptr;
    }
}