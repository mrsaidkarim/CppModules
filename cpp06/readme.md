
## CASTS

A Cast operator is a unary operator which forces one data type to be converted into another data type.

## C++ supports 5 types of casting:
### 1. C Style Casting
It is the casting used in the C language, and it is also used in C++. But in C++, usage of this type is not encouraged.

### 2. Static Cast (compile time)
This is the simplest type of cast that can be used. It is a compile-time cast. It does things like implicit conversions between types (such as int to float, or pointer to void*), and it can also call explicit conversion functions.

### 3. Dynamic Cast (runtime)
It is specifically designed for the polymorphic class,which have at least one virtual function.Dynamic cast operator allows us to check whether a pointer or reference to base pointer or references of a derived class.

### 4. Const Cast
It is used to change the value of the variable that is referenced through a pointer.

### 5. Reinterpret Cast
A low-level cast used to convert any pointer type to any other pointer type, and also to convert between pointer and integer types. It’s the least safe cast and is usually avoided unless absolutely necessary (e.g., for interfacing with low-level system code).

## rand() and srand() in C++:
- rand() generates a sequence of pseudo-random numbers based on an initial "seed" value.
- srand(seed) initializes the random number generator with a seed. Without calling srand(), rand() will produce the same sequence of numbers every time the program runs, because it defaults to a seed value of 1.
