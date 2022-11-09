#include <iostream>
#include "LinkedList.h"
#include "DebugMarco.h"


void test_begin() {
	List mylist;
	const Node* h = mylist.begin();
	TEST(h == nullptr);
	mylist.push_back(1);
	const Node* q = mylist.begin();
	TEST(q->val == 1);
	TEST(q->next == nullptr);
}

void test_end() {
	List mylist;
	const Node* e = mylist.end();
	TEST(e == nullptr);
	mylist.push_back(1);
	const Node* p = mylist.end();
	TEST(p->val == 1);
}

void test_push_back() {
	List mylist;
	mylist.push_back(1);
	TEST(mylist.front() == 1);
	TEST(mylist.back() == 1);

	mylist.push_back(2);
	TEST(mylist.front() == 1);
	TEST(mylist.back() == 2);
	mylist.push_back(3);
	TEST(mylist.front() == 1);
	TEST(mylist.back() == 3);
}


void test_empty() {
	List mylist;
	TEST(mylist.empty());
}

void test_back() {
	List mylist;
	mylist.push_back(11);
	TEST(mylist.back() == 11);
}

void test_front() {
	List mylist;
	mylist.push_back(11);
	TEST(mylist.front() == 11);
	return;
}

void test_ctor() {
	List mylist;
}

int main() {
	test_empty();
	test_begin();
	test_front();
	test_back();
	test_push_back();
	return 0;
}