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




// BASE CLASS METHOD IMPLEMENTATION
float property::get_square_feet() const {
	return square_feet;
}

string property::get_address() const {
	return address;
}
float property::get_market_price() const {
	return market_price;
}

void property::display() const {
	guy.owner_display();
	info.date_display();
	cout << "Address: " << address << endl;
	cout << "Square Footage : " << square_feet << " sq ft" << endl;
	cout << "Market Price: $" << market_price << endl;
}

const owner& property::get_owner() const {
	return guy;
}

const date& property::get_date() const {
	return info;
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













