#include "Property_Controller.h"
#include "Property_Registry_Class.h"
#include "Property_Registry_Implementation.cpp"

int main(void) {


	char choice;

	property_controller<property*> list;

	cout << "Property Registry Database:" << endl;
	cout << "Enter A to add new property" << endl;//easy
	cout << "Enter R to retrieve property by: " << endl;// im curious about how to search through, what is the search condition?
	cout << "Enter S to sort properties by: " << endl; //we just need to choose a sort condition
	cout << "Enter D to delete property" << endl; //we can choose to delete a certain property, delete first or delete last -- depends on search condition, or not who knows 
	cout << "Enter N to check number of properties" << endl; //already done
	cout << "Enter E to check if database empty" << endl; // already done
	cout << "Enter C to clear database" << endl; // already done

	// to test the classes as asked for class implementation deadline
	/*
	property_controller<property*> list;

	residential r1("Jane Doe", 123456789, "janedoe@gmail.com", 2015, 2000, " 1035 Spring Garden", 2000.5, 3000000.00, 3);
	commercial c1("Dalhousie University", 254681973, "dalhousiefacilities@dal.ca", 2024, 2015, "1548 Oxford St", 5430, 5325000.00, "public university");

	list.store(&r1);
	list.store(&c1);

	cout << "Property inventory test" << endl;
	list.print();		// printing the whole database
	*/
	////////////// end of asked material for class implementation testing

	
	// WHOMEVER IS WORKING ON THIS ONCE YOU ARE DONE THE LOGIC MAKE SURE THE CONSOLE PRINTING LOOKS NICE, ADDITIONALLY DEFINE A LINE BREAK ___________________ SOMEWHERE AND DEFINE A FUNCTION THAT PRINTS THE OPTIONS THAT THE USER HAS, ADDITIONALLY MAKE A NEW OPTION IN THE OPTIONS THAT HAS CHOICE P AND LETS THE USER DEICIDE WHEN TO REPINT THE OPTIONS SECTION!!!!!!!!!!!!
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
		//for this i just want someone to make it look nice in the console, AND make sure user can input address with spaces between the name of the address the number of the address and the location like str or blvd or crt yk
		else if (choice == 'a') {
			while (true){
				string name, email, address, business;
				int taxid, bought, built, bedc;
				float sqrfeet, marketv;
				cout << "Enter the type of property (commercial = c, residential = r) (x to quit): ";
				cin >> choice;
				cout << endl;
				if (choice == 'x' || choice == 'X') break;

				cout << "Input the information for the  property you are trying to add in the following order:" << endl;
				cout << "Name of owner, taxID, email, year bought, year built, adress, square feet, market value" << endl;
				cin >> name >> taxid >> email >> bought >> built >> address >> sqrfeet >> marketv;
				cout << endl;


				if (choice == 'c') {
					cout << "Enter business type: ";
					cin >> business;
					commercial c(name, taxid, email, bought, built, address, sqrfeet, marketv, business);
					list.store(&c);
					cout << endl;
				}
				if (choice == 'r') {
					cout << "Enter the number of bedrooms: ";
					cin >> bedc;
					residential r(name, taxid, email, bought, built, address, sqrfeet, marketv, bedc);
					list.store(&r);
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
					string address;
					getline(cin, address);
					Retrieve(list, address, choice);

				}else if (choice == 'n') {
					cout << "Enter name to search for: ";
					string name;
					getline(cin, name);
					Retrieve(list, name, choice);

				}else if (choice == 'i') {
					cout << "Enter owner id to search by: ";
					int id;
					cin >> id;
					Retrieve(list, id, choice);
				}else if (choice == 'e') {
					cout << "Enter email to search by:";
					string email;
					getline(cin, email);
					Retrieve(list, email, choice);

				}else if (choice == 'x') break;
					
				else {
					cout << "Invalid choice";
				}
			}
		}
		//prompt user to search by m - market price, or s - square feet, then call sort functions
		else if (choice == 's') {
			cout << "Search by market price (P) or square feet (S), enter X to return to main program: ";
			cin >> choice;
			choice = (char)tolower(choice);
			if (choice == 'p') {
				sort(list, choice);
			}
			else if (choice == 's') {


		}
		//for this i want someone to prompt user for what they are deleting, honetly just do the same for search but replace stuff with delete...
		else if (choice == 'd') {
			while (true) {
				
				
				
				if (choice == 'x') break;




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