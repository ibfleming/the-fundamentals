/*
   This program will demonstrate aggregation.
   Aggregation is a type of association where one class contains objects of another class as member variables, 
   but the contained objects can exist independently of the container
*/

/*
   In the provided program, aggregation is exemplified through the interaction between the `Library` and `Book` classes. 
   The `Library` class serves as a container for `Book` objects, storing them within a vector as pointers. 
   Each `Book` object encapsulates information like the book's title and author. 
   Within the `Library` class, methods such as `addBook()` facilitate the addition of `Book` objects to the library's collection, 
   while `displayBooks()` enables the presentation of book details. In the `main()` function, a `Library` object, `myLibrary`, is instantiated. 
   Through dynamic memory allocation, `Book` objects are created and incorporated into the library using the `addBook()` method. 
   This design demonstrates aggregation, wherein the `Library` class aggregates `Book` objects by containing references to them. 
   The `Library` class does not assume ownership of the `Book` objects; rather, it manages a collection of `Book` instances. 
   This showcases the essence of aggregation in object-oriented programming, 
   where objects are composed to form more complex structures without direct ownership or management.
*/

#include <iostream>
#include <vector>
#include <string>

// Forward declaration of class
class Book;

// Book class representing a book in the library
class Book {
private:
   std::string title;
   std::string author;
public:
   Book(const std::string& bookTitle, const std::string& bookAuthor) 
      : title(bookTitle), author(bookAuthor) {}

   std::string getTitle() const {
      return title;
   }

   std::string getAuthor() const {
      return author;
   }
};

// Library class representing a library containing books
class Library {
private:
   std::vector<Book *> books; // Vector of pointers to Book objects
public:
   ~Library() {
      // Clean up dynamically allocated Book objects
      for(auto& book : books) {
         delete book;
      }
   }

   void addBook(Book* book) {
      books.push_back(book);
   }

   void displayBooks() const {
      std::cout << "Books in the library:" << std::endl;
      for(const auto& book : books) {
         std::cout << "Title: " << book->getTitle() << ", Author: " << book->getAuthor() << std::endl;
      }
   }
};

int main() {

   Library library;

   library.addBook(new Book("The Great Gatsby", "F. Scott Fitzgerald"));
   library.addBook(new Book("To Kill a Mockingbird", "Harper Lee"));
   library.addBook(new Book("1984", "George Orwell"));
   library.addBook(new Book("The Holy Bible", "Lord God Almighty"));

   library.displayBooks();

   return 0;
}