### Exceptions
In C++, exceptions provide a way to handle errors or unexpected situations during runtime. When an error occurs, instead of the program crashing, an exception can be thrown and caught, allowing the program to handle the error gracefully.

#### Key Concepts in C++ Exceptions
- Throwing an Exception: When an error occurs, you can use the throw keyword to throw an exception. The object passed to throw can be of any type, though typically, exceptions are derived from std::exception.
- Catching an Exception: You catch exceptions using try-catch blocks. The code that might throw an exception is placed inside the try block, and the corresponding catch block handles the exception.
- The std::exception Class: The C++ Standard Library provides a base class for exceptions called std::exception. You can derive your own exception classes from this base class.


#### Basic Example of Throwing and Catching Exceptions
```#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero error!");
    }
    return a / b;
}

int main() {
    try {
        int result = divide(10, 0);  // This will throw an exception
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
```