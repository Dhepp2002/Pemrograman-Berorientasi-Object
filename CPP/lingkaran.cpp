#include <iostream>
using namespace std;

class lingkaran{
    public:
    float r;
   
    float hitungLuas (int r) {
        return 3.14*this->r*this->r;
    }
};

int main(int argc, char const *argv[]) {
	
    lingkaran s1, s2;

    s1.r = 30;
    s2.r = 10;

    cout<<"Luas Lingkaran 1 adalah " <<s1.hitungLuas(100)<<endl; 
    cout<<"Luas Lingkaran 2 adalah " <<s2.hitungLuas(100)<<endl;
    return 0;
}
