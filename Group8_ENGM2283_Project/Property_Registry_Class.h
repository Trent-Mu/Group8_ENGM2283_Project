#ifndef PROPERTY_REGISTRY_CLASS_H
#define PROPERTY_REGISTRY_CLASS_H

#include <iostream>

using namespace std;

/////////////////Composition Classes//////////////////////
//we need methods and boris said to remove some attributes
class date {
private:
	int date_bought;
	int year_built;
public:
	date(int bought = 0, int built = 0);
};

class owner {
private:
	string name;
	int tax_id;
	string email;
public:
	owner(string n = " ", int id = 0, string em = " ");
};

//////////////////////////////////////////////////////////





///////////////////// Base Class /////////////////////////

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
	float get_square_feet() const;
	string get_address() const;
	virtual void display() const;
};

/////////////////////////////////////////////////////////





/////////////////////// Child Classes ///////////////////

class residental : public property {
private:
	int bedroom_count;
public:
	residental(string n = " ", int id = 0, string em = " ", int bought = 0, int built = 0, string adr = " ", float sqft = 0, float mpr = 0, int bdc = 0);
	void display();
};
class commercial : public property {
private:
	string business_type;
public:
	commercial(string n = " ", int id = 0, string em = " ", int bought = 0, int built = 0, string adr = " ", float sqft = 0, float mpr = 0, string btype = " ");
	void display();
};

//////////////////////////////////////////////////////////
#endif


