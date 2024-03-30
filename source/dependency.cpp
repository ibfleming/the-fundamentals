/*
   This program will demonstrate the concept of dependency.

   Dependency refers to the reliance of one class (or module) on another class (or module) to fulfill its functionality or carry out its tasks. 
   It occurs when one class uses objects, services, or interfaces provided by another class. 
   Dependencies are established when one class directly references or depends on another class in its implementation.
*/

#include <iostream>
#include <string>

class Car {
private:
   std::string model;
public:
   Car(const std::string& model) : model(model) {}

   void start() {
      std::cout << "the " << model << " car." << std::endl;
   }
};

class Driver {
private:
   std::string name;
   Car car;
public:
   Driver(const std::string& name, const std::string& model) : name(name), car(model) {}

   void drive() {
      std::cout << name << " is driving ";
      car.start();
   }
};

int main() {
   Driver driver("Alice", "Toyota");

   driver.drive();

   return 0;
}