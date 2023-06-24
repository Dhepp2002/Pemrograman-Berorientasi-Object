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
	 		DaftarMenu daftar;
	 		int total;
	 	public:
	 		Order() {
	 			total = 0;
	 		}
	 		void add(Menu* item) {
	 			daftar.add(item->getNama(), item->getHarga());
	 			total += item->getHarga();
	 		}
	 		void remove(int index) {
	 			Menu* item = daftar.get(index);
	 			if (item != NULL) {
	 				daftar.remove(index);
	 				total -= item->getHarga();
	 			}
	 		}
	 		void display() {
				if (daftar.isEmpty()) {
	 				cout << "Pesanan Masih Kosong" << endl;
	 			} else {
	 				cout << "Pesanan = " << endl;
	 				for (int i = 0; i < daftar.size(); i++) {
	 					Menu* item = daftar.get(i);
	 					cout <<"\n|"<< i+1 << ". " << item->getNama() << "\t| " <<" Rp "<<item->getHarga()<<"|"<< endl;
	 				}
	 				cout<<endl;
	 				cout <<"\nTotal = "<<" Rp "<<total<<endl;
	 			}
	 		}
	};
	
int main() { 
	DaftarMenu hidangan;

// Makanan
	hidangan.add("Ramen Beef		", 33000);
	hidangan.add("Ramen Chicken	", 29000 );
	hidangan.add("Ramen Miso Beef	", 35000); 
	hidangan.add("Ramen Miso Chicken	", 30000);
	hidangan.add("Ramen Beef Karage	", 40000);
	hidangan.add("Ramen Chicken Kararge", 31000);
	hidangan.add("Ramen Beef Popcorn	", 31000);
	hidangan.add("Ramen Chicken Popcorn", 31000);

//Minuman
	hidangan.add("Ocha Original", 7000 );
	hidangan.add("Ocha Manis	", 10000);
	hidangan.add("Leci Squash	", 12000);
	hidangan.add("Melon Squash", 12000);
	hidangan.add("Yakult Strawberry", 15000); 
	hidangan.add("Yakult Melon", 20000);
	hidangan.add("Blue Sparkling", 20000);
	hidangan.add("Red Sparkling", 20000);
	
	Order order;
	do {
		system("cls"); 
		cout<<"--------------------------------------------------------------"<<endl;
		cout<<"\t Nama	: Dhevi Puspitasari"<<endl;
		cout<<"\t NPM	: 21081010165"<<endl;
		cout<<"\t Kelas	: Pemrograman Berorientasi Objek C081"<<endl;
		cout<<"--------------------------------------------------------------"<<endl<<endl;

		cout<<"\tSelamat Datang Di Restoran KUY Ramen! "<<endl; 
		cout<<endl; 
		cout<<"\tMenu Makanan :"<<endl;
		cout<<"\t------------------------"<<endl;
		for (int i=0; i<8; i++) { 
			Menu* item = hidangan.get(i); 
			cout<<"\t\t"<< i+1 <<". "<< item->getNama() << "\t| " <<" Rp "<<item->getHarga()<<"|"<< endl;
		}
		cout<<endl; 
		cout<<"\tMenu Minuman :" << endl;
		cout<<"\t------------------------"<<endl;
		for (int i=8; i<hidangan.size(); i++){
			Menu* item = hidangan.get(i);
			cout<<"\t\t"<< i+1 <<". "<< item->getNama() << "\t| " <<" Rp "<<item->getHarga()<<"|"<< endl;
		} 
		cout<<endl;
		cout<<"\t------------------------------------------------------"<<endl<<endl;
		
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
				cout<<"\t------------------------"<<endl;
				for (int i=0; i<8; i++) { 
					Menu* item = hidangan.get(i); 
					cout<<"\t\t"<< i+1 <<". "<< item->getNama() << "\t| " <<" Rp "<<item->getHarga()<<"|"<< endl;
				}              
				do {
					cout<<"\n\tPilihan (0. exit): ";
					cin>>pilihan;	
					if (pilihan>0 && pilihan <= hidangan.size()) { 
						Menu* item = hidangan.get(pilihan-1);
						order.add(item); 
						cout<<"\t\t"<<item->getNama()<<" ditambahkan ke Menu Order."<<endl;
					}else if (pilihan != 0) {
						cout <<"Pilihan tidak ada" << endl;
					}
				} while(pilihan != 0); 
				cout << "\n\tpress enter"<< endl;
			break;
			case '2' :
				system("cls");
				cout<<endl;
				cout<<"Minuman : " << endl;                                      
				for (int i=8; i<hidangan.size(); i++){
					Menu* item = hidangan.get(i);
					cout<<"|"<< i+1 << ". " << item->getNama() << "\t|" <<" Rp "<<item->getHarga()<<"|"<<endl;
				}          
				do {
					cout<<endl<<"Pilihan Menu (0. exit): ";
					cin>>pilihan;	
					if (pilihan>0 && pilihan <= hidangan.size()) { 
						Menu* item = hidangan.get(pilihan-1);
						order.add(item); 
						cout<<item->getNama()<<" ditambahkan ke Menu Order."<<endl;
					}else if (pilihan != 0) {
						cout <<"Pilihan Tidak Valid." << endl;
					}
				} while(pilihan != 0); 
				cout << "\nPRESS ENTER"<< endl;
			break;
			case '3' :
				system("cls");
				order.display(); 
				cout << "\nPRESS ENTER"<<endl;
			break;
			case '4' :
				int index;
				system("cls");
				order.display();
				do {
					cout<<endl<<"Menu yang ingin Dibatalkan (0. Keluar) : ";     					
					cin >> index;
					if (index > 0 && index <= hidangan.size()) {
						order.remove(index-1);
						order.display();
					}
					else if (index != 0) {
						cout<<"Index Tidak Valid."<<endl;
					}
				}while (index != 0);
				cout<<"\nPRESS ENTER"<<endl;
			break;
			case '5' :
				int money;
				system("cls"); 
				order.display();
				cout<<"\n\nSilahkan Bayar dikasir dengan Total yang tertera" <<endl; 
				cout<<"Terima Kasih!!" <<endl;
				exit(0);
			break;
		}
		
	} while (getch()!=27);
	
	cout<<endl<<"Terima Kasih Telah Makan di Restoran Kami! Sampai Jumpaa" <<endl;
				
	return 0;
}








	
