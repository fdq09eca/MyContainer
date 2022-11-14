#include "Node.h"
#include <iostream>
#include <assert.h>

Node::~Node()
{
	std::cout << "Delete Node:" << val << std::endl;	
	assert(!prev && !next && "prev or next is not null");
}