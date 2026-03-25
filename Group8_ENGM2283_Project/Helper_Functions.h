#ifndef HELPER_FUNCTION_H
#define HELPER_FUNCTION_H

#include "Property_Controller.h"

template <typename T>
void Retrieve(const property_controller<T>& list, string search, char choice) { //can retrieve by address, owner name, id or email, user will input which choice they want

	try {
		if (choice == 'a') {
			(list.retrieve([search](const T& a) {
				return search == a->get_address();
				}))->display();
		}
		//call retrieve in here with lambda function call, having search in the scope 
		else if (choice == 'n') {
			(list.retrieve([search](const T& a) {
				return search == a->get_owner().get_name();
				}))->display();
		}
		else if (choice == 'i') {
			(list.retrieve([search](const T& a) {
				return search == to_string(a->get_owner().get_taxid());
				}))->display();
		}
		else if (choice == 'e') {
			(list.retrieve([search](const T& a) {
				return search == a->get_owner().get_email();
				}))->display();
		}
		else {
			throw invalid_argument("Wrong charachter! (Try n - name search, i - tax id search or e - email search");
		}
	}
	catch (const exception& e) {

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
void remove(property_controller<T>& list, string del, char choice) { // delete element by address, owner name, owner id, or email

	try {
		if (choice == 'a') {
			list.Delete([del](const T& p) {
				return p->get_address() == del; });
		}
		else if (choice == 'n') {
			list.Delete([del](const T& p) {
				return p->get_owner().get_name() == del; });
		}
		else if (choice == 'i') {
			list.Delete([del](const T& p) {
				return to_string(p->get_owner().get_taxid()) == del; });
		}
		else if (choice == 'e') {
			list.Delete([del](const T& p) {
				return p->get_owner().get_email() == del; });
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





//Honestly after these we 

#endif 
