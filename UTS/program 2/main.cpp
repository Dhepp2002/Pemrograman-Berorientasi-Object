#include <iostream>
#include <conio.h>
using namespace std;

#include "MenuItem.cpp"
#include "MenuList.cpp"
#include "Order.cpp"

int main() { 
	MenuList menu;

// Makanan
	menu.add("Nasi Goreng", 10000);
	menu.add("Mie Goreng", 8000);
	menu.add("Ayam Goreng", 15000); 
	menu.add("Ikan Bakar", 30000);
	menu.add("Sate Ayan", 10000);
	menu.add("Bakso", 10000);

//Minuman
	menu.add("Es Teh", 3000);
	menu.add("Es Degan", 5000);
	menu.add("Es Jeruk", 4000);
	menu.add("Kopi", 5000);
	menu.add("Jus Jambu", 6000); 
	menu.add("Jus Apukat", 6000);
	
	Order order;
		do {
		system("cls"); 
		cout<<"Selamat Datang Di Restoran JUOSSS! "<<endl; 
		cout<<endl; 
		cout<<"Makanan :"<<endl;
		for (int i=0; i<6; i++) { 
			MenuItem* item = menu.get(i); 
			cout<<"|"<< i+1 <<". "<< item->getName() << "\t| " <<"\Rp "<<item->getPrice()<<"|"<< endl;
		}
		cout<<endl; 
		cout<<"Minuman :" << endl;
		for (int i=6; i<menu.size(); i++){
			MenuItem* item = menu.get(i);
			cout<<"|"<< i+1 <<". "<< item->getName() << "\t| " <<"\Rp "<<item->getPrice()<<"|"<< endl;
		} 
		cout<<endl;
		cout<<"Menu : "<<endl;
		puts("1. Pesan Makanan"); 
		puts("2. Pesan Minuman"); 
		puts("3. Lihat Pesanan");
		puts("4. Batalkan Pesanan");
		puts("5. Bayar");
		puts("Pilihan (Esc for EXIT): ");
		switch(getch()){
			case '1' :
				int choice; 
				system("cls");
				cout<<"Makanan : " << endl;
				for (int i=0; i<6; i++){
					MenuItem* item = menu.get(i); 
					cout<<"|"<< i+1 << ". " << item->getName() << "\t| " <<"\Rp "<<item->getPrice()<<"|"<<endl;          ;
				}
				do {
					cout<<endl<<"Pilihan Menu (0. exit): ";
					cin>>choice;	
					if (choice>0 && choice <= menu.size()) { 
						MenuItem* item = menu.get(choice-1);
						order.add(item); 
						cout<<item->getName()<<" ditambahkan ke Menu Order."<<endl;
					}else if (choice != 0) {
						cout <<"Pilihan Tidak Valid." << endl;
					}
				} while(choice != 0); 
				cout << "\nPRESS ENTER"<< endl;
			break;
			case '2' :
				system("cls");
				cout<<endl;
				cout<<"Minuman : " << endl;                                      
				for (int i=7; i<menu.size(); i++){
					MenuItem* item = menu.get(i);
					cout<<"|"<< i+1 << ". " << item->getName() << "\t|" <<"\Rp "<<item->getPrice()<<"|"<<endl;
				}
				do {
					cout<<endl<<"Pilihan Menu (0. exit): ";
					cin>>choice;	
					if (choice>0 && choice <= menu.size()) { 
						MenuItem* item = menu.get(choice-1);
						order.add(item); 
						cout<<item->getName()<<" ditambahkan ke Menu Order."<<endl;
					}else if (choice != 0) {
						cout <<"Pilihan Tidak Valid." << endl;
					}
				} while(choice != 0); 
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
					if (index > 0 && index <= menu.size()) {
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
