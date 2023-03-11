#ifndef DERIVED_H
#define DERIVED_H
struct Base;

struct Derived : public Base
{
public:
    void Print() const override;
    int j = 2;

};

#endif