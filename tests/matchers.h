#ifndef MATCHERS_H
#define MATCHERS_H
#include "gmock/gmock.h"

MATCHER_P(IntValueVecMatcher, container, "")
{
    if (arg->size() != container.size())
    {
        return false;
    }
    for (int i = 0; i < arg->size(); i++)
    {
        if (*((int*)(arg)->at(i)->get_value()) != *((int*)container[i]->get_value()))
        {
            return false;
        }
    }
    return true;
};

MATCHER_P(DoubleValueVecMatcher, container, "")
{
    if (arg->size() != container.size())
    {
        return false;
    }
    for (int i = 0; i < arg->size(); i++)
    {
        if (*((double*)(arg)->at(i)->get_value()) != *((double*)container[i]->get_value()))
        {
            return false;
        }
    }
    return true;
};

MATCHER_P(StringValueVecMatcher, container, "")
{
    if (arg->size() != container.size())
    {
        return false;
    }
    for (int i = 0; i < arg->size(); i++)
    {
        if (*((std::string*)(arg)->at(i)->get_value()) != *((std::string*)container[i]->get_value()))
        {
            return false;
        }
    }
    return true;
};

#endif