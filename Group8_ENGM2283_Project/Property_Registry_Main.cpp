#include "Property_Controller.h"
#include "Property_Registry_Class.h"
#include "Helper_Functions.h"

/**********************************************************************************************************************
Property Registry Main:

- Initializes the property database and presents an interactive menu - driven interface.
- Handles user input to 'a' - add, 'r' - retrieve, 's' - sort, 'd' - delete, and manage property records until the user chooses to quit.
**********************************************************************************************************************/
int main(void) {
	
	char choice;

	property_controller<property*> list;
	// Display the main menu once at program startup
	display_menu();

	// Main event loop — continues processing user input until 'Q' is entered
	while (1) {
		cout << endl;
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

		/*****************************************************************************************************
		Selection 'a' add:
		Prompts user to enter information about the property they are adding.

		Asks user to select 'c' commercial or 'r' residential for the type of building and saves the property.
		******************************************************************************************************/

		else if (choice == 'a') {
			while (true) {
				string name, email, address, business;
				int taxid, bought, built, bedc;
				float sqrfeet, marketv;
				cout << "Enter the type of property (commercial = c, residential = r) (x to quit): ";
				cin >> choice;
				choice = (char)tolower(choice);
				cout << endl;
				if (choice == 'x') break;

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
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					getline(cin, business);
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
		/*****************************************************************************************************************************
		Selection 'r' retrieve:

		Promts user to enter 'a' - for adress based retrieve, 'n' - for name of the owner based retrieve, 'i' - for tax id based retrieve.
		Based on the input retrieve function is called to retrieve the data.

		*Note: the entered adress/name/taxid must be exact same as it was saved.
		******************************************************************************************************************************/
		
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

		/*****************************************************************************************************************************
		Selection 's' sort:
		
		Promts user to enter 'p' - for price based search, 's' - for square feet based search
		Sorts and displays all property records by market price or square footage.		
		******************************************************************************************************************************/
		else if (choice == 's') {
			cout << "Sort by market price (P) or square feet (S), enter X to return to main program: ";
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

		/*****************************************************************************************************************************
		Selection 'd' delete:

		Removes a property record from the database based on user input.
        User can coose to delete by 'a' - address, 'n' - owner name, 'i' - tax id, or 'e' - email address.
		******************************************************************************************************************************/
		else if (choice == 'd') {
			while (true) {

				cout << "Delete: address (A), owner name (N), tax id (I), or email (E)";
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
		/**************************************************************************
		Selection 'n' count:

		Displays the total number of property records currently in the database.
		**************************************************************************/
		else if (choice == 'n') {
			cout << "Database contains " << list.count() << " properties.";
		}

		/******************************************************************************************
		Selection 'e' empty:

		Checks if database is empty and reports whether the database holds any property records.		
		******************************************************************************************/
		else if (choice == 'e') {
			if (list.empty()) {

				cout << "Database is empty." << endl;
			}
			else {
				cout << "Database contains " << list.count() << " property records." << endl;
			}
		}
		/******************************************************************************************
		Selection 'c' clear:

		Removes all property records from the database and frees allocated memory.
		******************************************************************************************/
		else if (choice == 'c') {
			list.clear();

			if (list.empty()) {
				cout << "Database succesfully cleared. Memory has been freed." << endl;
			}
		}
		/******************************************************************************************
		Selection 'c' clear:

		Outputs all property records currently stored in the database.
		******************************************************************************************/
		else if (choice == 'z') {
			list.print();
		}
	}
	return 0;
}