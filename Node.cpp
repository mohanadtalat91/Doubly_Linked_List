#include "Node.h"
#include <iostream>

Node::Node(int value)
{
     data = value ;
     next = prev = nullptr ;
}

Node::~Node(){

     std::cout << "\nDeleted data " << data << "\n\n" ;
}


