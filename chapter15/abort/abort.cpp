#include <iostream>
#include<exception>

using namespace std;

void except(int &);

int main()
{
    int a;
    cin >> a;
    try{
        except(a);
    }catch(const char *s){
        cout << s << endl;
    }
    
    return 0;
}

void except(int &a){
    if(a % 2 == 0) throw logic_error("123");

    cout << "odd number" << endl;
}