#include <iostream>
#include<math.h>
using namespace std;

class segitiga {
    private:
    	int a,t;
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
            return 0.5*a*t;
        }
};
	
class persegi {
    private:
    	int s;
	
	public:
		void sisi (int s){
			this->s=s;
		}
		int sisi (){
			return this->s;
		}
	    float luas(){
	        return this->s*this->s;
		}
};
	
class persegi_panjang {
    private:
    	int p,l;
    
	public:
		void panjang(int p){
            this->p = p;
        }
        int panjang(){
            return this->p;
        }
        void lebar(int l){
            this->l = l;
        }
        int lebar(){
            return this->l;
        }
	    float luas(){
		        return p*l;
	    }
};
	
class lingkaran {
    private:
	    float phi = 3.14;
		float jari_jari;
	
	public:
		void jari (float r){
			jari_jari=r;
		}
		float jari (){
			return jari_jari;
		}
		float phi_(){
			return phi;
		}
	    float luas () {
	        return phi*pow(jari_jari,2);
	    }
};

class kubus{
	private:
    	persegi p;
    	
	public:
		void sisi (float s){
			this->s=s;
		}
		float sisi (){
			return this->s;
		}
	    float volume (){
	        return pow(p.sisi(), 3);
	    }
};
	
class balok{
    private:
    	int tinggi;
    	persegi_panjang pp;
	
	public:
		//komposisi -> untuk pengambilan data member dari class lain
		void setSisi(int p, int l, int t){
	        pp.sisi(p, l);
	        tinggi = t;	
    	}
		int getTinggi(){
        	return tinggi;
    	}
		float volume(){
	        return pp.luas() * tinggi;
	    }
		}
};
	
class tabung{
	private:
		float t;
		
    public:
    	lingkaran l;
    	
    	float jari(){
    		return l.jari();
		}
		float phi(){
			return l.phi_();
		}
	    float volume () {
	        float volume = l.luas() * t;
	        return volume;
	    }
};
	
class kerucut{
    private:
		float t;
		
    public:
    	lingkaran l;

    	float jari(){
    		return l.jari();
		}
		float phi(){
			return l.phi_();
		}
	    float volume () {
	        float volume = l.luas() * t/3;
	        return volume;
	    }
};
	
class limas_segitiga{
    private:
    	segitiga s[1];
		float t;
	
	public:
	    void setSisi(int index, int a, int t){
            s[index].alas(a);
            s[index].tinggi(t);
        }
	    int alas (){
	    	return s.alas();
		}
		int tinggi (){
			return s.tinggi();
		}
		float volume(){
			float volume = s.luas() * t/3;
			return volume;
		}
};

int main() {
	
    segitiga s;
	s.alas(10); s.tinggi(20);

    persegi p;
    p.sisi(50);
    cout << "Luas Persegi: " << p.luas() << endl;
    
    persegi_panjang pp;
    pp.panjang(10); pp.lebar(20);
    cout << "Luas Persegi Panjang: " << pp.luas() << endl;

    lingkaran l;
    l.jari(30);
    cout << "Luas Lingkaran: " << l.luas()<<endl;
    
    kubus a;
    a.sisi(10);
    cout << "Luas Kubus : " << a.volume() << endl;

    balok b;
    cout << "Luas Balok: " << b.volume() << endl;
    
    tabung c;
    cout << "Luas Tabung: " << c.volume() << endl;

    kerucut d;
    cout << "Luas Kerucut: " << d.volume() <<endl;
    
    limas_segitiga e;
    cout << "Luas Limas Segitiga: " << e.volume() <<endl;
    return 0;
}
