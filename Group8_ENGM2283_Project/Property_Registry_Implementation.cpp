#include "Property_Registry_Class.h"

// CONSTRUCTOR IMPLEMENTATION

date::date(int bought, int built) : date_bought(bought), year_built(built) {}

owner::owner(string n, int id, string em) : name(n), tax_id(id), email(em) {}

property::property(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr) : guy(n, id, em), info(bought, built), address(adr), square_feet(sqft), market_price(mpr) {}

residental::residental(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr, int bdc): property(n, id, em, bought, built, adr, sqft, mpr), bedroom_count(bdc) {}

commercial::commercial(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr, string btype) : property(n, id, em, bought, built, adr, sqft, mpr), business_type(btype) {}
//_____________________________________________________________________________________________________________________________________________________________________________________________

// METHOD IMPLEMENTATION FOR COMPOSITION CLASSES date and owner

bool date::isNewHouse() {// new = built past 2020
	return year_built > 2020;
}
void date::display(ostream& out) {
	out << "Year built: " << year_built << endl;
	out << "Year bought: " << date_bought << endl;

	if (isNewHouse()) {
		out << "New House!";
	}
}


bool owner::isValidEmail() {
	return email > 2000;           // ?????????????????????????? How do we check if the email is valid ??????????????????????

}
void owner::display(ostream& out) {
	out << "Owner name: " << name;
	out << "Tax ID: " << tax_id;
	out << "Email: " << email;
}

// METHOD IMPLEMENTATION for BASE(property) class

float property::get_square_feet() const {
	return square_feet;
}

string property::get_address() const {
	return address;
}

float property::get_market_price() const {
	return market_price;
}

void property::display(ostream& out) const {
	out << "The market price is: " << get_market_price() << endl;
	out << "The adress is: " << get_address() << endl;
	out << "The square footage is: " << get_square_feet() << endl;
}

void property::create_property(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr) {
	this->guy = owner(n, id, em);

	this->info = date(bought, built);

	this->address = adr;
	this->square_feet = sqft;
	this->market_price = mpr;
}

//_____________________________________________________________________________________________________________________________________________________________________________________________

// METHOD IMPLEMENTATION for DERVIVED(residental) class

void residental::display(ostream& out) {

}




//_____________________________________________________________________________________________________________________________________________________________________________________________

// METHOD IMPLEMENTATION for DERVIVED(residential) class

void residental::display(ostream& out) {

}

//_____________________________________________________________________________________________________________________________________________________________________________________________


