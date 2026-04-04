#ifndef HELPER_FUNCTION_H
#define HELPER_FUNCTION_H

#include "Property_Controller.h"
#include "Property_Registry_Class.h"


const string LINE_BREAK = "____________________________________________";
/*
*****************************************************************************
Display Menu: 
Prints all of the options available for user input when function is called.
*****************************************************************************
*/ 
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
*****************************************************************************
Retrieve Template:
For operation (user choice) 'R'. Retrieves property with any piece of data from class 
User is promted t enter:
'a' - for search by adress
'n' - for search by name
'i' - for search by tax id	

Retrieve is called by lambda function which has search in the scope.
Lambda function call is ([search]( const property& p) { return search == p.get_(choice)()});

throws invalid_argument If an unrecognized choice character is provided.
*****************************************************************************
*/

template <typename T>
void Retrieve(const property_controller<T>& list, string search, char choice) { 

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

	}
}
/*
*****************************************************************************
Sort Template:

 - Sorts the property database by a specified attribute. Can sort by market price, or by square feet
 - Applies the comparison using a lambda function passed to the controller's sort method. 
 - Sorts in inreasing order.

 throws invalid_argument If an unrecognized choice character is provided.
*****************************************************************************
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
			throw invalid_argument("Wrong charachter! (p - price sort, s - square footage sort)");
		}

	}
	catch (const exception& e) {
		cout << "Sort Error: " << e.what() << endl;
	}

}

/*
*****************************************************************************
Delete Template:

Deletes a property record from the database matching a given value.

'a' — match by property address
'n' — match by owner name
'i' — match by owner tax ID
'e' — match by owner email
 
 - Passes a lambda predicate to the controller's
 - Delete method to locate and remove the matching record.

throws invalid_argument If an unrecognized choice character is provided.
*****************************************************************************
*/

template <typename T>
void Delete_property(property_controller<T>& list, string del, char choice) {

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
	}
}
#endif