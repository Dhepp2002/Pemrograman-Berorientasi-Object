class mahasiswa{
    private:
        string npm, nama;
    public:
        mahasiswa(string npm_, string nama_){
            npm = npm_;
            nama = nama_;
        }
        string getNPM(){
            return this->npm;
        }
        string getNama(){
            return this->nama;
        }
        void Display(){
            cout<<npm<<" - "<<nama<<endl;
        }
};