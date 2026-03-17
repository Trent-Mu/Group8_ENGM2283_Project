#ifndef PROPERTY_CONTROLLER_H
#define PROPERTY_CONTROLLER_H

#include "Property_Registry_Class.h"


template <typename T>
class property_controller { //linked list
private: 
	struct node {
		node* previous;
		node* next;
		T data;

		node(const T& value);
	};
	node* head;
public:
	
	property_controller() : head(nullptr) {} //linked list constructor
	property_controller(const property_controller& other); // linked list copy constructor
	~property_controller(); //linked list destructor
	property_controller<T>& operator=(const property_controller& other);
	void store(const T& value); //insert to front of linked list
	void append(const T& value); //insert to back of linked list
	template <typename search>
	const T& Retrieve(search data) const; // return object, searching for adress
	template <typename Compare>
	void sort(Compare comp); // sort...
	template <typename del>
	void Delete(del key);// 
	int count() const; //number of nodese
	bool empty() const;// bool for empty check
	void clear(); //clear the linked list



};
#endif