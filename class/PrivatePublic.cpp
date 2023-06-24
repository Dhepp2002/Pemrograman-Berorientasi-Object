#include <iostream>
#include <math.h>

using namespace std;

class Segitiga{
    private:
        int a, t; //data member
        
    protected: // dibahas lain waktu (ketika inheritance)
        float hitungLuas(){
            return 0.5 * this->a * this->t;
        }
    public:
        void alas(int a){
            this->a = a;
        }
        int alas(){
            return this->a;
        }
        void tinggi(int t){
            this->t = t;
        }
        int tinggi(){
            return this->t;
        }
        
        float luas(){ //member function
            return hitungLuas();
        }
};

class limasSegitiga{
    private:
        Segitiga s[4];
        int t;
        
    public:
        void setSisi(int index, int a, int t){
            s[index].alas(a);
            s[index].tinggi(t);
        }
        
        void tinggi(int t){
            this->t = t;
        }
        int tinggi(){
            return this->t;
        }
};

int main()
{
    Segitiga s;
    
    s.alas(10); s.tinggi(20);
    cout<<"luas segitga dengan alas : "<<s.alas()<<",  tinggi :"<<s.tinggi()<<", adalah "<<s.luas()<<endl;

    float a=7, t=24;
    float x = pow(a,2) + pow(t,2);
    
    cout<<sqrt(x)<<endl;
    cout<<sqrt(pow(a,2) + pow(t,2))<<endl;
    
    
    return 0;
}