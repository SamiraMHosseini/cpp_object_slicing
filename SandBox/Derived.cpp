#include "Base.h"
#include "Derived.h"

void Derived::Print()  const
{
    std::cout << "This is Derived\n";
}