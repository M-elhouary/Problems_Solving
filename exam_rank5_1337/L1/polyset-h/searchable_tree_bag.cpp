#include "searchable_tree_bag.hpp"
#include "cstddef"

searchable_tree_bag::searchable_tree_bag() : tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other) : tree_bag(other) {}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other)
{
    if(this != &other)
    {
        tree_bag::operator=(other);
    }
    return *this;
}

searchable_tree_bag::~searchable_tree_bag() {}


bool searchable_tree_bag::search_tree(node *n, int value) const
{
    if(n == NULL)
        return false;
    if(n->value == value)
        return true;
    if(value < n->value)
        return search_tree(n->l, value);
    else
        return search_tree(n->r, value);
    
}

bool searchable_tree_bag::has(int value) const
{
    return search_tree(tree, value);
}