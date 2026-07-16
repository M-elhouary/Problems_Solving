#include "set.hpp"

set::set(searchable_bag &bag_ref) : bag(&bag_ref) {}
set::set(const set &other) : bag(other.bag) {}
set& set::operator=(const set &other)
{
    if(this != &other)
    {
        this->bag = other.bag;
    }
    return *this;
}

set::~set() {};

void set::insert(int val)
{
    if (!bag->has(val))
        bag->insert(val);
}
void set::insert(int *array, int size)
{
    for(int i = 0; i < size; ++i)
    {
        insert(array[i]);
    }
}
void set::print() const
{
    bag->print();
}

void set::clear()
{
    bag->clear();
}

bool set::has(int val) const
{
    return bag->has(val);
}

searchable_bag& set::get_bag()
{
    return *bag;
}