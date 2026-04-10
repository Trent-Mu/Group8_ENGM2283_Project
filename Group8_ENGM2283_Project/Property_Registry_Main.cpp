#include "Property_Controller.h"
#include "Property_Registry_Class.h"
#include "Helper_Functions.h"

int main(void) {

	char choice;

	property_controller<property*> list;

	display_menu();
	//beginning of main menu loop, only ending when user commands it
	while (1) {
		cout << endl;
		cout << "Input (Q to quit): ";
		
		cin >> choice;
		choice = (char)tolower(choice);
		cout << endl;
		//quit main menu
		if (choice == 'q') {
			cout << "Exited Successfully";
			break;
		}
		//print main menu
		else if (choice == 'p') {
			display_menu();
		}
		//add properties to database
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
		//retrieve property by search condition, then print said property to screen
		else if (choice == 'r') {
			while (true) {
				if (list.empty()) {
					cout << "Database is empty" << endl << "returning to main menu: " << endl;
					display_menu();
					break;
				}
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
		//sort database by condition
		else if (choice == 's') {
			if (list.empty()) {
				cout << "Database is empty" << endl << "returning to main menu:" << endl;
				display_menu();
				continue;

			}
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
		//delete property by search, searching is done by condition
		else if (choice == 'd') {
			while (true) {
				if (list.empty()) {
					cout << "Database is empty" << endl << "returning to main menu: " << endl;
					display_menu();
					break;
				}
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
		//return number of properties in the database
		else if (choice == 'n') {
			if (list.empty()) {
				cout << "Database is empty" << endl << "returning to main menu: " << endl;
				display_menu();
				continue;
			}
			cout << "Database contains " << list.count() << " properties.";
		}
		//check if the database is empty
		else if (choice == 'e') {
			if (list.empty()) {
				cout << "Database is empty." << endl << "returning to main menu: " << endl;
				display_menu();
			}
			else {
				cout << "Database is not empty" << endl << "returning to main menu" << endl;
				display_menu();
			}
			
		}
		//clear the entire database
		else if (choice == 'c') {
			if (list.empty()) {
				cout << "Database already empty" << endl << "returning to main menu: " << endl;
				display_menu;
				continue;
			}
			list.clear();

			if (list.empty()) {
				cout << "Database succesfully cleared. Memory has been freed." << endl;
			}
		}
		//print the entire database
		else if (choice == 'z') {
			if (list.empty()) {
				cout << "Database is empty" << endl << "returning to main menu: " << endl;
				display_menu();
				continue;
			}
			list.print();
		}
	}
	return 0;
}

