#include "Node.h"
#include <iostream>

Node::~Node()
{
	std::cout << "Delete Node:" << val << std::endl;
	val = 0;
	delete next;

}
