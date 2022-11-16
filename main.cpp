#include <iostream>
#include "LinkedList.h"
#include "DebugMarco.h"

void test_insert() {
	// Arrange
	DoublyLinkedList dll;
	int length = 10;

	//Action
	for (int i = 0; i < length; i++)
	{
		Node* p = new Node(i);
		dll.insert(nullptr, p); // push_back!!
	}

	//Assert
	Node* h = dll.front_ptr();
	for (int v = 0; h; v++)
	{
		dump_var(v);
		dump_var(h->val);
		if (h->prev) TEST(h->prev->val == h->val - 1);
		TEST(h->val == v);
		if (h->next) TEST(h->next->val == h->val + 1);
		h = h->next;
	}
	TEST(h == nullptr);
	
	// push_front
	
	//Assert
	Node* f0 = dll.front_ptr();
	TEST(f0->prev == nullptr);
	TEST(f0->val == 0);
	TEST(f0->next->val == 1);
	
	dll.print();
	
	//Action
	dll.insert(dll.front_ptr(), new Node(-1));
	//Assert
	Node* f1 = dll.front_ptr();
	TEST(f1->prev == nullptr);
	TEST(f1->val == -1);
	TEST(f1->next == f0);
	
	dll.print();

	//Action
	dll.insert(dll.front_ptr(), new Node(-2));
	//Assert
	Node* f2 = dll.front_ptr();
	TEST(f2->prev == nullptr);
	TEST(f2->val == -2);
	TEST(f2->next == f1);
	dll.print();

	
	// f2 f1 -3 f0
	//       ^
	
	dll.insert(f0, new Node(-3));
	dll.print();
	Node* f0p = f0->prev;
	dump_var(f0p->val);
	TEST(f0p->val == -3);
	TEST(f0p->prev == f1);
	TEST(f0p->next == f0);
	


	
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