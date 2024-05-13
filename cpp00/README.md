# C++ Programming Concepts

## Namespace
In C++, a namespace is a named scope that provides a logical grouping for the identifiers it contains. It helps in organizing the code by encapsulating related names within a named scope, thus preventing naming collisions and making the code more modular, maintainable, and readable.

- **Example**: Using namespace extensively (e.g., `using namespace std;`) is considered a bad practice as it can lead to name conflicts and make code less clear. Instead, prefer selectively importing symbols using `using` declarations or fully qualifying names.

## Object-Oriented Programming (OOP)
Object-oriented programming is a programming paradigm that revolves around the concept of objects, which encapsulate data and behavior. Here are some key terms related to OOP:

- **Class**: A class is a user-defined data type that defines a blueprint for objects. It encapsulates data members (attributes) and member functions (methods) to operate on that data.

- **Object**: An object is an instance of a class. It represents a tangible entity with specific characteristics (data) and behaviors (methods).

- **Constructor**: A constructor is a special member function of a class that is automatically called when an object is created. It initializes the object's data members. Types of constructors include default, parameterized, copy, and move constructors.

- **Destructor**: A destructor is a special member function of a class that is automatically called when an object is destroyed (e.g., when it goes out of scope). It releases resources allocated by the object and performs cleanup tasks.

- **Static Member**: A static member of a class is shared by all instances (objects) of the class. It is declared using the `static` keyword and is accessed using the class name, rather than through objects.

- **Static Member Function**: A static member function is a member function of a class that operates on static data members. It does not require an object to be invoked and can be called using the class name.

By following object-oriented principles, such as encapsulation, inheritance, and polymorphism, you can create more modular, reusable, and maintainable code.
