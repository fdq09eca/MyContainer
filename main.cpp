#include <iostream>
#include "LinkedList.h"
#include "DebugMarco.h"



void test_push_back() {
	List mylist;	
	const int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	const int length = 10;
	for (size_t j = 0; j < length; j++)
	{
		mylist.push_back(j + 1);
	}

	const Node* begin = mylist.begin();
	const Node* end = mylist.end();
	
	int i = 0;	
	while (begin) {
		if (i) TEST(begin->prev->val == arr[i - 1]);
		TEST(begin->val == arr[i]);
		if (i && i < length - 1) TEST(begin->next->val == arr[i + 1]);
		begin = begin->next;
		i++;
		if (i == length - 1) TEST(begin == mylist.end());
	}

	i = length - 1;
	while (end) {	
		if (i) TEST(end->prev->val == arr[i - 1]);
		TEST(end->val == arr[i]);
		if (i && i < length - 1) TEST(end->next->val == arr[i + 1]);
		end = end->prev;
		i--;
		if (i == 0)	TEST(end == mylist.begin());
	}
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
	test_push_back();
	return 0;
}