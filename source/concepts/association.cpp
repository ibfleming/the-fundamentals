/*
   This program will demonstrate association, where two classes are related in such a way that they can exist independently.
   The definition of association is that a class can have a member that is an object of another class, but the two classes are not part of a hierarchy.
*/

#include <iostream>
#include <string>
#include <vector>

// Forward declaration of class
class Student;

// Class representing a course
class Course {
private:
   std::string name;
   std::vector<Student *> students; // Vector of pointers to Student objects
public:
   Course(const std::string& courseName) : name(courseName) {}

   // Method to add a student to the course
   void addStudent(Student* student) {
      students.push_back(student);
   }

   // Method to display course information and enrolled students
   void display() const;

   ~Course();
};

// Class representing a student
class Student {
private:
   std::string name;
public:
   Student(const std::string& studentName) : name(studentName) {}

   // Getter method to get student name
   std::string getName() const {
      return name;
   }
};

// Implementation of display() method for Course class
void Course::display() const {
   std::cout << "Course: " << name << std::endl;
   std::cout << "Enrolled Students:" << std::endl;
   for (const auto& student : students) {
      std::cout << "- " << student->getName() << std::endl;
   }
}

// Destructor for Course class
Course::~Course() {
   std::cout << "Destructor called!" << std::endl;
   for (auto& student : students) {
      delete student; // Delete dynamically allocated Student objects
   }
}

int main() {
   // Create Course object
   Course course("C++ Programming");

   // Create Student objects
   Student* student1 = new Student("Alice");
   Student* student2 = new Student("Bob");
   Student* student3 = new Student("Sierra");
   Student* student4 = new Student("Ian");

   // Add students to the course
   course.addStudent(student1);
   course.addStudent(student2);
   course.addStudent(student3);
   course.addStudent(student4);

   // Display course information
   course.display();

   return 0;
}