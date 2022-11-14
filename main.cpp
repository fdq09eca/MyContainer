#include <iostream>
#include "LinkedList.h"
#include "DebugMarco.h"

// helpers
void test_from_begin(const DoublyLinkedList& mylist, const int* arr, const int length) {
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
void test_from_end(const DoublyLinkedList& mylist, const int* arr, const int& length)
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

int main() {
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