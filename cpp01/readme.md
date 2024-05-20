
## Introduction

This README provides an overview of key concepts related to object-oriented programming (OOP) in C++.

## Using Initialization Lists vs Assignments Inside Constructor Bodies

When defining constructors in C++, you can initialize class members using either initialization lists or assignments inside the constructor body. Both approaches have their use cases, but there are important differences between them.

#### Using Initialization Lists

- **Direct Initialization**: Class members are directly initialized with values provided by constructor parameters.
- **Single Initialization**: Ensures that class members are initialized only once, directly from the constructor's parameter list.
- **Efficiency**: Often preferred for efficiency, especially for non-default-constructible members and reference members.
- **Readability**: Can improve code readability and maintainability by clearly indicating member initialization.

Example:
```cpp
class Example {
private:
    int value;
public:
    Example(int val) : value(val) {}  // Initialization list
};
```

#### Using Assignments Inside Constructor Body
Default Initialization Followed by Assignment: Class members undergo default initialization followed by assignment inside the constructor body.
- **Overhead**: May result in additional overhead due to default construction followed by assignment.
- **Inefficiencies**: Can lead to potential inefficiencies and duplicated work, especially for complex or non-trivial members.
- **Necessity in Some Cases**: Generally less preferred compared to initialization lists, but may be necessary in certain cases, such as dynamic initialization or complex initialization logic.
Example:
```cpp
class Example {
private:
    int value;
public:
    Example(int val) {
        value = val;  // Assignment inside constructor body
    }
};
```

## Pointers to Members in C++
Pointers to members in C++ allow you to refer to non-static members of class objects. Here are the key points regarding their usage:

- **Non-Static Members**: You cannot use a pointer to member to point to a static class member because the address of a static member is not associated with any particular object. To point to a static class member, you must use a normal pointer.
- **Member Functions**: You can use pointers to member functions in the same manner as pointers to functions. You can compare pointers to member functions, assign values to them, and use them to call member functions.
- **Type Difference**: Note that a member function does not have the same type as a non-member function that has the same number and type of arguments and the same return type.
Example of Pointer to Data Member:
```cpp
class MyClass {
public:
    int data;
};

int main() {
    int MyClass::*ptr = &MyClass::data; // Pointer to data member
    MyClass obj;
    obj.*ptr = 5; // Using pointer to data member
    return 0;
}
```
Example of Pointer to Member Function:
```cpp
class MyClass {
public:
    void display() {
        std::cout << "Hello, World!" << std::endl;
    }
};

int main() {
    void (MyClass::*ptr)() = &MyClass::display; // Pointer to member function
    MyClass obj;
    (obj.*ptr)(); // Using pointer to member function
    return 0;
}
```
