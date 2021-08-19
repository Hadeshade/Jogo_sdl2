#include "Vector2D.h"


float Vector2D::getX()
{
    return m_x;
}

float Vector2D::getY()
{
    return m_y;
}

void Vector2D::setX(float x) 
{
    m_x = x;
}

void Vector2D::setY(float y) 
{
    m_y = y;
}

// Retorna o comprimento
float Vector2D::length()
{
    return sqrt(m_x * m_x + m_y * m_y );
}

// Sobrecarrega o operador de soma
Vector2D Vector2D::operator+(const Vector2D& v2)
{
    return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
}

// Sobrecarrega o operador de soma e igual
Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
{
    v1.m_x += v2.m_x;
    v1.m_y += v2.m_y;

    return v1;
}

// Sobrecarrega o operador de multiplicação por escalar
Vector2D Vector2D::operator*(float scalar)
{
    return Vector2D(m_x * scalar, m_y * scalar);
}

// Sobrecarrega o operador de multiplicação e igual por escalar
Vector2D& Vector2D::operator*=(float scalar)
{
    m_x *= scalar;
    m_y *= scalar;

    return *this;
}

// Sobrecarrega o operador de subtrair
Vector2D Vector2D::operator-(const Vector2D& v2) const
{
    return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
}

// Sobrecarrega o operador de subtrair e igualar
Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
{
    v1.m_x -= v2.m_x;
    v1.m_y -= v2.m_y;

    return v1;
}

// Sobrecarrega o operador de divisão por escalar
Vector2D Vector2D::operator/(float scalar)
{
    return Vector2D(m_x / scalar, m_y / scalar);
}

// Sobrecarrega o operador de divisão e igual por escalar
Vector2D& Vector2D::operator/=(float scalar)
{
    m_x /= scalar;
    m_y /= scalar;

    return *this;
}

void Vector2D::normalize()
{
    float l = length();
    if(l>0)
    {
        (*this) *= 1/l;
    }
}