#include <iostream>
#include "LinkedList.h"
#include "DebugMarco.h"



void test_insert() {
	DoublyLinkedList dll;
	int length = 10;
	for (int i = 0; i < length; i++)
	{
		Node* p = new Node(i);
		dll.insert(nullptr, p); // push_back!!
		if (i)
			TEST(p->prev->val == i - 1);
			
	}
	
	dll.print();
	
}

int main() {
	test_insert();

	// test_push_front(); //PASS
	// test_push_back(); // PASS
	// test_size(); // PASS
	// test_empty(); // PASS
	// test_pop_front(); // PASS.. but memory leak here. poped node is not deleted
	// test_pop_back(); // PASS.. but memory leak here. poped node is not deleted
	// test_pop(); //PASS
	// test_erase(); //PASS ?
	return 0;
}