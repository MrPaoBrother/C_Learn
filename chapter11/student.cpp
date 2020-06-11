#include "student.h"

Student::Student(){
    name = "none";
    score = 0;
}

Student::Student(std::string name, int score):name(name),score(score){

}

std::ostream & operator<<(std::ostream & os, const Student &s){
    os << "name: " << s.name << " score: " << s.score << endl;
    return os;
}