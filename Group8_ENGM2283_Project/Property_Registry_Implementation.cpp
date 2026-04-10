#include "Property_Registry_Class.h"
#include "Property_Controller.h"

// CONSTRUCTOR IMPLEMENTATION

date::date(int bought, int built) : date_bought(bought), year_built(built) {}

owner::owner(string n, int id, string em) : name(n), tax_id(id), email(em) {}

property::property(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr) : guy(n, id, em), info(bought, built), address(adr), square_feet(sqft), market_price(mpr) {}

residential::residential(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr, int bdc): property(n, id, em, bought, built, adr, sqft, mpr), bedroom_count(bdc) {}

commercial::commercial(string n, int id, string em, int bought, int built, string adr, float sqft, float mpr, string btype) : property(n, id, em, bought, built, adr, sqft, mpr), business_type(btype) {}
//_____________________________________________________________________________________________________________________________________________________________________________________________

// METHOD IMPLEMENTATION FOR COMPOSITION CLASSES date and owner


/****************************************************************
Method implementation for composition class date
This function checks fi a property is new (built after 2020).
If the property is new, the functino returns true.
****************************************************************/

bool date::isNewHouse() const {
	return year_built > 2020;
}

/****************************************************************
Method implementation for composition class date
This function prints the year built and the year bought for the property in question.
It also prints a message to the screen if the house is new.
****************************************************************/

void date::date_display() const {
	cout << "Year built: " << year_built << endl;
	cout << "Year bought: " << date_bought << endl;

	if (isNewHouse()) {
		cout << "New House!";
	}
}

/**************************************************************
Method implementation for composition class owner
Helper function for the isValidEmail function
**************************************************************/

static bool is_char(char c) {
	return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**************************************************************
Method implementation for composition class owner
This function checks if teh email of an owner is valid.
It does so by checking if the email is composed of only letters.
Additionally, the function chechks if the email contains @ and a dot.
It returns true if the email is written in all letters and has '@' and '.' symbols.
**************************************************************/

bool owner::isValidEmail() const {
	if (!is_char(email[0])) return false;
	int At = -1;
	int dot = -1;


	for (int i = 0; i < email.length(); i++) {
		if (email[i] == '@') {
			At = i;
		}
		else if (email[i] == '.'){
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

/**********************************************
Method implementation for composition class owner
This function prints all the owner details to the screen.
Those details include the owner's name, taxID and valid email.
***********************************************/

void owner::owner_display() const {
	cout << "Owner name: " << name << endl;
	cout << "Tax ID: " << tax_id << endl;
	cout << "Email: " << email << endl;
}

/**********************************************
Method implementation for composition class owner
This function returns the owner's name.
***********************************************/

string owner::get_name() const {
	return name;
}

/**********************************************
Method implementation for composition class owner
This function returns the owner's name.
***********************************************/

string owner::get_email() const {
	return email;
}

/**********************************************
Method implementation for composition class owner
This function returns the owner's taxID.
***********************************************/

int owner::get_taxid() const {
	return tax_id;
}




// BASE CLASS METHOD IMPLEMENTATION

/**********************************************
Method implementation for base class property
This function returns the square footage of a property.
***********************************************/

float property::get_square_feet() const {
	return square_feet;
}


/**********************************************
Method implementation for base class property
This function returns the address of the property.
***********************************************/

string property::get_address() const {
	return address;
}

/**********************************************
Method implementation for base class property
This function returns the market value of the property.
***********************************************/

float property::get_market_price() const {
	return market_price;
}

/**********************************************
Method implementation for base class property
This function prints the contents of the class property.
This includes the address, square footage and market price.
***********************************************/

void property::display() const {
	guy.owner_display();
	info.date_display();
	cout << "Address: " << address << endl;
	cout << "Square Footage : " << square_feet << " sq ft" << endl;
	cout << "Market Price: $" << market_price << endl;
}

/**********************************************
Method implementation for base class property
This function returns the owner's name.
***********************************************/

const owner& property::get_owner() const {
	return guy;
}

/**********************************************
Method implementation for base class property
This function returns the date information.
***********************************************/

const date& property::get_date() const {
	return info;
}

// CHILD CLASS METHOD IMPLEMENTATION

/**********************************************
Method implementation for child class residential
This function prints the contents of the class residental.
That includes the number of bedrooms.
***********************************************/

void residential::display() const {
	cout << "Residential Property: " << endl;
	property::display();
	cout << "Bedrooms: " << bedroom_count << endl;
}

/**********************************************
Method implementation for child class commercial
This function prints the contents of the class commercial.
This includes the business type that owns the property.
***********************************************/

void commercial::display() const {
	cout << "Commercial Property: " << endl;
	property::display();
	cout << "Business Type: " << business_type << endl;
}


//_____________________________________________________________________________________________________________________________________________________________________________________________













