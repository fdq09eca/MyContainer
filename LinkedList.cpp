#include "LinkedList.h"
#include <cassert>

List::~List()
{
	delete m_front;
}

const int& List::front()
{
	assert(!empty() == true && "list is empty, access front() failed.\n");
	return m_front->val;
}

const int& List::back()
{
	assert(!empty() == true && "list is empty access back() failed.\n");
	return m_back->val;
}

const Node* List::begin()
{
	return m_front;
}

const Node* List::end()
{
	return m_back;
}




void List::print()
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

		if (p) {
			std::cout << " -> ";
		}
		else {
			std::cout << std::endl;
		}

	}
}

void List::push_back(const int& value)
{
	if (!m_front) {
		m_front = new Node(value);
		m_back = m_front;
		
		m_front->prev = nullptr;
		m_front->next = m_back;
		
		m_back->prev = m_front;
		m_back->next = nullptr;
		return;
	}
	Node* h = m_front;
	
	while (true) {
		if (!h->next) {
			h->next = new Node(value);
			m_back = h->next;
			break;
		}
		h = h->next;
	}
}

bool List::empty()
{
	return m_front == nullptr && m_back == nullptr;
}
