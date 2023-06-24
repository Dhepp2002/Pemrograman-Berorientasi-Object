#include <iostream>
#include <conio.h>
using namespace std;

#include "mahasiswa.cpp"
#include "listMHS.cpp"

void addMhs(listMHS **head_){
    listMHS *newHead;
    mahasiswa *newMhs;
    string npm, nama;

    newHead = new listMHS();

    cout<<"Masukkan NPM: ";
    cin>>npm;
    cout<<"Masukkan Nama: ";
    cin>>nama;

    newMhs = new mahasiswa(npm, nama);

    if (*head_ == NULL)
    {
        newHead->data(newMhs);
        *head_ = newHead;
    }else
    {
        newHead->data(newMhs);
        newHead->next = *head_;
        *head_ = newHead;
    }

    cout<<"Mahasiswa Berhasil Ditambahkan"<<endl;
    cout<<"(klik enter)"<<endl;
};

void displayMhs(listMHS *head_){
    cout<<"Daftar Mahasiswa: "<<endl;

    int i = 1;
    while (head_ != NULL)
    {
        cout<<i++<<". ";
        head_->data()->Display();
        head_ = head_->next;
    }

    cout<<"---------------------------------------"<<endl;
    cout<<"Berhasil Menampilkan Daftar Mahasiswa!"<<endl;
    cout<<"(klik enter)"<<endl;
}

void updateMhs(listMHS *head_){
    mahasiswa *newMhs;
    listMHS *cursor;
    string npm, nama;
    int status = 0;

    cout<<"Masukkan NPM Mahasiswa yang ingin diubah: ";
    cin>>npm;

    cursor = head_;

    while (cursor != NULL){
        if (cursor->data()->getNPM() == npm){
            cout<<"\nMahasiswa Berhasil Ditemukan = ";
            cursor->data()->Display();
            cout<<"---------------------------------------"<<endl;

            cout<<"Masukkan NPM Baru: ";
            cin>>npm;

            cout<<"Masukkan Nama Baru: ";
            cin>>nama;

            newMhs = new mahasiswa(npm, nama);
            cursor->data(newMhs);
            status = 1;

            cout<<"\nData Mahasiswa Berhasil Dirubah"<<endl;
            cout<<"(klik enter)"<<endl;

            break;
        }
        cursor = cursor->next;
    }

    if (status == 0){
        cout<<"\nData Mahasiswa Tidak Ditemukan"<<endl;
        cout<<"(klik enter)"<<endl;    
    }
}

int main(){
    listMHS *daftarMahasiswa = NULL, *cursor;
    mahasiswa *newMahasiswa = NULL;
    int pilih = 1;

    while (pilih != 0){
        system("cls");

        cout<<"   Siakad (Sistem Informasi Mahasiswa)	"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"Menu Pilihan : \n"<<endl;
        cout<<"1. Tampilkan Mahasiswa \n"<<endl;
        cout<<"2. Tambah Data Mahasiswa \n"<<endl;
        cout<<"3. Ubah Data Mahasiswa \n"<<endl;
        cout<<"4. Hapus Data Mahasiswa Teratas \n"<<endl;
        cout<<"5. Exit \n"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"Pilih nomor : ";
        cin>>pilih;

        system("cls");

        if (daftarMahasiswa == NULL && pilih != 2 && pilih != 0){
            cout<<"\nData Mahasiswa Masih Kosong"<<endl;
            cout<<"(klik enter)"<<endl;

            getche();
            continue;
        }

        switch (pilih){
        case 1: 
			displayMhs(daftarMahasiswa);
			break;
        case 2: 
			addMhs(&daftarMahasiswa);
            break;
        case 3: 
			updateMhs(daftarMahasiswa);
            break;
        case 4:
            daftarMahasiswa = daftarMahasiswa->next;
            cout<<"\nData Mahasiswa Teratas Berhasil Dihapus"<<endl;
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