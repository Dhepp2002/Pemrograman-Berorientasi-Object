class listMHS{
    private:
        mahasiswa *m;
    public:
        listMHS *next;
        mahasiswa *data(){
            return this->m;
        }
        void data(mahasiswa *m_){
            this->m = m_;
        }
};