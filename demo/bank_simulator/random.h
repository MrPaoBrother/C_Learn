#ifndef BANK_RANDOM_H
#define BANK_RANDOM_H

// 一个客人办理的业务的时间范围 [1,60]
#define RANDOM_DURATION 60

// 每分钟进来的客人数量范围
#define RANDOM_PER_MINUTE 10

#include<random>

class Random{
public:
    static int uniform(int max){
        if(max < 0) return 0;

        return 1 + static_cast<int>(static_cast<double>(std::rand()) / RAND_MAX * max);
    }
};

#endif