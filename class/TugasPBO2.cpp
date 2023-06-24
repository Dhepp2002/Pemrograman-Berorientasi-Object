#include <iostream>
using namespace std;

class bangun_datar {
	public :
	class segitiga {
	    public:
	    int a,t;
	    
	    float hitungLuas (float s) {
	        return 0.5*a*t;
	    }
	};
	
	class persegi{
	    public:
	    int s;
	
	    float hitungLuas (float s) {
	        return this->s*this->s;
	    }
	};
	
	class persegi_panjang{
	    public:
	    int p,l;
	    
	    float hitungLuas (float s) {
	        return p*l;
	    }
	};
	
	class lingkaran{
	    public:
	    float phi=3.14;
	    float r;
	   
	    float hitungLuas (float s) {
	        return phi*r*r;
	    }
	};
};

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
	
    bangun_datar::segitiga s1, s2;
    bangun_datar::persegi p1, p2;
    bangun_datar::persegi_panjang pp1, pp2;
    bangun_datar::lingkaran l1, l2;
    
    bangun_ruang::kubus a1, a2;
    bangun_ruang::balok b1, b2;
    bangun_ruang::tabung c1, c2;
    bangun_ruang::kerucut d1, d2;
    bangun_ruang::limas_segitiga e1, e2;

    s1.a = 30;
    s1.t = 15;

    s2.a = 25;
    s2.t = 30;
    
    p1.s = 25;
    p2.s = 10;
    
    pp1.p = 30;
    pp1.l = 15;
    
    pp2.p = 25;
    pp2.l = 30;
    
    l1.r = 30;
    l2.r = 10;
    
    a1.s = 30;
    
    b1.p = 30;
    b1.l = 20;
    b1.t = 10;
    
    c1.r = 30;
    c1.t = 5;
    
    d1.r = 30;
    d1.t = 5;

    e1.La = 30;
    e1.t = 5;
 
	cout<<"LUAS BANGUN DATAR "<<endl;
	cout<<"------------------------------"<<endl;
    cout<<"Luas Segitiga adalah " <<s2.hitungLuas(100)<<endl; 
    cout<<"Luas Persegi adalah " <<p2.hitungLuas(100)<<endl;
    cout<<"Luas Persegi Panjang adalah " <<pp2.hitungLuas(100)<<endl;
    cout<<"Luas Lingkaran adalah " <<l2.hitungLuas(100)<<endl<<endl;
    
    cout<<"LUAS BANGUN RUANG "<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"Volume Kubus adalah " <<a1.hitungVolume(100)<<endl; 
    cout<<"Volume Balok adalah " <<b1.hitungVolume(100)<<endl;
    cout<<"Volume Tabung adalah " <<c1.hitungVolume(100)<<endl;
    cout<<"Volume Kerucut adalah " <<d1.hitungVolume(100)<<endl;
    cout<<"Volume Limas Segitiga adalah " <<e1.hitungVolume(100)<<endl;
    return 0;
}
