#include "Property_Controller.h"
#include "Property_Registry_Class.h"
#include "Helper_Functions.h"

int main(void) {


	char choice;

	property_controller<property*> list;

	display_menu();
	// WHOMEVER IS WORKING ON THIS ONCE YOU ARE DONE THE LOGIC MAKE SURE THE CONSOLE PRINTING LOOKS NICE, ADDITIONALLY DEFINE A LINE BREAK ___________________ SOMEWHERE AND DEFINE A FUNCTION THAT PRINTS THE OPTIONS THAT THE USER HAS, ADDITIONALLY MAKE A NEW OPTION IN THE OPTIONS THAT HAS CHOICE P AND LETS THE USER DEICIDE WHEN TO REPINT THE OPTIONS SECTION!!!!!!!!!!!!
	while (1) {
		cout << endl;
		cout << "Enter P to print selection menu:" << endl;
		cout << "Input (Q to quit): ";
		
		cin >> choice;
		choice = (char)tolower(choice);
		cout << endl;

		if (choice == 'q') {
			cout << "Exited Successfully";
			break;
		}
		else if (choice == 'p') {
			display_menu();
		}
		//for this i just want someone to make it look nice in the console, AND make sure user can input address with spaces between the name of the address the number of the address and the location like str or blvd or crt yk
		else if (choice == 'a') {
			while (true) {
				string name, email, address, business;
				int taxid, bought, built, bedc;
				float sqrfeet, marketv;
				cout << "Enter the type of property (commercial = c, residential = r) (x to quit): ";
				cin >> choice;
				cout << endl;
				if (choice == 'x' || choice == 'X') break;

				cout << "Enter name: "; cin >> name;
				cout << "Enter tax ID: "; cin >> taxid;
				cout << "Enter email: "; cin >> email;
				cout << "Enter year bought: "; cin >> bought;
				cout << "Enter year built: "; cin >> built;
				cout << "Enter address: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, address);
				cout << "Enter square feet: "; cin >> sqrfeet;
				cout << "Enter market value: "; cin >> marketv;



				if (choice == 'c') {
					cout << "Enter business type: ";
					cin >> business;
					commercial* c = new commercial(name, taxid, email, bought, built, address, sqrfeet, marketv, business);
					list.store(c);
					cout << endl;
				}
				if (choice == 'r') {
					cout << "Enter the number of bedrooms: ";
					cin >> bedc;
					residential* r = new residential(name, taxid, email, bought, built, address, sqrfeet, marketv, bedc);
					list.store(r);
					cout << endl;
				}
			}
		}
		//for this i want someone to prompt user for what they are searching for 'a' for address 'n' for owner name 'i' for owner id 'e' for email
		//then prompt based on a n i e what thing they are searching for, for exmaple if they put in a, then prompt them for the exact address
		// then call Retrieeve function
		else if (choice == 'r') {
			while (true) {
				cout << "Retreieve property by: address (a), name (n), owner id (i), email (e)" << endl << "x to quit" << endl;
				cin >> choice;
				choice = (char)tolower(choice);
				if (choice == 'a') {
					cout << "Enter address to search for: ";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					string address;
					getline(cin, address);
					Retrieve(list, address, choice);

				}
				else if (choice == 'n') {
					cout << "Enter name to search for: ";
					string name;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					getline(cin, name);
					Retrieve(list, name, choice);

				}
				else if (choice == 'i') {
					cout << "Enter owner id to search by: ";
					int id;
					cin >> id;
					Retrieve(list, to_string(id), choice);
				}
				else if (choice == 'e') {
					cout << "Enter email to search by:";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					string email;
					getline(cin, email);
					Retrieve(list, email, choice);

				}
				else if (choice == 'x') break;

			}
		}
		//prompt user to search by m - market price, or s - square feet, then call sort functions
		else if (choice == 's') {
			cout << "Search by market price (P) or square feet (S), enter X to return to main program: ";
			cin >> choice;
			choice = (char)tolower(choice);
			if (choice == 'p') {
				Sort(list, choice);
			}
			else if (choice == 's') {
				Sort(list, choice);
			}
			else if (choice == 'x') {
				continue;
			}

		}
		//for this i want someone to prompt user for what they are deleting, honetly just do the same for search but replace stuff with delete...
		else if (choice == 'd') {
			while (true) {

				cout << "Delete: address (A), owner name (N) or email (E)";
				cin >> choice;

				choice = (char)tolower(choice);
				string del;
				if (choice == 'a') {
					cout << "Which address would you like to delete?";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					getline(cin, del);
					Delete_property(list, del, choice);
				}
				else if (choice == 'n') {
					cout << "Which owner name would you like to delete?";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					getline(cin, del);
					Delete_property(list, del, choice);
				}
				else if (choice == 'i') {
					cout << "Which owner ID would you like to delete?";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					getline(cin, del);
					Delete_property(list, del, choice);
				}
				else if (choice == 'e') {
					cout << "Which email would you like to delete?";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					getline(cin, del);
					Delete_property(list, del, choice);
				}
				else if (choice == 'x') break;



			}
		}

		//count function, pretty clear what to do
		else if (choice == 'n') {
			cout << "Database contains " << list.count() << " properties.";
		}
		//empty function, just checks if the database is empty, pretty clear what to do
		else if (choice == 'e') {
			if (list.empty()) {

				cout << "Database is empty." << endl;
			}
			else {
				cout << "Database contains " << list.count() << "property records." << endl;
			}
		}
		//clears the database, pretty clear what to do
		else if (choice == 'c') {
			list.clear();

			if (list.empty()) {
				cout << "Database succesfully cleared. Memory has been freed." << endl;
			}
		}
	}
	return 0;
}

// once we are done everything we are gonna remove all the weird comments and comment everything "professionally"