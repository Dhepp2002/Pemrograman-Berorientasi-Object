#include <iostream>
using namespace std;

class segitiga{
    public:
    int a;
    int t;

    float hitungLuas (int a) {
        return 0.5*this->a*t;
    }
};

int main(int argc, char const *argv[]) {
	
    segitiga s, s2;

    s.a = 30;
    s.t = 15;

    s2.a = 25;
    s2.t = 30;

    cout<<"Luas Segitiga Struct adalah " <<s2.hitungLuas(100)<<endl; 
    return 0;
}
