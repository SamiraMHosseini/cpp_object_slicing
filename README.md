# object slicing in C++
Object slicing in C++ occurs when a derived class object is assigned to a base class object, but the data members and member functions that are specific to the derived class are lost because the assignment only takes into account the base class portion of the derived class object. This can happen when the base class is passed by value as a parameter, or when a derived class object is assigned to a base class object.

# How to prevent object slicing?
Object slicing is a phenomenon in C++ where the derived class object is treated as a base class object, resulting in the loss of data and behavior specific to the derived class. To prevent object slicing, you can use one of the following methods:

1) Use references or pointers instead of values: When you pass a derived class object by reference or pointer, it will not be sliced and the original object will be preserved.

2) Make the base class virtual: By declaring the base class as virtual, the derived class object will be sliced to the most derived class and the behavior of the most derived class will be preserved.

3) Make the base class's copy constructor and assignment operator private: By making the base class's copy constructor and assignment operator private, you can prevent slicing by preventing the copying of objects.
