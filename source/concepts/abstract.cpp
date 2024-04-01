/*

   This program will demonstrate the concept of abstraction or abstract classes.

   An abstract class in object-oriented programming is a class that cannot be instantiated 
   and may contain one or more abstract methods, which must be implemented by its concrete subclasses.

*/

#include <iostream>
#include <string>

class Human {
public:
   virtual void speak() const = 0;
   virtual void display() const = 0;
};

class Adam : public Human {
private:
   std::string name;
   std::string sex;
public:
   Adam(const std::string& name, const std::string& sex) : name(name), sex(sex) {}

   void speak() const override {
      std::cout << "I am Adam, the first human created by God." << std::endl;
   }

   void display() const override {
      std::cout << "Name: " << name << ", Sex: " << sex << std::endl;
   }
};

class Eve : public Human {
private:
   std::string name;
   std::string sex;
public:
   Eve(const std::string& name, const std::string& sex) : name(name), sex(sex) {}

   void speak() const override {
      std::cout << "I am Eve, I was created from one of Adam's ribs to serve as his loyal helper by God." << std::endl;
   }

   void display() const override {
      std::cout << "Name: " << name << ", Sex: " << sex << std::endl;
   }
};

int main() {
   Adam adam("Adam", "Male");
   Eve eve("Eve", "Female");

   adam.display();
   adam.speak();

   eve.display();
   eve.speak();

   return 0;
}