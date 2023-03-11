#include <iostream>
#include "Base.h"
#include "Derived.h"

int main()
{
	const Base* object = Base::GetInstance(ClassType::DERIVED); //No object slicing

	const Base& temp = Base::GetInstance2A(ClassType::DERIVED); //object slicing

	const Base& tempB = Base::GetInstance2B(ClassType::DERIVED); //No object slicing

	const Base& tempC = Base::GetInstance2B(ClassType::DERIVED); //No object slicing

	const Base object2 = Base::GetInstance2A(ClassType::DERIVED); //This causes object slicing

	const Base& object3 = Base::GetInstance3(ClassType::DERIVED); //This causes object slicing

	const Base& object4 = Base::GetInstance4(ClassType::DERIVED); //This causes object slicing


	const std::unique_ptr<Base>& object5 = Base::GetInstance5(ClassType::DERIVED);//No object slicing
	//const std::unique_ptr<Base> object5 = Base::GetInstance5(ClassType::DERIVED);//this line causes error
	//because std::unique_ptr can't be copied

	//auto t = temp.instance;

	//Test
	Derived d;
	const Base& b = d; //No object slicing

	object->Print();
	temp.Print();
	tempB.Print();
	tempC.Print();
	object2.Print();
	object3.Print();
	object4.Print();
	object5.get()->Print();
	object5->Print();
	b.Print();

	delete object;
	const Base* deleteMe = (&tempB);
	delete deleteMe;
	delete (&tempC);
	/*
	When you slice a derived class object and assign it to a base class object, 
	the derived class information is lost, and you are left with a base class object. 
	When you try to delete the sliced base class object, the type of the object being deleted does not match 
	the type of the object that was originally allocated (which was a derived class object), and this results 
	in a runtime error.

     In conclusion, to avoid this issue, it's always recommended to use references or pointers 
	 to prevent slicing and ensure that the object being deleted is of the same type as the object that
	 was originally allocated.

	
	*/

	//The following causes object slicing and by invoking delete actually we're deleting Base part not Derived part
	// which cause run-time error 
	//auto deleteMe2 = (&temp); 
	//delete deleteMe2;




	/*
	Since tempB is a reference, we can't pass it directly to the delete operator.
	However, we can get the address of the object that tempB refers to by using the & operator,
	which returns a pointer to the object. So, &tempB returns a pointer to the object that tempB refers to,
	which is of type Base. This pointer can then be passed to the delete operator to free the dynamically allocated memory.

	*/

	//delete (&object2);
	//The line above causes object slicing and by invoking delete actually we're deleting Base part not Derived part
	// which cause run-time error 




}