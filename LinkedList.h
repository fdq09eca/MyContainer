#pragma once
#include <iostream>
#include "Node.h"

/// <summary>
/// https://en.cppreference.com/w/cpp/container/list
/// </summary>

class List
{
private:
	Node* m_front = nullptr;
	Node* m_back = nullptr;
public:
	// Constructor
	List() = default;

	// Destructor
	~List();

	// Element access
	const int& front();
	const int& back();

	const Node* begin();	// Returns an iterator (pointer?) to the first element of the list.
	const Node* end();	// Returns an iterator (pointer?) to the element following the last element of the list.

	// Capacity
	bool empty();		//	checks whether the container is empty
	int  size();		//	returns the number of elements
	int max_size();		//	returns the maximum possible number of elements

	// Modifiers
	void push_front(const int& value);	// adds an element to the front
	void push_back(const int& value);	// adds an element to the end
	void pop_front();	// removes the first element
	void pop_back();	// removes the last element

	void insert(Node* pos, const int& value);	// inserts elements	

	void emplace();								// constructs element inplace
	void emplace_front();						// constructs an element inplace at the beginning
	void emplace_back();						// constructs an element inplace at the end

	void clear();			// clears the contents
	void erase();			// erases elements
	void resize();			//	changes the number of elements stored
	void swap(List&);	// swaps the contents

	// Operations
	void sort();  // sorts the elements
	void reverse(); // 	reverses the order of the elements
	void merge(); // merges two sorted lists
	void remove(const int& value); // Removes all elements that are equal to value.
	void remove_if(); // Removes all elements for which predicate p returns true.
	void splice(Node* pos, List& other); //Transfers elements from one list to another.
	void unique(); // Removes all consecutive duplicate elements from the container.

	// Debug
	void print(); // orderly print out all nodes in the container
};


