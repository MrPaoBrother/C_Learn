#include "string.h"

#include<cstring>

int String::num_objects = 0;

String::String(){
    len = 0;
    str = new char[1];
    str[0] = '\0';
    num_objects ++;
}

String::String(const char *s){
    len = std::strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_objects ++;
}

String::String(const String &s){
    len = s.length();
    str = new char[len + 1];
    strcpy(str, s.str);
    num_objects ++;
}

String::~String(){
    delete [] str;
    num_objects --;
}

String & String::operator=(const String &s){
    if(this == &s){
        return *this;
    }
    delete [] str;
    str = new char[s.len + 1];
    strcpy(str, s.str);
    return *this;
}

String & String::operator=(const char *s){
    delete [] str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}

char & String::operator[](int i){
    return str[i];
}

const char & String::operator[](int i) const{
    return str[i];
}

bool operator==(const String &s1, const String &s2){
    return (std::strcmp(s1.str, s2.str) == 0);
}

bool operator<(const String &s1, const String &s2){
    return (std::strcmp(s1.str, s2.str) < 0);
}

bool operator>(const String &s1, const String &s2){
    return (std::strcmp(s1.str, s2.str) > 0);
}

std::ostream & operator << (std::ostream &os, const String &s){
    os << s.str << std::endl;
    return os;
}

std::istream & operator >> (std::istream &is, String &s){
    char temp[String::INPUT_LIMIT_NUM];
    is.get(temp, String::INPUT_LIMIT_NUM);
    if(is){
        s.str = temp;
    }

    while (is && is.get() != '\n')
    {
        /* code */
        continue;
    }

    return is;
}

int String::HowMany(){
    return num_objects;
}