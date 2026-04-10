#ifndef HELPER_FUNCTION_H
#define HELPER_FUNCTION_H

#include "Property_Controller.h"
#include "Property_Registry_Class.h"


const string LINE_BREAK = "____________________________________________";

void display_menu() {
	cout << "\n" << LINE_BREAK << endl;
	cout << "         Property Registry Database:" << endl;
	cout << LINE_BREAK << endl;
	cout << "Enter A to add new property" << endl;
	cout << "Enter R to retrieve property by: " << endl;
	cout << "Enter S to sort properties by: " << endl; 
	cout << "Enter D to delete property" << endl; 
	cout << "Enter N to check number of properties" << endl; 
	cout << "Enter E to check if database empty" << endl; 
	cout << "Enter C to clear database" << endl; 
	cout << "Enter P to print the selection options" << endl;
	cout << "Enter Z to print full database" << endl;
}


/*
Overview: Search function that allows user to search by query
Parameters: templated list, search query, search type
Description: pass a lambda function as a template search condition into the list.retreieve that evaluates if the search query is equal to a properties needed attribute, then it displays the property, each function call is decided by user searh type, known as choice
Return Value: void
*/
template <typename T>
void Retrieve(const property_controller<T>& list, string search, char choice) { 

	try {
		if (choice == 'a') {
			(list.retrieve([search](const T& a) {
				return search == a->get_address();
				}))->display();
		}
		
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
			throw invalid_argument("Wrong character! (Try n - name search, i - tax id search or e - email search");
		}
	}
	catch (const exception& e) {

		cout << "Search Error: " << e.what() << endl;
	}



}
/*
Overview: Sorts database based on condition
Parameters: templated list, choice ( search condition)
Description: pass a lambda function as a template comparator into the list.sort method, using if statements to decide which comparator to run for the sorting algorithm based on user choice
Return Value: void
*/
template <typename T>
void Sort(property_controller<T>& list, char choice) { 
	try {
		if (choice == 'p') {
			list.sort([](const T& a, const T& b) {
				return a->get_market_price() < b->get_market_price();
				});
			cout << "Sorted by Market Price." << endl;
		}
		else if (choice == 's') {
			list.sort([](const T& a, const T& b) {
				return a->get_square_feet() < b->get_square_feet();
				});
			cout << "Sorted by Square Footage." << endl;
		}
		else {
			throw invalid_argument("Wrong character! (p - price sort, s - square footage sort)");
		}

	}
	catch (const exception& e) {
		cout << "Sort Error: " << e.what() << endl;
	}

}
/*
Overview: Deletes property by user search query
Parameters: templated list, search query, search type
Description: pass a lambda function as a template search condition into the list.delete method, and pass search query into the lambda scope, evaluate if the search query = the property attribute, which is defined by user choice
Return Value: void
*/
template <typename T>
void Delete_property(property_controller<T>& list, string del, char choice) { // delete element by address, owner name, owner id, or email

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
			throw invalid_argument("Wrong character!(Try n - name search, i - tax id search or e - email search");
		}
	}
	catch (const exception& e) {
		cout << "Remove Error: " << e.what() << endl;
	}														
}				


static bool is_char(char c) {
	return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

static bool is_char_string(string str) {

	if (str.empty()) return false;
	 for (int i = 0; i < str.length(); i++) {
		 if (!is_char(str[i]) && str[i] != ' ') return false;
	 }

	 return true;
}
bool is_email(string email) {
	if (email.empty()) return false;
	if (!is_char(email[0])) return false;
	int At = -1;
	int dot = -1;


	for (int i = 0; i < email.length(); i++) {
		if (email[i] == '@') {
			At = i;
		}
		else if (email[i] == '.') {
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








#endif 
