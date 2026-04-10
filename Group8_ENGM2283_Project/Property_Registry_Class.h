#ifndef PROPERTY_REGISTRY_CLASS_H
#define PROPERTY_REGISTRY_CLASS_H

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

/////////////////Composition Classes//////////////////////
/*********************************************************
Composition class date
The class date has:
- values that represent the date the property is boght and the date the property is built
- an initialization function, a function that checks if it is
new construction (year 2020 for the saek of the project),
a print function
*********************************************************/


class date {
private:
	int date_bought;
	int year_built;
public:
	date(int bought = 0, int built = 0);
	bool isNewHouse() const;                           // new = built past 2020
	void date_display() const;
};

/********************************************************
Composition class owner
The class owner has;
- values that represent the owner's name, taxID and email
- an initializastion function, a function that checks if the email entered is valid,
a print function, getter functinos for the name, email and taxID
********************************************************/

class owner {
private:
	string name;
	int tax_id;
	string email;
public:
	owner(string n = " ", int id = 0, string em = " ");
	bool isValidEmail() const;
	void owner_display() const;
	string get_name() const;
	string get_email() const;
	int get_taxid() const;
};

//////////////////////////////////////////////////////////





///////////////////// Base Class /////////////////////////

/****************************************************
Base class property
This class has:
- variables that represent the address, sqare footage and market price of the property
- an initialization function,deconstructor, getter functions for square footage and address,
a print function, getter functions for the owner name, date and market price
****************************************************/

class property {
protected:
	string address;
	float square_feet;
	float market_price;
private:
	owner guy;
	date info;
public:
	property(string n = " ", int id = 0, string em = " ", int bought = 0, int built = 0, string adr = " ", float sqft = 0, float mpr = 0);
	virtual ~property() = default;
	float get_square_feet() const;
	string get_address() const;
	virtual void display() const;
	const owner& get_owner() const;
	const date& get_date() const;
	float get_market_price() const;
};

/////////////////////////////////////////////////////////





/////////////////////// Child Classes ///////////////////

/***********************************************************
Child class residential property
This class has:
- a variable that represents the bedroom number of the property
- an initialization function and a print function
***********************************************************/

class residential : public property {
private:
	int bedroom_count;
public:
	residential(string n = " ", int id = 0, string em = " ", int bought = 0, int built = 0, string adr = " ", float sqft = 0, float mpr = 0, int bdc = 0);
	void display() const;
};

/***********************************************************
Child class commercial property
This class has:
- a variable that represents type of business that owns the property
- an initialization function and a print function
***********************************************************/

class commercial : public property {
private:
	string business_type;
public:
	commercial(string n = " ", int id = 0, string em = " ", int bought = 0, int built = 0, string adr = " ", float sqft = 0, float mpr = 0, string btype = " ");
	void display() const;
};

//////////////////////////////////////////////////////////
#endif


