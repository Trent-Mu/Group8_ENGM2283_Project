#include "Property_Registry_Class.h"
#include "Property_Controller.h"

// CONSTRUCTOR IMPLEMENTATION

date::date(int bought, int built) : date_bought(bought), year_built(built) {}

owner::owner(string n, int id, string em) : name(n), tax_id(id), email(em) {}

property::property(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr) : guy(n, id, em), info(bought, built), address(adr), square_feet(sqft), market_price(mpr) {}

residental::residental(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr, int bdc): property(n, id, em, bought, built, adr, sqft, mpr), bedroom_count(bdc) {}

commercial::commercial(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr, string btype) : property(n, id, em, bought, built, adr, sqft, mpr), business_type(btype) {}
//_____________________________________________________________________________________________________________________________________________________________________________________________


// METHOD IMPLEMENTATION

float property::get_square_feet() const {
	return square_feet;
}

string property::get_address() const {
	return address;
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