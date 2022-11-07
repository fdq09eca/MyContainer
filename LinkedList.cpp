#include "LinkedList.h"

LinkedList::LinkedList(const int& v_)
{
	head = new Node(v_);
	std::cout << "LinkedList created. head node value:" << head->val << std::endl;
}

LinkedList::~LinkedList()
{
	delete head;
}

void LinkedList::add_back(const int& v_)
{
	if (!head) return;
	Node* p = head;
	
	while (p) {
		if (!p->next) break;
		p = p->next;
	}
	
	p->next = new Node(v_);
}

void LinkedList::print()
{
	Node* p = head;
	std::cout << "LinkedList values: ";
	while (p) {
		std::cout << p->val;
		p = p->next;
		
		if (p) {
			std::cout << ", ";
		}
		else {
			std::cout << std::endl;
		}

	}
}
