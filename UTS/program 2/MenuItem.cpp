class MenuItem {
	private:
		string name;
	int price;
	 	MenuItem* next;
	public:
		MenuItem(string name, int price) {
			this->name = name;
	 		this->price = price;
	 		this->next = NULL;
	 	}
		void setName(string name) {
		 	this->name = name;
		}
		string getName() {
		 	return name;
		}
		void setPrice(int price) {
		 	this->price = price;
		}
		int getPrice() {
		 	return price;
		}
		void setNext(MenuItem* next) {
		 	this->next = next;
		}
		MenuItem* getNext() {
		 	return next;
		}
};