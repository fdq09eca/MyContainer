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

void test_find() {
	//Arrange
	DoublyLinkedList dll;
	int length = 10;

	for (int i = 0; i < length; i++)
	{
		dll.push_back(new Node(i));
	}
	
	
	
	// Action and Assert
	for (int i = 0; i < length; i++)
	{
		TEST(dll.find(i));
	}
	
	TEST(dll.find(10) == nullptr);
	TEST(dll.find(-10) == nullptr);


}

void test_reverse() {
	//Arrange
	DoublyLinkedList dll;
	int length = 10;
	
	for (int i = 0; i < length; i++)
	{
		dll.push_back(new Node(i));
	}
	dll.print();

	Node* f0 = dll.front_ptr();
	Node* b0 = dll.back_ptr();
	
	//Action
	dll.reverse();
	dll.print();
	
	//Assert
	Node* f1 = dll.front_ptr();
	Node* b1 = dll.back_ptr();

	TEST(f1 == b0);
	TEST(b1 == f0);


	Node* p = f1;
	int v = length - 1;

	for (; p; v--)
	{
		dump_var(p->val);
		if (p->prev) TEST(p->prev->val == v + 1);
		TEST(p->val == v);
		if (p->next) TEST(p->next->val == v - 1);
		p = p->next;
	}
}




int main() {
	//test_insert(); // PASS
	//test_find(); //PASS
	test_reverse(); // PASS
	return 0;
}