#include <iostream>
#include <conio.h>
using namespace std;

#include "MenuItem.cpp"
#include "MenuList.cpp"

class Order {
	 	private:
	 		MenuList items;
	 		int total;
	 	public:
	 		Order() {
	 			total = 0;
	 		}
	 		void add(MenuItem* item) {
	 			items.add(item->getName(), item->getPrice());
	 			total += item->getPrice();
	 		}
	 		void remove(int index) {
	 			MenuItem* item = items.get(index);
	 			if (item != NULL) {
	 				items.remove(index);
	 				total -= item->getPrice();
	 			}
	 		}
	 		void display() {
				if (items.isEmpty()) {
	 				cout << "Order Kosong." << endl;
	 			} else {
	 				cout << "Order: " << endl;
	 				for (int i = 0; i < items.size(); i++) {
	 					MenuItem* item = items.get(i);
	 					cout <<"|"<< i+1 << ". " << item->getName() << "\t| " <<"\Rp "<<item->getPrice()<<"|"<< endl;
	 				}
	 				cout<<endl;
	 				cout <<"Total = "<<"\Rp "<<total<<endl;
	 			}
	 		}
	};