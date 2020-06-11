#ifndef CRAB_H_
#define CRAB_H_
#include "stack.h"
template<template<typename T>class Thing>
class Crab{
private:
    Thing<int> thing;
public:
    Crab(){};
    bool push(int t){return thing.push(t);}
    bool pop(int &t){return thing.pop(t);}
};
#endif