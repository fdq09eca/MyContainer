#include "LinkedList.h"
#include <cassert>

const Node* List::insert_before(Node* pos, const int& value)
{
	if (!pos) return nullptr;

	Node* n = new Node(value);
	Node* prev = pos->prev;
	if (!prev) {
		assert(pos == m_front && "pos->prev == null but pos != m_front");
		m_front->prev = n;
		n->next = m_front;
		m_front = n;
	}
	else {
		pos->prev = n;
		n->next = pos;
		prev->next = n;
		n->prev = prev;
	}

	return n;
}

const Node* List::insert_after(Node* pos, const int& value)
{
	if (!pos) return nullptr;

	Node* n = new Node(value);
	Node* next = pos->next;
	if (!next) {
		assert(pos == m_back && "pos->next is null but pos != m_back");
		m_back->next = n;
		n->prev = m_back;
		m_back = n;
	}
	else {
		pos->next = n;
		n->prev = pos;
		n->next = next;
		next->prev = n;
	}

	return n;
}

/// <summary>
/// Pop a Node from the list, 
/// Node that Node is not deleted. 
/// It is still attached with the prev/next pointer that can access the list.
/// not sure if it is needed..
/// </summary>
/// <param name="node"></param>
/// <returns>const Node*</returns>
const Node* List::pop(const Node * node)
{
	if (!node) return nullptr;
	if (!node->prev) {
		assert(node == m_front && "node->prev == nullptr but node != m_head");
		return pop_front();
	}
	if (!node->next) {
		assert(node == m_back && "node->next == nullptr but node != m_head");
		return pop_back();
	}
	
	Node* prev = node->prev;
	Node* next = node->next;

	prev->next = next;
	next->prev = prev;
	
	return node;
}

List::~List()
{
	delete m_front;
}

const int& List::front()
{
	assert(m_front && "m_front == null, cannot call front().");
	return m_front->val;
}

const int& List::back()
{
	assert(m_back && "m_back == null, cannot call front().");
	return m_back->val;
}

const Node* List::begin() const {
	return m_front;
}

const Node* List::end() const {
	return m_back;
}

const void List::print() const
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

const Node* List::push_front(const int& value)
{
	return m_front ? insert_before(m_front, value) : init(value);
}

const Node* List::push_back(const int& value)
{
	return m_back ? insert_after(m_back, value) : init(value);
}

const Node* List::pop_front()
{
	if (!m_front) return nullptr;
	Node* ret_ptr = m_front;
	if (m_front == m_back)
		reset();
	else
		set_front(m_front->next);
		/*m_front = m_front->next;
		if (m_front) m_front->prev= nullptr;*/
	return ret_ptr;
}

const Node* List::pop_back()
{
	if (!m_back) return nullptr;
	Node* ret_ptr = m_back;

	if (m_front == m_back)
		reset();
	else
		set_back(m_back->prev);
	return ret_ptr;
}

void List::set_front(Node* node) {
	if (!node) return;
	node->prev = nullptr;
	m_front = node;
}

void List::set_back(Node* node) {
	if (!node) return;
	node->next = nullptr;
	m_back = node;
}

void List::reset()
{
	m_back = nullptr;
	m_front = nullptr;
}

const Node* List::init(const int& value)
{
	assert(m_front == nullptr && m_back == nullptr && "m_back or m_front != nullptr");
	m_front = new Node(value);
	m_back = m_front;
	return m_back;
}

bool List::empty()
{
	return size() == 0;
}

int List::size()
{
	if (!m_front) return 0;
	int size = 0;
	Node* p = m_front;
	while (p) {
		size++;
		p = p->next;
	}
	return size;
}

const Node* List::erase(Node* pos)
{
	const Node* p = pop(pos);	
	if (!p) return nullptr;
	const Node* next = p->next;
	const_cast<Node*>(p)->reset()->~Node();
	return next;
}
