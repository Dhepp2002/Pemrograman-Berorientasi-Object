#include <iostream>
using namespace std;

class bangun_ruang {
	public :
	class kubus{
	    public:
	    int s;
	
	    float hitungVolume (float s) {
	        return this->s*this->s*this->s;
	    }
	};
	
	class balok{
	    public:
	    int p,l,t;
	
	    float hitungVolume (float s) {
	        return p*l*t;
	    }
	};
	
	class tabung{
	    public:
	    float phi=3.14;
	    float r,t;
	
	    float hitungVolume (float s) {
	        return phi*r*r*t;
	    }
	};
	
	class kerucut{
	    public:
	    float phi=3.14;
	    float r,t;
	
	    float hitungVolume (float s) {
	        return phi*r*r*t/3;
	    }
	};
	
	class limas_segitiga{
	    public:
	    float La,t;
	
	    float hitungVolume (float s) {
	        return La*t/3;
	    }
	};
};

int main(int argc, char const *argv[]) {
	
    kubus a1, a2;
    balok b1, b2;
    tabung c1, c2;
    kerucut d1, d2;
    limas_segitiga e1, e2;

    a1.s = 30;
    a2.s = 10;
    
    b1.p = 30;
    b1.l = 20;
    b1.t = 10;
    
    b2.p = 15;
    b2.l = 10;
    b2.t = 5;
    
    c1.r = 30;
    c1.t = 5;
    
    c2.r = 10;
    c2.t = 5;
    
    d1.r = 30;
    d1.t = 5;
    
    d2.r = 10;
    d2.t = 5;
    
    e1.La = 30;
    e1.t = 5;
    
    e2.La = 40;
    e2.t = 5;

    cout<<"Volume Kubus adalah " <<a2.hitungVolume(100)<<endl; 
    cout<<"Volume Balok adalah " <<b2.hitungVolume(100)<<endl;
    cout<<"Volume Tabung adalah " <<c2.hitungVolume(100)<<endl;
    cout<<"Volume Kerucut adalah " <<d2.hitungVolume(100)<<endl;
    cout<<"Volume Limas Segitiga adalah " <<e2.hitungVolume(100)<<endl;
    
    return 0;
}
