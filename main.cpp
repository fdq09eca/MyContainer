#include <iostream>
#include "LinkedList.h"
#include <stdio.h>

int main() {
	std::cout << "hello." << std::endl;
	LinkedList ll(1);
	ll.add_back(2);
	ll.add_back(3);
	ll.add_back(4);
	ll.print();

	return 0;
}