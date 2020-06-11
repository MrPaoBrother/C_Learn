#ifndef BANK_CUSTOMER_H
#define BANK_CUSTOMER_H

#include "random.h"

class Customer
{
public:
    Customer() : arriveTime(0), duration(Random::uniform(RANDOM_DURATION)), next(nullptr) {}
    Customer(int arriveTime) : arriveTime(arriveTime), duration(Random::uniform(RANDOM_DURATION)), next(nullptr) {}

public:
    // 到达时间
    int arriveTime;
    // 办理业务花费的时间
    int duration;
    Customer *next;
};

#endif