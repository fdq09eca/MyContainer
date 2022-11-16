#include "LinkedList.h"
#include <cassert>


void DoublyLinkedList::clear()
{
	Node* h = m_front;
	while (h) {
		Node* n = h->next;
		remove(h); // not optional, assertion error from ~Node() otherwise
		delete h;
		h = n;
	}
	assert(m_size == 0 && "size != 0 after clear()");
}

void DoublyLinkedList::insert(Node* pos, Node* node)
{
	if (!pos && !m_front && !m_back) {
		// insert 1st node
		m_front = node;
		m_back = node;
		m_size++;
		return;
	}

	if (!pos) {
		// special case: insert after m_back;
		// m_back-> <-[node]
		assert(m_back, "tried to push_back() but m_back == null");
		m_back->next = node;
		node->prev = m_back;
		m_back = node;
		m_size++;
		return;
	}
	
	Node* prev = pos->prev;
	
	if (!prev) {
		// push front
		assert(pos == m_front && "pos == null but pos != m_front.");
		pos->prev = node;
		node->next = m_front;
		m_front = node;
		m_size++;
	}
	else {
		// insert before pos.
		// prev -> <-{node}-> <- pos
		pos->prev = node;
		prev->next = node;
		node->prev = prev;
		node->next = pos;
		m_size++;
	}
}

void DoublyLinkedList::remove(Node* node)
{
	
	Node* prev = node->prev;
	Node* next = node->next;
	if (prev) prev->next = next;
	if (next) next->prev = prev;
	
	node->next = nullptr;
	node->prev = nullptr;
	m_size--;
}

Node* DoublyLinkedList::push_front(Node* node)
{
	insert(m_front, node);
	return m_front;
}

Node* DoublyLinkedList::push_back(Node* node)
{
	insert(nullptr, node);
	return m_back;
}

Node* DoublyLinkedList::pop_front()
{
	remove(m_front);
	return m_front;
}

Node* DoublyLinkedList::pop_back()
{
	remove(m_back);
	return m_back;
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

Node* DoublyLinkedList::find(const int & value)
{
	Node* p = m_front;
	for (; p;) {
		if (p->val == value) 
			return p;
		p = p->next;
	}
	return nullptr;
}

void DoublyLinkedList::reverse()
{
	Node* p = m_front;
	Node* next = nullptr;
	while (p) {
		next = p->next;
		std::swap(p->prev, p->next);
		p = next;
	}
	std::swap(m_front, m_back);
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
