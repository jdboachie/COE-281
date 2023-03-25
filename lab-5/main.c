#include <stdio.h>
#include <stdlib.h>

float areaofSquare(float side);
float areaofRectangle(float length, float width);
float areaofCircle(float radius);
float areaofTriangle(float base, float height);

int main()
{
    float area;

    printf("Shape 1\nIt contains a semi-circle and a rectangle.\n");
    area = circle(4) / 2 + rectangle(12, 8);
    printf("Area of shape 1 = %.2fft\n\n ", area);

    printf("Shape 2\nIt contains a rectangle and a square.\n");
    area = rectangle(11, 4) + square(5);
    printf("Area of shape 2 = %.2fft\n\n ", area);
    return 0;
}

float areaofSquare(float side)
{
    return side * side;
}

float areaofRectangle(float length, float width)
{
    return length * width;
}

float areaofCircle(float radius)
{
    return 3.14 * radius * radius;
}

float areaofTriangle(float base, float height)
{
    return 0.5 * base * height;
}
