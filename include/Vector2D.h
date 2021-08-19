#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>

class Vector2D
{
    friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2);
private:
    float m_x;
    float m_y;
public:
    Vector2D(float x, float y):m_x(x), m_y(y){}
    
    float getX();
    float getY();
    float length();

    void setX(float x);
    void setY(float y);

    Vector2D operator+(const Vector2D& v2);
     
    Vector2D operator*(float scalar);
    Vector2D& operator*=(float scalar);
    Vector2D operator-(const Vector2D& v2) const;
     
    Vector2D operator/(float scalar);
    Vector2D& operator/=(float scalar);
    void normalize();
};

#endif