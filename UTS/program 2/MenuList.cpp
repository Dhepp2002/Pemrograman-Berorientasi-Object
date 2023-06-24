#include <iostream>
#include <conio.h>
using namespace std;

#include "MenuItem.cpp"

class MenuList {
		private:
		 	MenuItem* head;
		 	int count;
		public:
		 	MenuList() {
		 	head = NULL;
		 	count = 0;
		 	}
		 	bool isEmpty() {
			 	return head == NULL;
			}
			int size() {
			 	return count;
			}
			void add(string name, int price) {
			 	MenuItem* item = new MenuItem(name, price);
			 	if (isEmpty()) {
			 		head = item;
			 	} else {
			 		MenuItem* current = head;
			 		while (current->getNext() != NULL) {
			 			current = current->getNext();
			 		}
			 		current->setNext(item);
			 	}
				count++;
			}
			
			void remove(int index) {
			 	if (index < 0 || index >= count) {
			 		cout << "Index Tidak Valid." << endl;
			 		return;
				}
				MenuItem* current = head;
				if (index == 0) {
				 	head = current->getNext();
			 	} else {
				 	for (int i = 0; i < index-1; i++) {
				 		current = current->getNext();
				 	}
					MenuItem* temp = current->getNext();
			 		current->setNext(temp->getNext());
			 		delete temp;
			 	}
			 	count--;
			 }
			MenuItem* get(int index) {
				if (index < 0 || index >= count) {
					cout << "Index Tidak Valid." << endl;
			 		return NULL;
			 	}
				MenuItem* current = head;
			 	for (int i = 0; i < index; i++) {
			 		current = current->getNext();
			 	}
			 	return current;
			}
	};