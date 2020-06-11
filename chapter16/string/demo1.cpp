#include<iostream>
#include<string>
using namespace std;

int main(){
    string one("powerer");
    cout << one << endl;

    string two(20, 'p');
    cout << two << endl;

    string three(one);
    cout << three << endl;

    string four(three, 4);
    cout << four << endl;

    string five(three, 2, 3);
    cout << five << endl;

    int index = one.find("er", 0, 2);

    cout << index << endl;
    return 0;
}