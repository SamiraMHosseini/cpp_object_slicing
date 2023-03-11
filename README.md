# object slicing in C++
Object slicing in C++ occurs when a derived class object is assigned to a base class object, but the data members and member functions that are specific to the derived class are lost because the assignment only takes into account the base class portion of the derived class object. This can happen when the base class is passed by value as a parameter, or when a derived class object is assigned to a base class object.

# How to prevent object slicing?
To prevent object slicing in C++, we can use a pointer or a reference to the base class instead of passing the object by value.
