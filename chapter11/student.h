#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include<iostream>
using namespace std;

class Student
{
private:
    string name;
    int score;

public:
    Student();
    Student(string name, int score);

    friend std::ostream & operator<<(std::ostream &os, const Student &s);
};

#endif