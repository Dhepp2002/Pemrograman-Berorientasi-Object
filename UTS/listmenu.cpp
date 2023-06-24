class listmenu{
    private:
        menu *m;
    public:
        listmenu *next;
        menu *data(){
            return this->m;
        }
        void data(menu *m_){
            this->m = m_;
        }
};