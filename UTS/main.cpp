#include <iostream>
#include <conio.h>
using namespace std;

#include "menu.cpp"
#include "listmenu.cpp"

void addmenu(listmenu **head_){
    listmenu *newHead;
    menu *newmenu;
    string nama, deskripsi;
    double harga;

    newHead = new listmenu();

    cout<<"Nama Menu : ";
    getline(cin,nama);
    cout<<"Deskripsi : ";
    getline(cin,deskripsi);
    cout<<"Harga : ";
    cin>>harga;
    
    newmenu = new menu(nama, deskripsi, harga);

    if (*head_ == NULL)
    {
        newHead->data(newmenu);
        *head_ = newHead;
    }else
    {
        newHead->data(newmenu);
        newHead->next = *head_;
        *head_ = newHead;
    }

    cout<<"Menu Berhasil Ditambahkan"<<endl;
    cout<<"(klik enter)"<<endl;
};

void displaymenu(listmenu *head_){
    cout<<"Daftar Menu : "<<endl;

    int i = 1;
    while (head_ != NULL)
    {
        cout<<i++<<". ";
        head_->data()->Display();
        head_ = head_->next;
    }

    cout<<"---------------------------------------"<<endl;
    cout<<"Berhasil Menampilkan Daftar Menu!"<<endl;
    cout<<"(klik enter)"<<endl;
}

void updatemenu(listmenu *head_){
    menu *newmenu;
    listmenu *cursor;
    string nama, deskripsi;
    double harga;
    int status = 0;

    cout<<"Masukkan menu yang ingin diubah: ";
    cin>>nama;

    cursor = head_;

    while (cursor != NULL){
        if (cursor->data()->getNama() == nama){
            cout<<"\nMenu Berhasil Ditemukan = ";
            cursor->data()->Display();
            cout<<"---------------------------------------"<<endl;

            cout<<"Nama Menu Baru : ";
            cin>>nama;

            cout<<"Deskripsi Baru : ";
            cin>>deskripsi;
            
            cout<<"Harga Baru : ";
            cin>>harga;
            

            newmenu = new menu(nama, deskripsi, harga);
            cursor->data(newmenu);
            status = 1;

            cout<<"\nMenu Berhasil Dirubah"<<endl;
            cout<<"(klik enter)"<<endl;

            break;
        }
        cursor = cursor->next;
    }

    if (status == 0){
        cout<<"\nMenu Tidak Ditemukan"<<endl;
        cout<<"(klik enter)"<<endl;    
    }
}

int main(){
    listmenu *daftarMenu = NULL, *cursor;
    menu *newMenu = NULL;
    int pilih = 1;

    while (pilih != 0){
        system("cls");

        cout<<"   Restaurant Ciayo Surabaya	"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"Menu Pilihan : \n"<<endl;
        cout<<"1. Tampilkan Menu \n";
        cout<<"2. Tambah Data Menu \n";
        cout<<"3. Ubah Data Menu \n";
        cout<<"4. Hapus Data Menu Teratas \n";
        cout<<"5. Exit \n";
        cout<<"----------------------------"<<endl;
        cout<<"Pilih nomor : ";
        cin>>pilih;

        system("cls");

        if (daftarMenu == NULL && pilih != 2 && pilih != 0){
            cout<<"\nData Menu Masih Kosong"<<endl;
            cout<<"(klik enter)"<<endl;

            getche();
            continue;
        }

        switch (pilih){
        case 1: 
			displaymenu(daftarMenu);
			break;
        case 2: 
			addmenu(&daftarMenu);
            break;
        case 3: 
			updatemenu(daftarMenu);
            break;
        case 4:
            daftarMenu = daftarMenu->next;
            cout<<"\nData Menu Teratas Berhasil Dihapus"<<endl;
            cout<<"(klik enter)"<<endl;
            break;
        case 5:
            cout<<"\nProgram Berhenti"<<endl;
            cout<<"(klik enter)"<<endl;
            break;
        default:
            cout<<"\nInputan anda salah"<<endl;
            cout<<"(klik enter)"<<endl;
            break;
        }
        getche();
    }
    return 0;
}