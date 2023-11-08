// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 10/31/23
// hw5.cpp
// Win10
// Visual Studio 2022
// Main tests inheritance and virtual functions of Shape class.

#include <iostream>
#include "Shapes.h"

using namespace std;
using namespace JoseMedrano;

const int NUM_SHAPES = 4;

int main() {

    // Initialize shape array with size NUM_SHAPES
    Shape *shapes[NUM_SHAPES];

    // Creation of test objects
    Circle* a = new Circle(2.0);
    Square* b = new Square(3.0);
    Sphere* c = new Sphere(4.0);
    Cube* d = new Cube(5.0);

    // Assigning shape ptrs to ptr of test objects
    shapes[0] = a;
    shapes[1] = b;
    shapes[2] = c;
    shapes[3] = d;

    // Use display function for each object, then delete
    for (int curr_shape = 0; curr_shape < NUM_SHAPES; curr_shape++) {
        shapes[curr_shape]->display();
        delete shapes[curr_shape];
    }
    
    return 0;
}