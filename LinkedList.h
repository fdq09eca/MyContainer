#pragma once
#include <iostream>
#include "Node.h"

class DoublyLinkedList
{
private:
	Node* m_front = nullptr;
	Node* m_back = nullptr;
	int m_size = 0;

	
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
	Node* push_back(Node* node); // inserts before front node;
	Node* pop_front();	// removes the first element
	Node* pop_back();	// removes the last element
	
	// Operations
	Node* find(int& value);                      // find 1st node with same value 
	void swap(DoublyLinkedList& another_list);	 // swaps the contents
	void sort();	       				         // sorts the elements
	void merge(DoublyLinkedList& another_list);  // merges two sorted lists
	void reverse();                              // reverses the order of the elements
	
	// Debug
	void print(); // orderly print out all nodes in the container
};