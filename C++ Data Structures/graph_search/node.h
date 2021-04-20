#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

typedef string ItemType;

struct Node
{
  ItemType value;
  Node* next;
};

#endif