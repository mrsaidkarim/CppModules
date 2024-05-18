the difference between using initialization lists and assignments inside constructor bodies:
Using Initialization List:

- Directly initializes class members with values provided by constructor parameters.
Ensures that class members are initialized only once, directly from the constructor's parameter list.
- Often preferred for efficiency, especially for non-default-constructible members and reference members.
- Can improve code readability and maintainability by clearly indicating member initialization.
Using Assignments Inside Constructor Body:

- Involves default initialization of class members followed by assignment inside the constructor body.
- May result in additional overhead due to default construction followed by assignment.
Can lead to potential inefficiencies and duplicated work, especially for complex or non-trivial members.
- Generally less preferred compared to initialization lists, but may be necessary in certain cases, such as dynamic initialization or complex initialization logic.

###### Pointers to members 
Pointers to members allow you to refer to nonstatic members of class objects. You cannot use a pointer to member to point to a static class member because the address of a static member is not associated with any particular object. To point to a static class member, you must use a normal pointer.
You can use pointers to member functions in the same manner as pointers to functions. You can compare pointers to member functions, assign values to them, and use them to call member functions. Note that a member function does not have the same type as a nonmember function that has the same number and type of arguments and the same return type.

ex04