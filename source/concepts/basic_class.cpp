/*
   This is a simple class example in C++.
   A class is a blueprint for creating objects.
   It defines the properties and behaviors common to all objects of a certain kind.
   It contains data members (variables) and member functions (methods).
*/

/*
   *Encapsulation* in this code ensures that the internal state of the ExampleClass
   is hidden from external access. Data members 'name', 'x', and 'y' are declared
   as private, restricting direct modification or access from outside the class.
   This protects the integrity of the object's data and allows controlled access
   through public member functions such as the constructor, sum(), and print().
   By encapsulating the implementation details, the class provides a clear interface
   for interacting with objects, promoting modularity, flexibility, and maintainability.
*/

/*
   Abstraction in this code focuses on presenting only essential features of the ExampleClass
   while hiding the complex implementation details. The class interface exposes methods
   such as the constructor, sum(), and print(), which provide high-level functionalities
   without revealing the underlying logic of how these operations are performed. Users interact
   with the class through these abstracted methods, without needing to understand the internal
   workings of the class. This abstraction simplifies the usage of the class, promotes
   code readability, and facilitates future modifications or enhancements to the class
   implementation without affecting its external behavior.
*/

#include <iostream>
#include <string>

class ExampleClass
{
private:
   std::string name = "ExampleClass";
   int x;
   int y;

public:
   ExampleClass(int x, int y)
   {
      this->x = x;
      this->y = y;
   }

   ~ExampleClass()
   {
      // Destructor
   }

   int sum()
   {
      return x + y;
   }

   void print()
   {
      std::cout << "OBJECT of ";
      std::cout << "class: " << name << std::endl;
      std::cout << "x: " << x << std::endl;
      std::cout << "y: " << y << std::endl;
   }
};

int main(int argc, char *argv[])
{
   ExampleClass obj(10, 20);
   obj.print();
   std::cout << std::endl;
   std::cout << "Sum: " << obj.sum() << std::endl;
   return 0;
}