#pragma once
#include <iostream>
#include "Node.h"



class LinkedList
{
public:
	LinkedList() = default;
	LinkedList(Node* h) { head = h; };
	LinkedList(const int& v_);
	~LinkedList();
	
	void add_back(const int&);  // add node after the last node
	void add_front(const int&); // add node before head
	
	const Node* find(const int&); // return the the first node that match with the parameter value.
	
	void remove(const int&); // remove all nodes that match with the parameter value
	void reverse(); // reverse the linked list
	
	void insert_before(Node*, const int&); // add node before the first node that matches with the value
	void insert_after(Node*, const int&); //  add node after the first node that matches with the value
	
	
	const Node* pop(const int&); // remove and return the first node that match with the parameter value.
	const Node* pop_front(); // remove and return the head node.
	const Node* pop_back(); // remove and return the last node
	
	const int get_length();
	void print();

	Node* pop_head();


private:
	Node* head = nullptr;
};


