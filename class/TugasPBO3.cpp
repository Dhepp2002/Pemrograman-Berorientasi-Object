#include<iostream>
#include<math.h>
using namespace std;

class segitiga{
	private:
		int a,t;
	
	public:
		void alas (int a_){
			this->a= a_;
		}
		int alas(){
			return this->a;
		}
		void tinggi (int t){
			this->t = t;
		}
		
		int tinggi(){
			return this->t;
		}
		float luas(){
			return 0.5*this->a*this->t;
		}
};

class persegi{
	private:
		float s;
	public:
		void set_sisi(int s_){
			this->s = s_;
		}
		float get_sisi(){
			return this->s;
		}
		
		float luas (){
			return (this->s*this->s);
		}
};

class persegi_panjang{
	private:
		float p, l;
	public:
		void set_panjang (int p_){
			this->p = p_;
		}
		float get_panjang(){
			return this->p;
		}
		void set_lebar (int l_){
			this->l = l_;
		}
		float get_lebar(){
			return this->l;
		}
		float luas (){
			return (this->p*this->l);
		}
};

class lingkaran{
	private:
		float phi = 3.14;
		float r;
	public:
		void set_jarijari (float r_){
			this->r = r_;
		}
		float get_r (){
			return this->r;
		}
		float get_phi(){
			return phi;
		}
		float luas (){
			return (phi*pow(this->r,2));
		}
};

class kubus{
	private:
		persegi p;
	public:		
		void set_persegi(persegi p){
			this->p=p;
		}
		float get_sisi(){
			p.get_sisi();
		}
		float volume(){
			return (pow(p.get_sisi(),3));
	}
};

class balok{
	private:
		persegi_panjang pp;
		float t;	
	public:
		void set_persegi_panjang (persegi_panjang pp){
			this->pp=pp;
		}
	    void set_tinggi(float t){
	        this->t=t;
	    }
	    float get_tinggi (){
	    	return this->t;
		}
		int get_panjang (){
			return pp.get_panjang();
		}
		int get_lebar (){
			return pp.get_lebar();
		}
	    float volume(){
	        return pp.luas() * t;
	    }
};

class tabung{
	private:
		lingkaran l;
		float t;
	public:
		void set_lingkaran(lingkaran l){
			this->l = l;
		}
		void set_tinggi(float t){
			this->t = t;
		}
		float get_tinggi (){
			return this->t;
		}
		float get_r (){
			return l.get_r();
		}
		float volume(){
			return (l.luas()*this->t);
		}
};

class limas_segitiga{
	private:
		segitiga s;
		float t;
	public:
		void set_segitiga(segitiga s){
			this->s=s;
		}
		void set_tinggi(float t){
			this->t = t;
		}
		float get_tinggi(){
			return this->t;
		}
		float alas(){
			return s.alas();
		}
		float get_tinggisegitiga(){
			return s.tinggi();
		}
		float volume(){
			return (s.luas()*this->t)/3;
		}
};

int main(){
	
	segitiga s;
	s.alas(5); s.tinggi(10);
	
	persegi p;
	p.set_sisi (10);
	
	persegi_panjang pp;
	pp.set_panjang(10); pp.set_lebar(15);
	
	lingkaran l;
	l.set_jarijari(30);
	
	kubus a;
	a.set_persegi(p);
	
	balok b;
	b.set_tinggi(10); b.set_persegi_panjang(pp);
	
	tabung c;
	c.set_tinggi(30); c.set_lingkaran(l);
	
	limas_segitiga d;
	d.set_segitiga(s);	d.set_tinggi(10);
	

	cout<<"Dhevi Puspitasari\n";
	cout<<"21081010165\n";
	cout<<"--------------------------\n\n\n";
	
	cout<<"SEGITIGA "<<endl;
	cout<<"Alas = "<<s.alas()<<" dan tinggi = "<<s.tinggi()<<endl;
	cout<<"Luas segitiga = "<<s.luas()<<endl<<endl;
	
	cout<<"PERSEGI "<<endl;
	cout<<"Panjang sisi = "<<p.get_sisi()<<endl;
	cout<<"Luas persegi = "<<p.luas()<<endl<<endl;

	cout<<"PERSEGI PANJANG "<<endl;
	cout<<"Panjang = "<<pp.get_panjang()<<" dan Lebar ="<<pp.get_lebar()<<endl;
	cout<<"Luas Persegi Panjang = "<<pp.luas()<<endl<<endl;

	cout<<"LINGKARAN "<<endl;
	cout<<"Jari-Jari = "<<l.get_r()<<endl;
	cout<<"Luas Lingkaran = "<<l.luas()<<endl<<endl;
	
	cout<<"KUBUS "<<endl;
	cout<<"Panjang sisi "<<a.get_sisi()<<endl;
	cout<<"Volume Kubus = "<<a.volume()<<endl<<endl;
	
	cout<<"BALOK "<<endl;
	cout<<"Panjang = "<<b.get_panjang()<<", lebar = "<<b.get_lebar()<<" dan tinggi = "<<b.get_tinggi()<<endl;
	cout<<"Volume Balok = "<<b.volume()<<endl<<endl;
	
	cout<<"TABUNG "<<endl;
	cout<<"Jari-jari alas = "<<c.get_r()<<" dan tinggi = "<<c.get_tinggi()<<endl;
	cout<<"Volume tabung = "<<c.volume()<<endl<<endl;
	
	cout<<"LIMAS SEGITIGA "<<endl;
	cout<<"Alas = "<<d.alas()<<", Tinggi = "<<d.get_tinggi()<<", dan Tinggi Limas = "<<d.get_tinggi()<<endl;
	cout<<"Volume Limas Segitiga = "<<d.volume()<<endl;
	
}