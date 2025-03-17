
### How C++ compiles and links normal vs template functions
1. Normal (Non-Template) Functions:
- When you declare a function in a class but implement it in a .cpp file, the compiler compiles it once and generates a definition in the object file.
- The linker then resolves the function call, ensuring there's a single definition (following the One Definition Rule (ODR)).

2. Template Functions:
- Template functions are not compiled into a single definition in the .cpp file because templates depend on the type parameter(s).
- The compiler needs to see the full definition of the template function when it's used so it can generate code for specific types (instantiation). (that's mean the object file doesn't know anything about our function)
- When we compile we have the main.cpp and for the linking we have the object files and the header file (so we need to implement our template function in the header file cuz the object files won't contain its implementation).


### Standard Template Library (STL) in C++
Standard Template Library is a set of template classes and functions that provides the implementation of common data structures and algorithms such as lists, stacks, arrays, sorting, searching, etc.

Standard Template Library (STL) in C++ that can be classified into 4 types:
- Containers
- Algorithms
- Iterators
- Functors