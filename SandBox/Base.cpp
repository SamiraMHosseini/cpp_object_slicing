#include "Base.h"
#include "Derived.h"
#include <iostream>

Base Base::instance;
Base* Base::pInstance;
std::unique_ptr<Base> Base::puInstance;
Base* Base::GetInstance(const ClassType& type)
{
	if (type == ClassType::DERIVED)
		pInstance = new Derived();
	else
		pInstance = new Base();
	return pInstance;
}

Base& Base::GetInstance2A(const ClassType& type)
{
	if (type == ClassType::DERIVED)
		instance = *(new Derived()); //this line can cause object slicing because 
									//it assigns a derived class object to a base class object not reference or pointer Base
	else
		instance = *(new Base());
	return instance;
}

Base& Base::GetInstance2B(const ClassType& type)
{
	if (type == ClassType::DERIVED)
		return *(new Derived());
	else
		return *(new Base());

}

Base& Base::GetInstance2C(const ClassType& type)
{
	if (type == ClassType::DERIVED)
		pInstance= (new Derived());
	else
		pInstance= (new Base());
	return *(pInstance);
}

Base& Base::GetInstance3(const ClassType& type) //This causes object slicing
{
	if (type == ClassType::DERIVED)
		instance = Derived();
	else
		instance = Base();
	return instance;
}

Base Base::GetInstance4(const ClassType& type) //This causes object slicing
{
	if (type == ClassType::DERIVED)
		instance = Derived();
	else
		instance = Base();
	return instance;
}

std::unique_ptr<Base>& Base::GetInstance5(const ClassType& type)
{
	if (type == ClassType::BASE)
	{
		puInstance = std::make_unique<Base>();
	}
	else
	{
		puInstance = std::make_unique<Derived>();
	}
	return puInstance;
}
void Base::Print() const
{
	std::cout << "This is Base\n";
}


