### RPN
Reverse Polish Notation (RPN) was developed primarily to solve several practical and theoretical problems in mathematics and computer science.

RPN provides a way to represent mathematical expressions that is simultaneously human-readable (with practice) and directly executable by a computer using minimal resources, which made it invaluable in the early days of computing when resources were severely constrained.

### Where is a std::vector stored: stack or heap?
When you write something like this:
``` class A {
private:
    std::vector<int> vec;
};
```
Here’s what happens:

📦 vec (the std::vector object itself):
- The vec object (which includes things like the pointer to the data, the size, and the capacity) is stored directly in the object of class A.

- If an instance of A is allocated on the stack, then vec is on the stack as part of A.

- If A is allocated on the heap (e.g., via new), then vec is also on the heap as part of A.

📂 vec's internal data array:
- The actual elements of the vector (e.g., the ints in std::vector<int>) are allocated on the heap.

- This internal memory is managed by the vector.

- When the vector grows or shrinks, it automatically allocates and deallocates heap memory as needed.

### C++ Standard Template Library (STL)
The C++ Standard Template Library (STL) is a set of template classes and functions that provides the implementation of common data structures and algorithms such as lists, stacks, arrays, sorting, searching, etc. It also provides the iterators and functors which makes it easier to work with algorithms and containers.

### Why Vector and Deque? (ex02)

1. Complementary Performance Characteristics:

- std::vector provides excellent memory locality (contiguous memory) with O(1) random access, making it efficient for many operations in the algorithm.
- std::deque (double-ended queue) offers efficient insertion and deletion at both ends with O(1) complexity, which is crucial for certain operations in the merge-insertion sort algorithm.


2. Implementation Requirements:
The PmergeMe algorithm involves operations that benefit from these specific containers:

- Fast random access for comparisons and binary search
- Efficient insertions in the middle (which is more costly with vector but manageable for the algorithm's pattern)
- The Ford-Johnson algorithm (which PmergeMe is based on) works well with these data structures
stl, why vec and deq, destuctor clear, 