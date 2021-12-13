#ifndef SHAPE_H
#define SHAPE_H

#ifdef __cplusplus
#include <string>

class Shape
{
public:
    Shape(int length,int height,std::string type);
    virtual ~Shape();
    virtual float getArea();
    virtual float getPerimeter();

    float getLength();
    float getHeight();
    std::string getType();
protected:
    float m_length;
    float m_height;
    std::string m_type;
};

class Square:public Shape
{
public:
    Square(int length,int height,std::string type);
    ~Square() override;
    float getArea() override;
    float getPerimeter() override;
};

class Circle:public Shape
{
public:
    Circle(int length,int height,std::string type);
    ~Circle() override;
    float getArea() override;
    float getPerimeter() override;
};

class RightTriangle:public Shape
{
public:
    RightTriangle(int length,int height,std::string type);
    ~RightTriangle() override;
    float getArea() override;
    float getPerimeter() override;
};
#else
typedef struct Shape Shape;
#endif


#ifdef __cplusplus
extern "C"{
#endif

Shape* shape_item_init(float length,float height,const char* strtype);
float shape_item_get_area(Shape* self);
float shape_item_get_perimeter(Shape* self);
float shape_item_get_length(Shape* self);
float shape_item_get_height(Shape* self);
const char* shape_item_get_type(Shape* self);
void shape_item_release(Shape* self);

#ifdef __cplusplus
}   // extern "C"
#endif

#endif //SHAPE_H