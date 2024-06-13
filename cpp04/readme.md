### Polymorphism:
The word “polymorphism” means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form. A real-life example of polymorphism is a person who at the same time can have different characteristics. A man at the same time is a father, a husband, and an employee. So the same person exhibits different behavior in different situations. This is called polymorphism. Polymorphism is considered one of the important features of Object-Oriented Programming.

### Types of Polymorphism
- Compile-time Polymorphism
- Runtime Polymorphism

*Function Overloading* is a feature in C++ where multiple functions can have the same name but different parameters (either in number, types, or both). Overloading is resolved at compile time based on the function signature (i.e., the number and type of arguments).

*Function Overriding* occurs in the context of inheritance. It allows a derived class to provide a specific implementation of a method that is already defined in its base class. Overriding is resolved at runtime using dynamic binding (polymorphism).

```
+---------------------------------------+       +------------------+
| class Animal {                        |       | Dog Vtable       |
|   _vptr;                              |       +------------------+
|   virtual ~Animal() { }               |<----->| ~Dog()           |
|   virtual void makeSound() const = 0; |       +------------------+
| }                                     |       | Dog::makeSound() |
+---------------------------------------+       +------------------+

+---------------------------------------+       +------------------+
| class Dog : public Animal {           |       | Cat Vtable       |
|   _vptr;                              |       +------------------+
|   void makeSound() const override { } |       | ~Cat()           |
| }                                     |<----->| Cat::makeSound() |
+---------------------------------------+       +------------------+
```

### Interface
interfaces are implemented using abstract classes. An abstract class is a class that contains at least one pure virtual function. A pure virtual function is a function declared by placing = 0 at the end of its declaration. Abstract classes cannot be instantiated directly and are meant to be derived from by concrete classes that implement the pure virtual functions. An interface in C++ is typically defined as a class with all pure virtual functions and usually a virtual destructor to allow proper cleanup of derived class objects through base class pointers.

```cpp
#include <iostream>

// Define an interface
class IShape {
public:
    virtual ~IShape() {} // A virtual destructor
    virtual void draw() const = 0; // Pure virtual function
    virtual double area() const = 0; // Pure virtual function
};

class Circle : public IShape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Override the pure virtual functions
    void draw() const override {
        std::cout << "Drawing Circle\n";
    }

    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public IShape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Override the pure virtual functions
    void draw() const override {
        std::cout << "Drawing Rectangle\n";
    }

    double area() const override {
        return width * height;
    }
};

int main() {
    IShape* shapes[2];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);

    for (int i = 0; i < 2; ++i) {
        shapes[i]->draw();
        std::cout << "Area: " << shapes[i]->area() << std::endl;
        delete shapes[i];
    }

    return 0;
}
```
