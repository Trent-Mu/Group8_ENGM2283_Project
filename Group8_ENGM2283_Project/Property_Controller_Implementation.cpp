#include "Property_Controller.h"

// NODE CONSTRUCTOR

template <typename T>
property_controller<T>::node::node(T value) {
	data = value;
	next = nullptr;
	previous = nullptr;
}
//___________________________________________________________________________________________________________________________________________________________________________



// LINKED LIST COPY CONSTRUCTOR

template <typename T>
property_controller<T>::property_controller(const property_controller& other) {

	head = nullptr;

	node* current = other.head;

	while (current != nullptr) {
		store(current->data);
		current = current->next;
	}
}
//__________________________________________________________________________________________________________________________________________________________________________



// LINKED LIST DESTRUCTOR

template <typename T>
property_controller<T>::~property_controller() {
	clear();
}
//____________________________________________________________________________________________________________________________________________________________________________


// LINKED LIST COPY ASSIGNMENT OPERATOR
template <typename T>
property_controller<T>& property_controller<T>::operator=(const property_controller& other) {
	if (this == &other) return *this;

	clear();

	node* current = other.head;

	while (current != nullptr) {
		store(current->data);
		current = current->next;
	}

	return *this;
}
//__________________________________________________________________________________________________________________________


// LINKED LIST INSERTION

template <typename T>
void property_controller<T>::store(T value) {
	
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

template <typename T>
void property_controller<T>::append(T value) {
	
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

template <typename T>
template <typename search>
const T& property_controller<T>::Retrieve(search key) { //we can have filters if we choose
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
	throw invalid_argument("Data not found"); //remember try and catch with invalid_arguement object as the catch arguement pass by reference
}
//_____________________________________________________________________________________________________________________________________________________________________________



// LINKED LIST SORT 

template <typename T>
template <typename Compare> // if template for the list is T then if we are sorting, objects we need a difference template for the sort parameter
void property_controller<T>::sort(Compare comp) { 

	if (empty() || head->next == nullptr) return;

	node* current = head->next;


	while (current != nullptr) {
		
		T value = current->data; //list template value = current-> data
		node* temp = current->previous;

		while (temp != nullptr && comp(value,temp->data)) {  //lambda function required, 
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

template <typename T>
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

template <typename T>
int property_controller<T>::count() const {
	if (empty()) return 0;

	node* current = head;
	int count = 0;

	while (current!= nullptr) {
		count++;
		current = current->next;
	}

	return count;
}
//______________________________________________________________________________________________________________________________________________________________________________



// LINKED LIST EMPTY CHECK

template <typename T>
bool property_controller<T>::empty() const{
	return(head == nullptr);
}
//______________________________________________________________________________________________________________________________________________________________________________



// LINKED LIST DATA CLEAR

template <typename T>
void property_controller<T>::clear() {
	if (empty()) return;

	node* current = head;

	while (current != nullptr) {
		node* temp = current;
		current = current->next;
		delete temp;
	}

	head = nullptr;
}
//____________________________________________________________________________________________________________________________________________________________________________________________
