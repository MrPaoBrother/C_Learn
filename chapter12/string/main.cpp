#include "string.h"
using namespace std;

int main(){
    String power("power");
    String weny("weny");

    if(power < weny){
        cout << "power small" <<endl;
    }

    cout << "now objects is " << power.HowMany() << endl;

    power = weny;

    cout << power[0] << endl;

    String goodpower(power);

    cout << "now objects is " << power.HowMany() << endl;
    return 0;
}