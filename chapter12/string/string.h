#ifndef STRING_H_
#define STRING_H_

#include<iostream>

class String{
private:
    char *str;
    int len;
    static int num_objects;
    static const int INPUT_LIMIT_NUM = 80;

public:
    String();
    String(const char *);
    String(const String &);

    ~String();

    int length() const {return len;}

    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;

    friend bool operator==(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend std::ostream & operator<<(std::ostream &, const String &);
    friend std::istream & operator>>(std::istream &, String &);

    static int HowMany();
};

#endif