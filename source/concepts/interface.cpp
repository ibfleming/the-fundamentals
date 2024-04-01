/*
   This program will demonstrate interfaces in C++.

   An Interface defines a contract specifying a set of methods that classes must implement.
*/

#include <iostream>

// Interface class
class Drawable {
public:
   virtual void draw() const = 0;
   virtual ~Drawable() = default;
};

class Circle : public Drawable {
public:
   void draw() const override {
      std::cout << "Drawing a circle" << std::endl;
   }
};

class Rectangle : public Drawable {
public:
   void draw() const override {
      std::cout << "Drawing a rectangle" << std::endl;
   }
};

int main() {

   Circle circle;
   Rectangle rectangle;

   circle.draw();
   rectangle.draw();

   std::cout << std::boolalpha;
   std::cout << std::is_base_of<Drawable, Circle>::value << std::endl;
   std::cout << std::is_base_of<Drawable, Rectangle>::value << std::endl;


   return 0;
}