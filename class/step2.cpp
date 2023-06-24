#include <iostream>
using namespace std;

struct segitiga{
    int a;
    int t;
};

float luasSegitiga (int a, int t) {
    return 0.5*a*t;
}

int main(int argc, char const *argv[]) {
    int a = 10;
    int t = 15;

    segitiga s;

    s.a = 15;
    s.t = 20;

    cout << "Luas Segitiga Struct adalah " << luasSegitiga(s.a, s.t) << endl; 

    float luas = luasSegitiga (a,t);
    cout << "Luas segitiga = " << luas << endl;
    return 0;
}
