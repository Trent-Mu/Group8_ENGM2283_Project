#include "Property_Registry_Class.h"

// CONSTRUCTOR IMPLEMENTATION

date::date(int bought, int built) : date_bought(bought), year_built(built) {}

owner::owner(string n, int id, string em) : name(n), tax_id(id), email(em) {}

property::property(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr) : guy(n, id, em), info(bought, built), address(adr), square_feet(sqft), market_price(mpr) {}

residential::residential(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr, int bdc): property(n, id, em, bought, built, adr, sqft, mpr), bedroom_count(bdc) {}

commercial::commercial(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr, string btype) : property(n, id, em, bought, built, adr, sqft, mpr), business_type(btype) {}
//_____________________________________________________________________________________________________________________________________________________________________________________________


// METHOD IMPLEMENTATION


// BASE CLASS METHOD IMPLEMENTATION
float property::get_square_feet() const {
	return square_feet;
}

string property::get_address() const {
	return address;
}

void property::create_property(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr){
	guy = owner(n, id, em);
	info = date(bought, built);
	address = adr;
	square_feet = sqft;
	market_price = mpr;
}

void property::display() const {
	guy.display();
	info.display();
	cout << "Address: " << address << endl;
	cout << "Square Footage : " << square_feet << " sq ft" << endl;
	cout << "Market Price: $" << market_price << endl;
}

// CHILD CLASS METHOD IMPLEMENTATION

void residential::create_property(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr, int bdc) {
	property::create_property(n, id, em, bought, built, adr, sqft, mpr);
	bedroom_count = bdc;
}

void residential::display() const {
	cout << "Residential Property: " << endl;
	property::display();
	cout << "Bedrooms: " << bedroom_count << endl;
}

void commercial::create_property(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr, string btype) {
	property::create_property(n, id, em, bought, built, adr, sqft, mpr);
	business_type = btype;
}

void commercial::display() const {
	cout << "Commercial Property: " << endl;
	property::display();
	cout << "Business Type: " << business_type << endl;
}


//_____________________________________________________________________________________________________________________________________________________________________________________________

