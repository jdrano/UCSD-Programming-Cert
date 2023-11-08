// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 10/31/23
// Shapes.cpp
// Win10
// Visual Studio 2022
// Implementations for derived classes of Shape

#include <iostream>
#include "Shapes.h"

using namespace std;

// PI constant for circular area and volume.
constexpr double PI = 3.14159265358979323846;

// Ints const necessary for sphere volume.
const int THREE = 3;
const int FOUR = 4;

// Ints const necessary for cube volume.
const int SIX = 6;

/*******************************************************************************
* Implementations for Circle class
*******************************************************************************/

// Constructor
JoseMedrano::Circle::Circle(double radius) {
    this->radius = radius;
}

// Displays object data
void
JoseMedrano::Circle::display() const {
    cout << "Circle with radius " << radius << " has area " 
        << getArea() << '\n';
}

// Returns the area of object
double
JoseMedrano::Circle::getArea() const {
    return radius*radius*PI;
}

/*******************************************************************************
* Implementations for Square class
*******************************************************************************/

// Constructor
JoseMedrano::Square::Square(double length) {
    this->length = length;
}

// Displays object data
void
JoseMedrano::Square::display() const {
    cout << "Square with length " << length << " has area "
        << getArea() << '\n';
}

// Returns the area of object
double
JoseMedrano::Square::getArea() const {
    return length*length;
}

/*******************************************************************************
* Implementations for Sphere class
*******************************************************************************/

// Constructor
JoseMedrano::Sphere::Sphere(double radius) {
    this->radius = radius;
}

// Displays object data
void
JoseMedrano::Sphere::display() const {
    cout << "Sphere with radius " << radius << " has surface area "
        << getSurfaceArea() << " and volume " << getVolume() << '\n';
}

// Returns the area of object
double
JoseMedrano::Sphere::getSurfaceArea() const {
    return radius * radius * PI * FOUR;
}

// Returns the volume of object
double
JoseMedrano::Sphere::getVolume() const {
    return (FOUR * PI * radius * radius * radius) / THREE;
}

/*******************************************************************************
* Implementations for Cube class
*******************************************************************************/

// Constructor
JoseMedrano::Cube::Cube(double length) {
    this->length = length;
}

// Displays object data
void
JoseMedrano::Cube::display() const {
    cout << "Cube with length " << length << " has surface area "
        << getSurfaceArea() << " and volume " << getVolume() << '\n';
}

// Returns the area of object
double
JoseMedrano::Cube::getSurfaceArea() const {
    return SIX * length * length;
}

// Returns the volume of object
double
JoseMedrano::Cube::getVolume() const {
    return length * length * length;
}