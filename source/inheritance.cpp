/*
   This is a simple example of inheritance in C++.

   Inheritance is a fundamental concept in object-oriented programming (OOP) where a class (subclass)
   inherits properties and behaviors (methods) from another class (superclass). In C++, inheritance is
   represented by the colon (:) notation.

   In this example:
   - The class 'Animal' serves as the superclass, defining common behaviors shared by all animals.
   - The class 'Carnivore' inherits from 'Animal', extending its functionality with carnivore-specific behaviors.
   - The class 'Lion' inherits from 'Carnivore', further extending the hierarchy with lion-specific behaviors.

   This hierarchy illustrates the "is-a" relationship, where a lion "is-a" carnivore, and a carnivore "is-a" animal.
   Through inheritance, code reuse is facilitated, as common behaviors and properties are defined in the base class
   and can be inherited by derived classes.

   Each class in the hierarchy overrides the 'print()' method to provide a hierarchical representation of the class names.
*/

#include <iostream>

class Animal
{
public:
   void awake()
   {
      std::cout << "Animal is awake" << std::endl;
   }

   void sleep()
   {
      std::cout << "Animal is sleeping" << std::endl;
   }

   void print()
   {
      std::cout << "Animal" << std::endl;
   }
};

class Carnivore : public Animal
{
public:
   void hunt()
   {
      std::cout << "Carnivore is hunting" << std::endl;
   }

   void print()
   {
      Animal::print(); // Call base class's print() method
      std::cout << "Carnivore" << std::endl;
   }
};

class Lion : public Carnivore
{
public:
   void roar()
   {
      std::cout << "Lion is roaring" << std::endl;
   }

   void print()
   {
      Carnivore::print(); // Call base class's print() method
      std::cout << "Lion" << std::endl;
   }
};

int main()
{
   Lion lion;
   lion.awake(); // Inherited from Animal
   lion.sleep(); // Inherited from Animal
   lion.hunt();  // Inherited from Carnivore
   lion.roar();  // Specific to Lion
   lion.print(); // Calls Lion's print() method

   return 0;
}