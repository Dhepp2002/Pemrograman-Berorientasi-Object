class menu{
    private:
        string nama, deskripsi;
		double harga;
    public:
        menu(string nama_, string deskripsi_, double harga_){
            nama = nama_;
            deskripsi = deskripsi_;
            harga = harga_;
        }
        string getNama(){
            return this->nama;
        }
        string getDeskripsi(){
            return this->deskripsi;
        }
        double getHarga(){
        	return this->harga;
		}
        void Display(){
            cout<<nama<<" - "<<deskripsi<<" - "<<harga<<endl;
        }
};