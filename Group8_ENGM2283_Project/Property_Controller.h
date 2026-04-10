#ifndef PROPERTY_CONTROLLER_H
#define PROPERTY_CONTROLLER_H

#include "Property_Registry_Class.h"

/***************************************************************************
Property controller template:
- node with pointers to previous and next, and a variable of type data
- pointer for head node
has functions for:
- linked list constructor, copy constructor, deconstructor
- has functions for assignment operator, insert to front and back of linked list, address search, sort
- has functions for deleting nodes, counting the number of nodes, checking if empty, clear linked list and print
***************************************************************************/
template <class T>
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
	
	property_controller() : head(nullptr) {} 
	property_controller(const property_controller& other); 
	~property_controller(); 
	property_controller<T>& operator=(const property_controller& other);
	void store(const T& value); 
	void append(const T& value); 
	template <typename search>
	const T& retrieve(search data) const; 
	template <typename Compare>
	void sort(Compare comp);
	template <typename del>
	void Delete(del key);
	int count() const; 
	bool empty() const;
	void clear(); 
	void print() const;

};



/***************************************************************
Node Constructor
initializes the values of node with a value of type T and null poinyters for previous and next.
***************************************************************/

template <class T>
property_controller<T>::node::node(const T& value) {
	data = value;
	next = nullptr;
	previous = nullptr;
}
//___________________________________________________________________________________________________________________________________________________________________________




/***************************************************************
Linked list copy constructor
Makes a copy of the whole linked list
***************************************************************/

template <class T>
property_controller<T>::property_controller(const property_controller& other) {

	head = nullptr;

	node* current = other.head;

	while (current != nullptr) {
		append(current->data);
		current = current->next;
	}
}
//__________________________________________________________________________________________________________________________________________________________________________



/***************************************************************
Linked list deconstructor
Deletes the whole linked list.
***************************************************************/


template <class T>
property_controller<T>::~property_controller() {
	clear();
}
//____________________________________________________________________________________________________________________________________________________________________________


/****************************************************************
Linked list copy assignment operator
Function assigns the value of the right hand side value to the left hand side variable (lhs = rhs) and returns the pointer
****************************************************************/


template <class T>
property_controller<T>& property_controller<T>::operator=(const property_controller& other) {
	if (this == &other) return *this;

	clear();

	node* current = other.head;

	while (current != nullptr) {
		append(current->data);
		current = current->next;
	}

	return *this;
}
//__________________________________________________________________________________________________________________________


/***************************************************************
Linked list insertion
Inserts the new node at the start of the list, making it the head.
***************************************************************/

template <class T>
void property_controller<T>::store(const T& value) {

	node* newNode = new node(value);
	//empty list case
	if (empty()) {
		head = newNode;
		return;
	}

	newNode->next = head;
	head->previous = newNode;
	head = newNode;
}
//___________________________________________________________________________________________________________________________________________________________________________



/*******************************************************************
Linked list append
Adds the new node at the end of the list
*******************************************************************/


template <class T>
void property_controller<T>::append(const T& value) {

	node* newNode = new node(value);

	if (empty()) {
		head = newNode;
		return;
	}

	node* current = head;

	while (current->next != nullptr) {
		current = current->next;
	}

	current->next = newNode;
	newNode->previous = current;
}
//____________________________________________________________________________________________________________________________________________________________________________




/*********************************************************************
Linked list search
If the database is empty, the user is notified trough an output message.
If the database isn't empty the it's searched for the specific type of data that the user has input. The function goes trough the database until it finds the
value that the user inputs and prints the property on the screen.
If the database doesn't have the value the user inputs an error message is printed.
*********************************************************************/


template <class T>
template <typename search>
const T& property_controller<T>::retrieve(search key) const { //we can have filters if we choose
	if (empty()) {
		throw invalid_argument("Database is empty"); //remember try and catch with invalid_argument object as the catch argument passed by reference
	}

	node* current = head;

	while (current != nullptr) {
		if (key(current->data)) { //lambda bool function 
			return current->data;
		}
		current = current->next;
	}
	throw runtime_error("Data not found"); //remember try and catch with invalid_arguement object as the catch arguement pass by reference
}
//_____________________________________________________________________________________________________________________________________________________________________________



/*************************************************************************
Linked list sort
Sorts values of type T from smasllest to larggest by inserton sort (starts from
second value and checks if the one before it is bigger, if yes the value moves
until the value before it is smaller)
**************************************************************************/


template <class T>
template <typename Compare> // if template for the list is T then if we are sorting, objects we need a difference template for the sort parameter
void property_controller<T>::sort(Compare comp) {

	if (empty() || head->next == nullptr) return;

	node* current = head->next;


	while (current != nullptr) {

		T value = current->data; //list template value = current-> data
		node* temp = current->previous;

		while (temp != nullptr && comp(value, temp->data)) {  //lambda function required, 
			temp->next->data = temp->data;
			temp = temp->previous;

		}
		if (temp == nullptr) {
			head->data = value;
		}
		else {
			temp->next->data = value;
		}

		current = current->next;
	}
}
//________________________________________________________________________________________________________________________________________________________________________________



/************************************************************
Linked list search delete
Searches for the node with value type T, when it is found the note is deleted.
*************************************************************/


template <class T>
template <typename del>
void property_controller<T>::Delete(del key) {
	if (empty()) return;

	node* current = head;

	while (current != nullptr) {


		if (key(current->data)) {

			node* nextNode = current->next;

			if (current->previous != nullptr) {
				current->previous->next = current->next;
			}

			else {
				head = current->next;
			}
			if (current->next != nullptr) {
				current->next->previous = current->previous;
			}
			delete current->data;
			delete current;
			current = nextNode;
		}
		else {
			current = current->next;
		}
	}

}
//_____________________________________________________________________________________________________________________________________________________________________________



/***************************************************
Linked list count
Starting at the head, the while loop keeps going trough nodes until the end of the database, incresing the value of count by 1 every time.
The function returns count as the number of nodes in the database.
***************************************************/


template <class T>
int property_controller<T>::count() const {
	if (empty()) return 0;

	node* current = head;
	int count = 0;

	while (current != nullptr) {
		count++;
		current = current->next;
	}

	return count;
}
//______________________________________________________________________________________________________________________________________________________________________________



/**********************************************************
Linked list empty check
This functino checks if the database is empty.
If the database is empty the functino returns true.
***********************************************************/


template <class T>
bool property_controller<T>::empty() const {
	return(head == nullptr);
}
//______________________________________________________________________________________________________________________________________________________________________________



/**********************************************************
Linked list data clear
This function clears the whole database, deleting it node by node.
**********************************************************/


template <class T>
void property_controller<T>::clear() {
	if (empty()) return;

	node* current = head;

	while (current != nullptr) {
		node* temp = current;
		current = current->next;
		delete temp->data;
		delete temp;
	}

	head = nullptr;
}
//____________________________________________________________________________________________________________________________________________________________________________________________

/*********************************************************************
Linked list print
This function prints the whole database node by node.
**********************************************************************/

template <class T>
void property_controller<T>::print() const {
	if (empty()) return;

	node* current = head;

	while (current != nullptr) {

		current->data->display();
		cout << endl;
		current = current->next;
	}
}
#endif