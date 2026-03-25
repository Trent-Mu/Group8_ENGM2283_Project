#ifndef PROPERTY_CONTROLLER_H
#define PROPERTY_CONTROLLER_H

#include "Property_Registry_Class.h"


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
	
	property_controller() : head(nullptr) {} //linked list constructor
	property_controller(const property_controller& other); // linked list copy constructor
	~property_controller(); //linked list destructor
	property_controller<T>& operator=(const property_controller& other);
	void store(const T& value); //insert to front of linked list
	void append(const T& value); //insert to back of linked list
	template <typename search>
	const T& retrieve(search data) const; // return object, searching for adress
	template <typename Compare>
	void sort(Compare comp); // sort...
	template <typename del>
	void Delete(del key);// 
	int count() const; //number of nodese
	bool empty() const;// bool for empty check
	void clear(); //clear the linked list
	void print() const;


};


// NODE CONSTRUCTOR

template <class T>
property_controller<T>::node::node(const T& value) {
	data = value;
	next = nullptr;
	previous = nullptr;
}
//___________________________________________________________________________________________________________________________________________________________________________



// LINKED LIST COPY CONSTRUCTOR

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



// LINKED LIST DESTRUCTOR

template <class T>
property_controller<T>::~property_controller() {
	clear();
}
//____________________________________________________________________________________________________________________________________________________________________________


// LINKED LIST COPY ASSIGNMENT OPERATOR
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


// LINKED LIST INSERTION

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



// LINKED LIST APPEND

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




// LINKED LIST SEARCH

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



// LINKED LIST SORT 

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



// LINKED LIST SEARCH DELETE

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



// LINKED LIST COUNT

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



// LINKED LIST EMPTY CHECK

template <class T>
bool property_controller<T>::empty() const {
	return(head == nullptr);
}
//______________________________________________________________________________________________________________________________________________________________________________



// LINKED LIST DATA CLEAR

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

// LINKED LIST PRINT

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