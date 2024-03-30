/*
   This program will demonstrate a Singleton in C++.

   A Singleton is a design pattern that ensures a class has only one instance and provides a global point of access to that instance. 
   It's commonly used when exactly one object is needed to coordinate actions across the system.
*/

#include <iostream>

class Singleton {
public:
   static Singleton& get_instance() {
      static Singleton instance; // Static local variable ensures it's initialized only once
      return instance;
   }

   void show_message() {
      std::cout << "Hello, I'm a Singleton!" << std::endl;
   }
private:
   Singleton() = default;
   ~Singleton() = default;
   Singleton(const Singleton&) = delete;              // Delete copy constructor
   Singleton& operator=(const Singleton&) = delete;   // Delete copy assignment operator
};

int main() {

   Singleton& singleton = Singleton::get_instance();
   singleton.show_message();

   return 0;
}