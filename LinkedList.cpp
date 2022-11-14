#include "LinkedList.h"
#include <cassert>


void DoublyLinkedList::clear()
{
	Node* h = m_front;
	while (h) {
		Node* n = h->next;
		delete h;
		h = n;
	}
	m_size = 0;
}

void DoublyLinkedList::insert(Node* pos, Node* node)
{
	if (!pos) {
		// special case: insert after m_back;
		m_back->next = node;
		node->prev = m_back;
		m_back = node;
		return;
	}
	
	Node* prev = pos->prev;
	Node* next = pos->next;
	
	if (!prev) {
		assert(pos == m_front && "pos == null but pos != m_front.");
		m_front->prev = node;
		node->next = m_front;
		m_front = node;
	}
	else {
		prev->next = node;
		node->prev = prev;

		node->next = next;
		next->prev = node;
	}
}

DoublyLinkedList::~DoublyLinkedList()
{
	clear();
}

Node* DoublyLinkedList::front_ptr()
{
	return m_front;
}

Node* DoublyLinkedList::back_ptr()
{
	return m_back;
}

void DoublyLinkedList::print()
{
	Node* p = m_front;
	std::cout << "LinkedList values: ";
	while (p) {
		if (p == m_front)
			std::cout << "(" << p->val << ")";
		else if (p == m_back)
			std::cout << "[" << p->val << "]";
		else
			std::cout << p->val;

		p = p->next;

		if (!p)
			std::cout << "\n";
		else
			std::cout << "->";
	}
}

int DoublyLinkedList::size()
{
	return m_size;
}
