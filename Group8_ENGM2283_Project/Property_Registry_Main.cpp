#include "Property_Controller.h"

int main(void) {

	char choice;

	cout << "Property Registry Database:" << endl;
	cout << "Enter A to add new property" << endl;//easy
	cout << "Enter R to retrieve property by: " << endl;// im curious about how to search through, what is the search condition?
	cout << "Enter S to sort properties by: " << endl; //we just need to choose a sort condition
	cout << "Enter D to delete property" << endl; //we can choose to delete a certain property, delete first or delete last -- depends on search condition, or not who knows 
	cout << "Enter C to check number of properties" << endl; //already done
	cout << "Enter E to check if database empty" << endl; // already done
	cout << "Enter C to clear database" << endl; // already done

	// to test the classes as asked for class implementation deadline
	property_controller<property*> list;

	residential r1("Jane Doe", 123456789, "janedoe@gmail.com", 2015, 2000, " 1035 Spring Garden", 2000.5, 3000000.00, 3);
	commercial c1("Dalhousie University", 254681973, "dalhousiefacilities@dal.ca", 2024, 2015, "1548 Oxford St", 5430, 5325000.00, "public university");

	list.store(&r1);
	list.store(&c1);

	cout << "Property inventory test" << endl;
	list.print();		// printing the whole database

	////////////// end of asked material for class implementation testing

	

	while (1) {

		cout << "Input (X to quit): ";

		cin >> choice;

		if (choice == 'X') {
			cout << "Exited Successfully";
			break;
		}
		else if (choice == 'A') {
			string tname, temail, tadress, tbusiness;
			int ttaxid, tbought, tbuilt, tbedc;
			float tsqrfeet, tmarketv;
			char tchoice;

			cout << "Input the information for the  property you are trying to add in the following order:" << endl;
			cout << "Name of owner, taxID, email, year bought, year built, adress, square feet, market value" << endl;
			cin >> tname >> ttaxid >> temail >> tbought >> tbuilt >> tadress >> tsqrfeet >> tmarketv;

			cout << "Evter the type of property (commercial = c, residential = r): ";
			cin >> tchoice;

			if (choice == 'c') {
				cout << "Enter busess type: ";
				cin >> tbusiness;
				commercial c(tname, ttaxid, temail, tbought, tbuilt, tadress, tsqrfeet, tmarketv, tbusiness);
				list.store(&c);
			}
			if (choice == 'r') {
				cout << "Enter the number of bedrooms: ";
				cin >> tbedc;
				residential r(tname, ttaxid, temail, tbought, tbuilt, tadress, tsqrfeet, tmarketv, tbedc);
				list.store(&r);
			}

		}
		else if (choice == 'R') {

		}
		else if (choice == 'S') {

		}
		else if (choice == 'D') {

		}
		else if (choice == 'C') {

		}
		else if (choice == 'E') {

		}
		else if (choice == 'C') {

		}

	}


	return 0;
}