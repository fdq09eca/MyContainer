#include <iostream>
#include "LinkedList.h"
#include "DebugMarco.h"

// helpers
void test_from_begin(const List& mylist, const int* arr, const int length) {
	const Node* begin = mylist.begin();
	int i = 0;
	while (begin) {
		if (i) TEST(begin->prev->val == arr[i - 1]);
		TEST(begin->val == arr[i]);
		if (i && i < length - 1) TEST(begin->next->val == arr[i + 1]);
		begin = begin->next;
		i++;
		if (i == length - 1) TEST(begin == mylist.end());
	}
}
void test_from_end(const List& mylist, const int* arr, const int& length)
{
	const Node* end = mylist.end();
	int i = length - 1;
	while (end) {
		if (i) TEST(end->prev->val == arr[i - 1]);
		TEST(end->val == arr[i]);
		if (i && i < length - 1) TEST(end->next->val == arr[i + 1]);
		end = end->prev;
		i--;
		if (i == 0)	TEST(end == mylist.begin());
	}
}

void test_insert_before() { /*TODO*/ };
void test_insert_after() { /*TODO*/ };


void test_front() { /*TODO*/ };
void test_back() { /*TODO*/ };

void test_begin() { /*TODO*/ };
void test_end() { /*TODO*/ };

void test_push_front() {
	List mylist;
	const int length = 10;
	int arr[length] = {};
	for (int i = 0; i < length; i++)
	{
		mylist.push_front(i);
		arr[length - i - 1] = i;
	}
	mylist.print();

	test_from_begin(mylist, &(*arr), length);
	test_from_end(mylist, &(*arr), length);
}
void test_push_back() {
	List mylist;
	const int length = 10;
	int arr[length] = {};
	for (int i = 0; i < length; i++)
	{
		mylist.push_back(i);
		arr[i] = i;
	}
	test_from_begin(mylist, &(*arr), length);
	test_from_end(mylist, &(*arr), length);

}

void test_pop_front() {
	List mylist;

	for (int i = 0; i < 10; i++)
	{
		mylist.push_back(i);
		const Node* ori_front = mylist.begin();

		TEST(mylist.front() == i);

		const Node* poped_front = mylist.pop_front();

		TEST(mylist.begin() == nullptr);
		TEST(ori_front == poped_front);
	}

	TEST(mylist.empty());

	for (int i = 0; i < 10; i++)
	{
		mylist.push_back(i);
	}

	mylist.print();

	for (int i = 0; i < 10; i++)
	{
		const Node* ori_front = mylist.begin();

		TEST(mylist.front() == i);

		const Node* poped_front = mylist.pop_front();
		TEST(ori_front == poped_front);
	}

	TEST(mylist.begin() == nullptr);
}
void test_pop_back() {
	List mylist;

	// TEST pop_back when a list is established with 1 Node
	for (int i = 0; i < 10; i++)
	{
		mylist.push_back(i);
		const Node* ori_front = mylist.begin();
		const Node* ori_end = mylist.end();
		TEST(mylist.front() == i);
		TEST(mylist.back() == i);
		const Node* poped_back = mylist.pop_back();

		TEST(mylist.begin() == nullptr);
		TEST(ori_front == poped_back);
		TEST(ori_end == poped_back);
		
	}
	
	// list should be empty
	TEST(mylist.begin() == nullptr);
	TEST(mylist.end() == nullptr);
	TEST(mylist.empty());

	// TEST continuous pop_back when a list is established with > 1 Nodes
	for (int i = 0; i < 10; i++)
	{
		mylist.push_back(i);
	}

	mylist.print();

	for (int i = 0; i < 10; i++)
	{
		const Node* ori_back = mylist.end();
		mylist.print();
		TEST(mylist.front() == 0);
		TEST(mylist.back() == 10 - i - 1);
		const Node* poped_back = mylist.pop_back();
		TEST(ori_back == poped_back);
	}

	// list should be empty
	TEST(mylist.begin() == nullptr);
	TEST(mylist.end() == nullptr);
	TEST(mylist.empty());

}

void test_pop() {
	// Arrange
	List mylist;
	int size = 10;
	for (int i = 0; i < size; i++)
	{
		mylist.push_back(i);
	}

	mylist.print();

	const Node* h = mylist.begin();
	const Node* h_next = h->next;
	
	const Node* t = mylist.end();
	const Node* t_prev = t->prev;
	
	//Act test_pop_front:
	const Node* pop_h = mylist.pop(h);
	
	mylist.print();
	//Assert
	TEST(pop_h == h);
	TEST(mylist.begin() == h_next);
	TEST(mylist.size() == --size);
	
	// Act test_pop_end:
	const Node* pop_t = mylist.pop(t);
	mylist.print();
	//Assert
	TEST(pop_t == t);
	TEST(mylist.end() == t_prev);
	TEST(mylist.size() == --size);

	// test_pop
	const Node* h0 = mylist.begin();
	const Node* n1 = mylist.begin()->next;
	const Node* n2 = n1->next;

	const Node* pop_n1 = mylist.pop(n1);
	mylist.print();
	TEST(n1 == pop_n1);
	TEST(mylist.begin() == h0);
	TEST(mylist.begin()->prev == nullptr);
	TEST(mylist.begin()->next == n2);
	TEST(n2->prev == mylist.begin());
	TEST(mylist.size() == --size);

}

void test_erase() { 
	List mylist;
	mylist.push_back(20);
	const Node* b = mylist.begin();
	mylist.erase(b);
	TEST(mylist.size() == 0);
}

void test_size() {
	const int length = 10;
	List list;
	for (int i = 0; i < length; i++)
	{
		list.push_back(i);
	}
	TEST(list.size() == length);
}
void test_empty() {
	List mylist;
	TEST(mylist.empty() == true);
}

int main() {
	//test_push_front(); //PASS
	//test_push_back(); // PASS
	//test_size(); // PASS
	//test_empty(); // PASS
	//test_pop_front(); // PASS.. but memory leak here. poped node is not deleted
	//test_pop_back(); // PASS.. but memory leak here. poped node is not deleted
	// test_pop(); //PASS
	//test_erase(); //PASS ?
	return 0;
}