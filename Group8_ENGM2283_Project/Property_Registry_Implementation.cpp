#include "Property_Registry_Class.h"
#include "Property_Controller.h"

// CONSTRUCTOR IMPLEMENTATION

date::date(int bought, int built) : date_bought(bought), year_built(built) {}

owner::owner(string n, int id, string em) : name(n), tax_id(id), email(em) {}

property::property(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr) : guy(n, id, em), info(bought, built), address(adr), square_feet(sqft), market_price(mpr) {}

residential::residential(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr, int bdc): property(n, id, em, bought, built, adr, sqft, mpr), bedroom_count(bdc) {}

commercial::commercial(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr, string btype) : property(n, id, em, bought, built, adr, sqft, mpr), business_type(btype) {}
//_____________________________________________________________________________________________________________________________________________________________________________________________

// METHOD IMPLEMENTATION FOR COMPOSITION CLASSES date and owner

bool date::isNewHouse() const {// new = built past 2020
	return year_built > 2020;
}
void date::date_display() const {
	cout << "Year built: " << year_built << endl;
	cout << "Year bought: " << date_bought << endl;

	if (isNewHouse()) {
		cout << "New House!";
	}
}

// Helper functions for is valid email
static bool is_char(char c) {
	return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}


bool owner::isValidEmail() const {
	if (!is_char(email[0])) return false;
	int At = -1;
	int dot = -1;


	for (int i = 0; i < email.length(); i++) {
		if (email[i] == '@') {
			At = i;
		}
		else if (email[i] == '.'){
			dot = i;
		}
	}
	if (At == -1 || dot == -1) {
		return false;
	}
	if (At > dot) {
		return false;
	}
	return !(dot >= (email.length() - 1));
}
void owner::owner_display() const {
	cout << "Owner name: " << name;
	cout << "Tax ID: " << tax_id;
	cout << "Email: " << email;
}

string owner::get_name() const {
	return name;
}
string owner::get_email() const {
	return email;
}
int owner::get_taxid() const {
	return tax_id;
}

// METHOD IMPLEMENTATION for BASE(property) class


// BASE CLASS METHOD IMPLEMENTATION
float property::get_square_feet() const {
	return square_feet;
}

string property::get_address() const {
	return address;
}

void property::display() const {
	guy.owner_display();
	info.date_display();
	cout << "Address: " << address << endl;
	cout << "Square Footage : " << square_feet << " sq ft" << endl;
	cout << "Market Price: $" << market_price << endl;
}

// CHILD CLASS METHOD IMPLEMENTATION

void residential::display() const {
	cout << "Residential Property: " << endl;
	property::display();
	cout << "Bedrooms: " << bedroom_count << endl;
}

void commercial::display() const {
	cout << "Commercial Property: " << endl;
	property::display();
	cout << "Business Type: " << business_type << endl;
}


//_____________________________________________________________________________________________________________________________________________________________________________________________












// HELPER FUNCTIONS

template <typename T>
void Retrieve(const property_controller<T>& list, auto search, char choice) { //can retrieve by address, owner name, id or email, user will input which choice they want
	
	try {
		if (choice == 'a') {
			(list.retrieve([search](const T & a) {
				return search == a.get_address();
			})).display();
		}
		//call retrieve in here with lambda function call, having search in the scope 
		else if (choice == 'n') {
			(list.retrieve([search](const T & a) {
				return search == a.get_name();
			})).display();
		}
		else if (choice == 'i') {
			(list.retrieve([search](const T & a) {
				return search == a.get_taxid();
			})).display();
		}
		else if (choice == 'e') {
			(list.retrieve([search](const T & a) {
				return search == a.get_email();
			})).display();
		}
		else {
			throw invalid_argument("Wrong charachter! (Try n - name search, i - tax id search or e - email search");
		}
	}
	catch(const exception& e){

		cout << "Search Error: " << e.what() << endl;
																	//lambda function call is ([search]( const property& p) { return search == p.get_(choice)()});
	}
																//make sure that the correct getter is used according to choice
												
																//alternatively replace choice with and enum and do switch case statments, thats way cooler 
												

}

template <typename T>
void Sort(property_controller<T>& list, char choice) { //can sort by market price, or by square feet
															
	try {
		if (choice == 'p') {
			list.sort([](const T& a, const T& b) {
				return a.get_market_price() < b.get_market_price();
				});
			cout << "Sorted by Market Price." << endl;
		}
		else if (choice == 's') {
			list.sort([](const T& a, const T& b) {
				return a.get_square_feet() < b.get_square_feet();
				});
			cout << "Sorted by Square Footage." << endl;
		}
		else {
			throw invalid_argument("Wrong charachter! (p - price sort, s - square footage sort)");
		}

	}
	catch (const exception& e) {
		cout << "Sort Error: " << e.what() << endl;
	}
																//call sort in here with lambda function call as the parameter

																//lambda function call is ([](const property& a, const property& b) { return a.get_(choice)() < b.get_(choice)() });
																// 
																// 																//make sure that the correct getter is used according to choice
																//alternatively replace choice with and enum and do switch case statments, thats way cooler 

}

template <typename T>
void remove(property_controller<T>& list, auto del, char choice) { // delete element by address, owner name, owner id, or email

	try {
		if (choice == 'a') {
			list.Delete([del](const T& p) {
				return p.get_adress() == del; });
		} else if (choice == 'n') {
			list.Delete([del](const T& p) {
				return p.get_name() == del; });
		}
		else if (choice == 'i') {
			list.Delete([del](const T& p) {
				return p.get_taxid() == del; });
		}
		else if (choice == 'e') {
			list.Delete([del](const T& p) {
				return p.get_email() == del; });
		}
		else {
			throw invalid_argument("Wrong charachter!(Try n - name search, i - tax id search or e - email search");
		}	
	}
	catch (const exception& e) {
		cout << "Remove Error: " << e.what() << endl;
	}														//call delete in here with lambda function call as the paramete
}																//lmabda function call is ([del](property& p){ return del==p.get_(choice)()});

																// make sure that the correct getter is used according to choice

																//alternatively replace choice with and enum and do switch case statments, thats way cooler 





//Honestly after these we are mostly done 
