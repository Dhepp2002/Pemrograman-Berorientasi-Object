#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int total;

class MenuSatuan {
	private: 
		string nmsatuan;
		int hargasatuan;
		MenuSatuan* next;
	public:
		MenuSatuan(string nmsatuan, int hargasatuan) {
			this->nmsatuan = nmsatuan;
			this->hargasatuan = hargasatuan;
			this->next = NULL;
		}
		
		void setNamasatuan(string nmsatuan) {
			this->nmsatuan = nmsatuan;
		}
		
		string getNamaSatuan() {
			return nmsatuan;
		}
		
		void setHargasatuan(int hargasatuan) {
			this->hargasatuan = hargasatuan;
		}
		
		int getHargasatuan() {
			return hargasatuan;
		}
		
		void setNext(MenuSatuan* next) {
			this->next = next;
		}
		
		MenuSatuan* getNext() {
			return next;
		}
		
};

class Restoran {
	private:
		MenuSatuan* head;
		MenuSatuan* tail;
		int uang, kembalian;
	public:
		Restoran() {
			head = NULL;
			tail = NULL;
		}
		
		void tambahMenu(string nmsatuan, int hargasatuan) {
			MenuSatuan* menu = new MenuSatuan(nmsatuan, hargasatuan);
			if (head == NULL) {
				head = menu;
				tail = menu;
			} else {
				tail->setNext(menu);
				tail = menu;
			}
		}
		
		void tampilkanMenu() {
			MenuSatuan* current = head;
			cout << endl << endl;
			cout << "   ---------------------------------------------" << endl;
			cout << " ||	 Daftar Menu Restoran Madagaskar        ||  " << endl;
			cout << "   ---------------------------------------------" << endl;
			cout << " || No.\t    || Nama Menu \t || Harga \t|| " << endl;
			int i = 1;
			while (current != NULL) {
				cout << " || "<< i << ".\t    || " << current->getNamaSatuan() << "\t || Rp" << current->getHargasatuan() << "\t||"<< endl;
				current = current->getNext();
				i++;
			}
			cout << "   ---------------------------------------------" << endl;
		}
		
		void pesanMenu(int nomor, int jumlah) {
			MenuSatuan* current = head;
			int i = 1;
			while (current != NULL && i < nomor) {
			current = current->getNext();
			i++;
				}
				if (current != NULL) {
					int subtotal = current->getHargasatuan() * jumlah;
					cout << endl << endl;
					cout << "   -------------------------------------------------------------------------------" << endl;
					cout << " ||\t PESANAN \t || \t QTY \t || \t HARGA \t || \t SUB TOTAL \t || " << endl;
					cout << " ||\t " << current->getNamaSatuan() << " \t || \t " << jumlah << " \t || \t " << current->getHargasatuan() << " \t || \t  " << subtotal << " \t || " << endl;
					
					total += subtotal;
				} else {
					cout << "Menu tidak ditemukan" << endl;
				}
			}
	
	void tampilkanTotal() {
		
		cout << "Total	: Rp" << total << endl;
	}
	
	void bayar() {
		cout << "Uang	: Rp";
		cin >> uang;
		kembalian = uang - total;
		cout << endl << "Kembalian	: Rp" << kembalian;
	}
	
	
	void deletePesanan() {
    total = 0;
	}
	
	


};

int main() {
		Restoran restoran;
		int pilihan;
		int nomor, jumlah;
		char lanjut;
		
			restoran.tambahMenu("Soto Madura", 12000);
			restoran.tambahMenu("Soto Banjar", 14000);
			restoran.tambahMenu("Soto Betawi", 13000);
			restoran.tambahMenu("Soto Daging", 15000);
			restoran.tambahMenu("Soto Ayam", 10000);
			restoran.tambahMenu("Jeruk Peras", 5000);
			restoran.tambahMenu("Teh Tarik", 5000);
			restoran.tambahMenu("Air putih", 4000);
			restoran.tambahMenu("Teh Hanget", 4000);
			restoran.tambahMenu("Jeruk Hangat", 4000);
		
			restoran.tampilkanMenu();
		
		
		do {
			
			cout << endl << endl;
			cout << "1. Pesan Makanan" << endl;
			cout << "2. Clear Pesanan" << endl;
			cout << "3. Bayar" << endl << endl;
			
			cout << "Masukkan pilihan : ";
			cin >> pilihan;
			cout << endl << endl;
			
		  switch (pilihan) {
		        case 1:
		            cout << "Pesanan (input nomer)  : ";
		            cin >> nomor;
		            cout << "Jumlah pesanan (porsi) : ";
		            cin >> jumlah;
		            restoran.pesanMenu(nomor, jumlah);
		            cout << endl;
		            break;
		        
		        case 2:
				    restoran.tampilkanMenu();
				    break;
		
				
				case 3:
		            restoran.tampilkanTotal();
		            restoran.bayar();
		            break;
		        
		
		        default:
		            cout << "Oops! Opsti tidak tersedia!" << endl;
		            break;
		    }
		
		    cout << "Anda ingin memesan lagi? (Y/N)";
		    cin >> lanjut;
		} while (lanjut == 'Y' || lanjut == 'y');
		
		return 0;
}