#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
	class Menu {
		private:
			string nama;
			int harga;
		 	Menu* next;
		public:
		 	Menu(string nama, int harga) {
				this->nama = nama;
		 		this->harga = harga;
		 		this->next = NULL;
		 	}
			void setNama(string nama) {
			 	this->nama = nama;
			}
			string getNama() {
			 	return nama;
			}
			void setHarga(int harga) {
			 	this->harga = harga;
			}
			int getHarga() {
			 	return harga;
			}
			void setNext(Menu* next) {
			 	this->next = next;
			}
			Menu* getNext() {
			 	return next;
			}
	};
	
	class DaftarMenu {
		private:
		 	Menu* head;
		 	int hitung;
		public:
		 	DaftarMenu() {
		 		head = NULL;
		 		hitung = 0;
		 	}
		 	bool isEmpty() {
			 	return head == NULL;
			}
			int size() {
			 	return hitung;
			}
			void add(string nama, int harga) {
			 	Menu* item = new Menu(nama, harga);
			 	if (isEmpty()) {
			 		head = item;
			 	} else {
			 		Menu* current = head;
			 		while (current->getNext() != NULL) {
			 			current = current->getNext();
			 		}
			 		current->setNext(item);
			 	}
				hitung++;
			}
			void remove(int index) {
			 	if (index < 0 || index >= hitung) {
			 		cout << "Index Tidak Valid." << endl;
			 		return;
				}
				Menu* current = head;
				if (index == 0) {
				 	head = current->getNext();
			 	} else {
				 	for (int i = 0; i < index-1; i++) {
				 		current = current->getNext();
				 	}
					Menu* temp = current->getNext();
			 		current->setNext(temp->getNext());
			 		delete temp;
			 	}
			 	hitung--;
			 }
			Menu* get(int index) {
				if (index < 0 || index >= hitung) {
					cout << "Index Tidak Valid." << endl;
			 		return NULL;
			 	}
				Menu* current = head;
			 	for (int i = 0; i < index; i++) {
			 		current = current->getNext();
			 	}
			 	return current;
			}
	};
	
	class Order {
	 	private:
	 		DaftarMenu pesanan;
	 		int total;
	 	public:
	 		Order() {
	 			total = 0;
	 		}
	 		void add(Menu* item) {
	 			pesanan.add(item->getNama(), item->getHarga());
	 			total += item->getHarga();
	 		}
	 		void remove(int index) {
	 			Menu* item = pesanan.get(index);
	 			if (item != NULL) {
	 				pesanan.remove(index);
	 				total -= item->getHarga();
	 			}
	 		}
	 		void display() {
				if (pesanan.isEmpty()) {
	 				cout << "\t Pesanan Masih Kosong" << endl;
	 			} else {
	 				cout << "\t Pesanan = " << endl;
	 				for (int i=0; i<pesanan.size(); i++) {
	 					Menu* item = pesanan.get(i);
	 					cout <<"\t"<<i+1 << ". " << item->getNama() << " Rp "<<item->getHarga()<<endl;
	 				}
	 				cout<<endl;
	 				cout <<"\tTotal = "<<" Rp "<<total<<endl;
	 			}
	 		}
	};
	
int main() { 
	DaftarMenu pesanan;
	char lanjut;

// Makanan
	pesanan.add("Ramen Beef		", 33000);
	pesanan.add("Ramen Chicken	", 29000 );
	pesanan.add("Ramen Miso Beef	", 35000); 
	pesanan.add("Ramen Miso Chicken	", 30000);
	pesanan.add("Ramen Beef Karage	", 40000);
	pesanan.add("Ramen Chicken Kararge", 31000);
	pesanan.add("Ramen Beef Popcorn	", 31000);
	pesanan.add("Ramen Chicken Popcorn", 31000);

//Minuman
	pesanan.add(" Ocha Original	", 7000 );
	pesanan.add("Ocha Manis		", 10000);
	pesanan.add("Leci Squash		", 12000);
	pesanan.add("Melon Squash	", 12000);
	pesanan.add("Yakult Strawberry	", 15000); 
	pesanan.add("Yakult Melon	", 20000);
	pesanan.add("Blue Sparkling	", 20000);
	pesanan.add("Red Sparkling	", 20000);
	
	Order order;
	do {
		system("cls"); 
		cout<<"--------------------------------------------------------------"<<endl;
		cout<<"\t Nama	: Dhevi Puspitasari"<<endl;
		cout<<"\t NPM	: 21081010165"<<endl;
		cout<<"\t Kelas	: Pemrograman Berorientasi Objek C081"<<endl;
		cout<<"--------------------------------------------------------------"<<endl<<endl;

		cout<<"\t SELAMAT DATANG DI RESTORAN KUY RAMEN! "<<endl; 
		cout<<endl; 
		cout<<"\t MENU MAKANAN :"<<endl;
		cout<<"\t ------------------------"<<endl;
		for (int i=0; i<8; i++) { 
			Menu* item = pesanan.get(i); 
			cout<<"\t\t"<< i+1 <<". "<< item->getNama() <<" Rp "<<item->getHarga() <<endl;
		}
		cout<<endl; 
		cout<<"\t MENU MINUMAN :" << endl;
		cout<<"\t ------------------------"<<endl;
		for (int i=8; i<pesanan.size(); i++){
			Menu* item = pesanan.get(i);
			cout<<"\t\t"<< i+1 <<". "<< item->getNama() <<" Rp "<<item->getHarga() <<endl;
		} 
		cout<<endl;
		cout<<"\t ------------------------------------------------------"<<endl<<endl;
		
		cout<<"\t Menu Pilihan : "<<endl;
		puts("\t\t 1. Pesan Makanan"); 
		puts("\t\t 2. Pesan Minuman"); 
		puts("\t\t 3. Lihat Pesanan"); 
		puts("\t\t 4. Batalkan Pesanan");
		puts("\t\t 5. Bayar \n");
		puts("\t Pilihan (Esc for EXIT) : "); 
			
		                       
		switch(getch()) {
			case '1' :
				int pilihan; 
				system("cls");
				cout<<"\tMenu Makanan :"<<endl;
				cout<<"\t\tNo"<< "\tNama Makanan" <<"\t\tHarga "<<endl;
				for (int i=0; i<8; i++) { 
					Menu* item = pesanan.get(i); 
					cout<<"\t\t"<< i+1 <<". "<<item->getNama() <<"\tRp "<<item->getHarga() <<endl;
				}              
				do {
					cout<<"\n\tPilihan (0 = kembali): ";
					cin>>pilihan;	
					if (pilihan>0 && pilihan <= pesanan.size()) { 
						Menu* item = pesanan.get(pilihan-1);
						order.add(item); 
						cout<<"\t pesanan ditambahkan "<<endl;
	
					}else if (pilihan != 0) {
						cout <<"Pilihan tidak ada" << endl;
					}
				} while(pilihan != 0); 
				cout << "\t(press enter)"<< endl;
			break;
			case '2' :
				system("cls");
				cout<<"\tMenu Minuman :"<<endl;
				cout<<"\t\tNo"<< "\tNama Minuman" <<"\tHarga "<<endl;
				for (int i=8; i<pesanan.size(); i++) { 
					Menu* item = pesanan.get(i); 
					cout<<"\t\t"<< i+1 <<". "<<item->getNama() <<"Rp "<<item->getHarga() <<endl;
				}              
				do {
					cout<<"\n\tPilihan (0 = kembali): ";
					cin>>pilihan;	
					if (pilihan>0 && pilihan <= pesanan.size()) { 
						Menu* item = pesanan.get(pilihan-1);
						order.add(item); 
						cout<<"\t pesanan ditambahkan "<<endl;
	
					}else if (pilihan != 0) {
						cout <<"Pilihan tidak ada" << endl;
					}
				} while(pilihan != 0); 
				cout << "\t(press enter)"<< endl;
			break;
			case '3' :
				system("cls");
				order.display(); 
				cout << "\t(press enter)"<<endl;
			break;
			case '4' :
				int index;
				system("cls");
				order.display();
				do {
					cout<<endl<<"\tMenu yang ingin Dibatalkan (0 = kembali) : ";     					
					cin >> index;
					if (index > 0 && index <= pesanan.size()) {
						order.remove(index-1);
						order.display();
					}
					else if (index != 0) {
						cout<<"Index Tidak Valid."<<endl;
					}
				}while (index != 0);
				cout<<"\t(press enter)"<<endl;
			break;
			case '5' :
				system("cls"); 
				cout<<"\tPembayaran menggunakan :"<<endl;      
				cout<<"\t\t 1. Menggunakan CASH"<<endl;
				cout<<"\t\t 2. Menggunakan DEBIT"<<endl;
				       
				do {
					cout<<"\n\t Pilihan : ";
					cin>>pilihan;	
					if (pilihan=1) { 
						cout<<"\t Anda memilih CASH"<<endl;
					}else if (pilihan=2) { 
						cout<<"\t Anda memilih DEBIT"<<endl;
					}else if (pilihan != 0) {
						cout <<"\t Pilihan tidak ada" << endl;
					}
					cout<<"\n\t Rincian =" <<endl;
					order.display();
					cout<<"\t Silahkan Bayar di kasir!!"<<endl; 
					cout<<"\t Terima Kasih!!" <<endl;
				} while (lanjut == 'Y' || lanjut == 'y'); 
				  cout<<"\t(press enter)"<<endl;
			break;
		}
		
	} while (getch()!=27);
	
	cout<<endl<<"ARIGATOU!!!" <<endl;
				
	return 0;
}









	
