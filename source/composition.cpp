/*
   This program will demonstrate composition, where a class is composed of other classes.
*/

#include <iostream>
#include <cstdio>
#include <string>

// Forward declarations of class
class Engine;
class Wheel;
class Body;

// Engine class
class Engine {
private:
   std::string type;
public:
   Engine(const std::string& engineType) : type(engineType) {}

   void start() {
      printf("Engine of type %s started\n", type.c_str());
   }
};

// Wheel class
class Wheel {
private:
   int size;
public:
   Wheel() : size(0) {}

   Wheel(int wheelSize) : size(wheelSize) {}

   void rotate() {
      printf("Wheel of size %d rotating\n", size);
   }
};

// Body class
class Body {
private:
   std::string color;
public:
   Body(const std::string& bodyColor) : color(bodyColor) {}

   void paint() {
      printf("Body painted %s\n", color.c_str());
   }
};

class Car {
private:
   Engine engine;
   Wheel wheels[4];
   Body body;
public:
   Car(const std::string& engineType, int wheelSize, const std::string& bodyColor)
      : engine(engineType), body(bodyColor) {
         for (int i = 0; i < 4; ++i) {
            wheels[i] = Wheel(wheelSize);
         }
      }

   void drive() {
      engine.start();
      for (int i = 0; i < 4; ++i) {
         wheels[i].rotate();
      }
      printf("Car is being driven\n");
   }

   void repaint(const std::string& newColor) {
      body.paint();
      printf("Car repainted to %s\n", newColor.c_str());
   }
};

int main() {
   Car car("V8", 22, "Red");
   car.drive();
   car.repaint("Blue");

   return 0;
}