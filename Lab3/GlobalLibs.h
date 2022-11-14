#pragma once
#include <iostream>

struct Data
{
    int data;
};

inline bool operator==(Data const& lhs, Data const& rhs) {
    return (lhs.data == rhs.data);
}