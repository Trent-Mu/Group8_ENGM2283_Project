#include "Property_Registry_Class.h"
#include "Property_Controller.h"

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












// HELPER FUNCTIONS

template <typename T>
void retrieve(const property_controller<T>& list, auto search, string choice) { //can retrieve by address, owner name, id or email, user will input which choice they want

																//call retrieve in here with lambda function call, having search in the scope 
			
																//lambda function call is ([search]( const property& p) { return search == p.get_(choice)()});
					
																//make sure that the correct getter is used according to choice
												
																//alternatively replace choice with and enum and do switch case statments, thats way cooler 
												

}

template <typename T>
void sort(property_controller<T>, string choice) { //can sort by market price, or by square feet
																		
																//call sort in here with lambda function call as the parameter

																//lambda function call is ([](const property& a, const property& b) { return a.get_(choice)() < b.get_(choice)() });

																//make sure that the correct getter is used according to choice

																//alternatively replace choice with and enum and do switch case statments, thats way cooler 

}

template <typename T>
void remove(property_controller<T>, auto del, string choice) { // delete element by address, owner name, owner id, or email

																//call delete in here with lambda function call as the parameter

}																//lmabda function call is ([del](property& p){ return del==p.get_(choice)()});

																// make sure that the correct getter is used according to choice

																//alternatively replace choice with and enum and do switch case statments, thats way cooler 





//Honestly after these we are mostly done 