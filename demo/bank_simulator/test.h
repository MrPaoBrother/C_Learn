#ifndef BANK_TEST_H
#define BANK_TEST_H

// TODO STL模板库可以利用
#include<ctime>
#include<iostream>
#include "manager.h"

class Test
{
public:
    static void run(int serverTime, int serviceNum, int simulateNum);
    static void printTime();
};

void Test::printTime(){
    time_t t = time(0);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y%m%d %X", localtime(&t));
    std::cout << "Current time: " << tmp << std:: endl;
}

void Test::run(int serverTime, int serviceNum, int simulateNum){
    std::srand(static_cast<unsigned int>(time(0)));

    time_t start, end;

    time(&start);
    printTime();
    Manager tester(serverTime, serviceNum);
    tester.simulate(simulateNum);
    printTime();
    time(&end);

    std::cout << "Average customer stay time: " << tester._getAvgStayTime() << std::endl;

    std::cout << "Average deal customer num in bank per minute: " << tester._getAvgDealCustomerNumInMinute() << std::endl;

    std::cout << "run cost time in seconds: " << difftime(end, start) << std::endl;
}
#endif