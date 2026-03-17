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


	

	while (1) {

		cout << "Input (X to quit): ";

		cin >> choice;

		if (choice == 'X') {
			cout << "Exited Successfully";
			break;
		}
		else if (choice == 'A') {

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