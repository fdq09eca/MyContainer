#pragma once

/// <summary>
/// Singly Linked List Node, 
/// reference: https://en.cppreference.com/w/cpp/container/forward_list
/// </summary>

class Node
{
public:
	int val = 0;
	Node* prev = nullptr;
	Node* next = nullptr;
	
	Node() = default;
	Node(const int& v) { val = v; };
	~Node();
	
};

