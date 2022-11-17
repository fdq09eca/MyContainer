#pragma once
#include <iostream>
#include "Node.h"

class DoublyLinkedList
{
private:
	Node* m_front = nullptr;
	Node* m_back = nullptr;
	int m_size = 0;
	DoublyLinkedList& operator=(const DoublyLinkedList& other) = delete; //non-copyable
	DoublyLinkedList(const DoublyLinkedList& other) = delete; //non-copyable
	
public:
	// Constructor
	DoublyLinkedList() = default;

	// Destructor
	~DoublyLinkedList();


	// Element access
	Node* front_ptr();
	Node* back_ptr();

	// Capacity
	int size();		             //	returns the number of elements
	
	// Modifiers
	void clear();			    // clears the contents == reset();
	void insert(Node* pos, Node* node);	    // inserts node before pos
	void remove(Node* node);        // removes any node
	
	Node* push_front(Node* node); // inserts before front node;
	Node* push_front(const int& value); // inserts before front node;
	
	Node* push_back(Node* node); // inserts after back node;
	Node* push_back(const int& value); // inserts after back node;
	
	Node* pop_front();	// removes and returns the first element
	Node* pop_back();	// removes and returns the last element
	
	// Operations
	Node* find(const int & value);      // find 1st node with same value 
	Node* find_min();                   // returns min value 
	Node* find_max();                   // returns max value 
	DoublyLinkedList& sort(const bool& asc = true);	 // sorts the elements
	void deep_copy(const DoublyLinkedList& another_list); 
	
	void swap(DoublyLinkedList& another_list);	 // swaps the contents
	void merge(DoublyLinkedList& another_list);  // merges two sorted lists
	void reverse();                              // reverses the order of the elements
	
	// Debug
	void print(); // orderly print out all nodes in the container
};