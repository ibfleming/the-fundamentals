/*
   This program will demonstrate polymorphism, where a derived class can be
   treated as its base class.
*/

#include <iostream>

// Base class
class Shape {
public:
   virtual double area () const {   // Virtual function to calculate area
      return 0;
   }

   virtual void display() const {   // Virtual function to display information
      std::cout << "Shape" << std::endl;
   }
};

// Derived class Circle
class Circle : public Shape {
private:
   double radius;
public:
   Circle(double r) : radius(r) {}

   double area() const override {   // Override area() function
      return 3.14159 * radius * radius;
   }

   void display() const override {  // Override display() function
      std::cout << "Circle" << std::endl;
   }

   void display(int precision) const {  // Overload display() function
      std::cout.precision(precision);
      std::cout << "Circle with radius: " << std::fixed << radius << std::endl;
   }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
   double length;
   double width;
public:
   Rectangle(double l, double w) : length(l), width(w) {}

   double area() const override {   // Override area() function
      return length * width;
   }

   void display() const override {  // Override display() function
      std::cout << "Rectangle" << std::endl;
   }
};

int main() {
   Shape* shapes[2];    // Array of pointers to Shape objects
   Circle circle(5.0);
   shapes[0] = new Circle(5.0);   // Create Circle object and assign to shapes[0] pointer where Shape is the base class
   shapes[1] = new Rectangle(4.0, 6.0); // Create Rectangle object and assign to shapes[1] pointer where Shape is the base class

   circle.display();  
   circle.display(0); // Call Circle's overloaded display() function

   for(int i = 0; i < 2; ++i) {
      shapes[i]->display();
      std::cout << "Area: " << shapes[i]->area() << std::endl;
   }


   // Clean pointers
   for(int i = 0; i < 2; ++i) {
      delete shapes[i];
   }

   return 0;
}