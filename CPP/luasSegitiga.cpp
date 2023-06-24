#include <iostream>
using namespace std;

float luasSegitiga (int a, int t) {
    return 0.5*a*t;
}

int main(){
    int a = 10;
    int t = 15;

    float luas = luasSegitiga (a,t);
    cout<<"Luas segitiga = "<<luas<< endl;
    return 0;
}
