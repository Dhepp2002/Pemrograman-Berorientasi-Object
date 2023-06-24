/*
Nama : Dhevi Puspitasari
NPM  : 21081010165
Kelas : C081
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits> 

using namespace std;

class Person {
protected:
    string nama;
    string kelamin;
    string agama;

public:
    Person() {}

    void inputPerson() {
        cout << "Masukkan Nama: ";
        cin.sync();
        getline(cin, nama);
        cout << "Masukkan Kelamin (L / P): ";
        getline(cin, kelamin);
        cout << "Masukkan Agama: ";
        getline(cin, agama);
    }

    void outputPerson() {
        cout << "Nama: " << nama << endl;
        cout << "Kelamin: " << kelamin << endl;
        cout << "Agama: " << agama << endl;
    }
};

class Mahasiswa : public Person {
private:
    string status;
    int semester;
    long long nim;

public:
    Mahasiswa() {}

    void input() {
        cout << "======================================================\n";
        cout << "Data Mahasiswa\n";
        inputPerson();
        cout << "Masukkan NIM Mahasiswa: ";
        cin >> nim;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukkan Semester Mahasiswa: ";
        cin >> semester;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukkan status Mahasiswa (Aktif, Non-Aktif, Lulus): ";
        getline(cin, status);
    }

    void output() {
        outputPerson();
        cout << "NIM Mahasiswa: " << nim << endl;
        cout << "Semester Mahasiswa: " << semester << endl;
        cout << "Status: " << status << endl;
    }

    const string& getNama() const {
        return nama;
    }
	//mengatur objek kelas Mahasiswa ditampilkan dan dibaca dalam stream.
    friend ostream& operator<<(ostream& os, const Mahasiswa& mhs);
    friend istream& operator>>(istream& is, Mahasiswa& mhs);
};

//Operator overload ini mempermudah proses serialisasi objek Mahasiswa ke dalam stream untuk tujuan tampilan atau penyimpanan.
ostream& operator<<(ostream& os, const Mahasiswa& mhs) {
    os << mhs.nama << "_" << mhs.nim << " " << mhs.semester << " " << mhs.kelamin << " " << mhs.agama << " " << mhs.status;
    return os;
}

//berguna untuk proses pembacaan data Mahasiswa dari stream, baik untuk tujuan pengolahan data maupun pemulihan data dari penyimpanan.
istream& operator>>(istream& is, Mahasiswa& mhs) {
    getline(is, mhs.nama, '_');
    is >> mhs.nim;
    is.ignore();
    is >> mhs.semester;
    is.ignore();
    getline(is, mhs.kelamin, ' ');
    getline(is, mhs.agama, ' ');
    getline(is, mhs.status);
    return is;
}

class LinkedList {
private:
    struct Node {
        Mahasiswa* mahasiswa;
        Node* next;

        Node(Mahasiswa* mhs) : mahasiswa(mhs), next(NULL) {}
    };

    Node* head;

public:
	    LinkedList() : head(NULL) {} //NULL ini menandakan bahwa linked list saat ini tidak memiliki node apapun.
	
	    ~LinkedList() { //Destruktor ini digunakan untuk menghapus semua node dalam linked list dan membebaskan memori yang telah dialokasikan.
	        Node* current = head;
	        while (current != NULL) {
	            Node* next = current->next;
	            delete current->mahasiswa;
	            delete current;
	            current = next;
	        }
	    }

    void addData(Mahasiswa* mhs) {
        Node* newNode = new Node(mhs);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void displayData() {
        Node* current = head;
        while (current != NULL) {
            current->mahasiswa->output();
            cout << endl; 
            current = current->next;
        }
    }

    Mahasiswa* search(const string& nama) { //Menerima parameter nama yang merupakan nama yang ingin dicari.
        Node* current = head; //penunjuk ke node pertama dalam linked list.
        while (current != NULL) { //Melakukan iterasi selama current tidak bernilai NULL
            if (current->mahasiswa->getNama() == nama) { //validasi nama, Jika kedua nama tersebut sama, berarti objek Mahasiswa yang dicari ditemukan.
                return current->mahasiswa; //mengembalikan objek Mahasiswa yang sesuai dengan nama yang dicari.
            }
            current = current->next;
        }
        return NULL; //penanda bahwa objek tidak ditemukan dalam linkedlist
    }

    void saveData() {
        ofstream file("students.txt"); //membuat atau membuka file dengan nama tersebut.
        //memeriksa apakah file bisa dibuka atau tidak
        if (!file) { 
            cout << "File tidak tersedia!\n";
            return;
        }

        Node* current = head; 
        while (current != NULL) { //Selama current tidak bernilai NULL artinya masih ada node dalam linked list),
            file << *(current->mahasiswa) << endl;
            current = current->next;
        }

        file.close(); //fungsi menutup file
    }

    void loadData() {
        ifstream file("students.txt");
        if (!file) {
            cout << "File tidak tersedia!\n";
            return;
        }

        string line; 
        while (getline(file, line)) { //untuk membaca satu baris dari file dan menyimpannya dalam variabel line
            istringstream iss(line);
            Mahasiswa* mhs = new Mahasiswa(); //membuat objek mahasiswa baru
            iss >> *mhs;
            addData(mhs); //penambahan data ke linkedlist
        }

        file.close(); 
    }
    
    ////urutkan dari a-z
    void sortAscending() {
    if (head == NULL || head->next == NULL) {
        return; // Tidak perlu melakukan pengurutan jika linked list kosong atau hanya memiliki satu elemen
    }

    bool swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->mahasiswa->getNama() > ptr1->next->mahasiswa->getNama()) {
                // Tukar posisi elemen jika urutan nama tidak sesuai
                swapNodes(ptr1, ptr1->next);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    	} while (swapped);
	}
	
	//proses penukaran elemen
	void swapNodes(Node* node1, Node* node2) {
	    Mahasiswa* temp = node1->mahasiswa;
	    node1->mahasiswa = node2->mahasiswa;
	    node2->mahasiswa = temp;
	}
	
	//urutkan dari z-a
	void sortDescending() {
	    if (head == NULL || head->next == NULL) {
	        return; // Tidak perlu melakukan pengurutan jika linked list kosong atau hanya memiliki satu elemen
	    }
	
	    bool swapped;
	    Node* ptr1;
	    Node* lptr = NULL;
	
	    do {
	        swapped = false;
	        ptr1 = head;
	
	        while (ptr1->next != lptr) {
	            if (ptr1->mahasiswa->getNama() < ptr1->next->mahasiswa->getNama()) {
	                // Tukar posisi elemen jika urutan nama tidak sesuai
	                swapNodes(ptr1, ptr1->next);
	                swapped = true;
	            }
	            ptr1 = ptr1->next;
	        }
	        lptr = ptr1;
	    } while (swapped);
	}


	
    bool performLogin() {
        string username;
        string password;

        cout << "Username: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        if (username == "admin" && password == "admin") { 
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    LinkedList linkedList; //menyimpan dan mengolah data mahasiswa
    int pilih, banyak, opsiSort;
    bool isDataLoaded = false;
    bool isDataModified = false;
	
	//verifikasi data apakah input sesuai dengan username dan password
    bool isLoggedIn = linkedList.performLogin();
    if (!isLoggedIn) {
        cout << "Login failed. Exiting the program.\n";
        return 0;
    }

    do {
        cout << "\n\tSistem Data Akademik Mahasiswa Prodi IF";
        cout << "\n======================================================";
        cout << "\n1. Tambah Data Mahasiswa";
        cout << "\n2. Tampilkan Data Mahasiswa";
        cout << "\n3. Edit Data Mahasiswa";
        cout << "\n4. Pencarian Data Mahasiswa";
        cout << "\n5. Pengurutan Data Mahasiswa";
        cout << "\n6. Keluar";
        cout << "\n======================================================";
        cout << "\nMasukkan Pilihan: ";
        cin >> pilih;

        std::string editNama;
        std::string cariNama;
        bool isDataFound = false;
        switch (pilih) {
            case 1: {
                system("cls");
                Mahasiswa* mhs = new Mahasiswa();
                mhs->input();
                linkedList.addData(mhs);
                linkedList.saveData();
                isDataLoaded = true;
                isDataModified = true;
                break;
            }
            case 2: {
                system("cls");
                if (!isDataLoaded) {
                    linkedList.loadData();
                    isDataLoaded = true;
                }
                linkedList.displayData();
                break;
            }
           case 3: {
                system("cls");
                if (!isDataLoaded) {
                    linkedList.loadData();
                    isDataLoaded = true;
                }

                cout << "Masukkan Nama Mahasiswa Yang Ingin di edit: ";
                cin.ignore();
                getline(cin, editNama);

                Mahasiswa* foundMahasiswa = linkedList.search(editNama);
                if (foundMahasiswa != NULL) {
                    Mahasiswa copyMahasiswa = *foundMahasiswa;
                    copyMahasiswa.input();
                    *foundMahasiswa = copyMahasiswa;
                    linkedList.saveData();
                    isDataModified = true;
                } else {
                    cout << "Data tidak ditemukan\n";
                }
                break;
            }
            case 4: {
                system("cls");
                isDataFound = false;
                cout << "Masukkan nama Mahasiswa yang ingin dicari: ";
                cin.ignore();
                getline(cin, cariNama);
                Mahasiswa* foundMahasiswa = linkedList.search(cariNama);
                if (foundMahasiswa != NULL) {
                    foundMahasiswa->output();
                    isDataFound = true;
                }
                if (!isDataFound) {
                    cout << "Data tidak ditemukan\n";
                }
                break;
            }
            case 5: {
                system("cls");
                if (!isDataLoaded) {
                    linkedList.loadData();
                    isDataLoaded = true;
                }
                cout << "\n======================================================\n";
                cout << "Pilihan Pengurutan\n";
                cout << "1. Ascending\n";
                cout << "2. Descending\n";
                cout << "======================================================\n";
                cout << "Pilih opsi: ";
                cin >> opsiSort;
                if (opsiSort == 1) {
        			linkedList.sortAscending(); // Panggil metode sorting ascending
    			} else if (opsiSort == 2) {
        			linkedList.sortDescending(); // Panggil metode sorting descending
    			}
                linkedList.displayData();
                break;
            }
            case 6: {
                system("cls");
                if (isDataModified) {
                    char saveChoice;
                    cout << "Apakah Anda ingin menyimpan perubahan data (Y/N)? ";
                    cin >> saveChoice;
                    if (saveChoice == 'Y' || saveChoice == 'y') {
                        linkedList.saveData();
                    }
                }
                return 0;
            }
            default:
                cout << "\nMohon pilih menu yang ada! ";
        }
        cout << "\n";
        system("pause");
        system("cls");

    } while (pilih != 6);

    if (isDataModified) {
        char saveChoice;
        cout << "Apakah Anda ingin menyimpan perubahan data (Y/N)? ";
        cin >> saveChoice;
        if (saveChoice == 'Y' || saveChoice == 'y') {
            linkedList.saveData();
        }
    }

    return 0;
}

