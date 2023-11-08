// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 10/31/23
// Shapes.h
// Win10
// Visual Studio 2022
// Shapes class and member data. Includes derived classes 2D and 3D Shapes. 
// 2D shapes has 2 derived classes: circle and square. 3D shapes has 2 derived
// classes: Sphere and Cube.

#ifndef JOSEMEDRANO_SHAPE_H
#define JOSEMEDRANO_SHAPE_H

namespace JoseMedrano {
    
    /*******************************************************************************
    * Shape class declarations
    *******************************************************************************/
    class Shape {
    public:
        // Pure virtual function makes Shape an abstract class
        virtual void display() const = 0;

    };

    /***************************************************************************
    * TwoDimensionalShape class declarations
    ***************************************************************************/
    class TwoDimensionalShape : public Shape {
    public :
        // Pure virtual function makes 2DShape an abstract class
        virtual double getArea() const = 0;
    };

    /***************************************************************************
    * Circle class declarations
    ***************************************************************************/
    class Circle : public TwoDimensionalShape {
    public :
        // Constructor
        Circle(double radius);

        // Getter
        double getArea() const;

        // Display function
        void display() const;

    private:
        double radius;
    };

    /***************************************************************************
    * Square class declarations
    ***************************************************************************/
    class Square : public TwoDimensionalShape {
    public :
        // Constructor
        Square(double length);

        // Getter
        double getArea() const;

        // Display function
        void display() const;

    private : 
        double length;
    };

    /***************************************************************************
    * ThreeDimensionalShape class declarations
    ***************************************************************************/
    class ThreeDimensionalShape : public Shape {
    public :
        // Getters
        virtual double getSurfaceArea() const = 0;
        virtual double getVolume() const = 0;
    };

    /***************************************************************************
    * Sphere class declarations
    ***************************************************************************/
    class Sphere : public ThreeDimensionalShape {
    public :
        //Constructor
        Sphere(double radius);

        // Getters
        double getSurfaceArea() const;
        double getVolume() const;

        // Display function
        void display() const;

    private:
        double radius;
    };

    /***************************************************************************
    * Cube class declarations
    ***************************************************************************/
    class Cube : public ThreeDimensionalShape {
    public : 
        // Construcutor
        Cube(double length);

        // Getters
        double getSurfaceArea() const;
        double getVolume() const;

        // Display function
        void display() const;

    private:
        double length;
    };
}
#endif