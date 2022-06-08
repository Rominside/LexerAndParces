#pragma once
#include <string>
#include "RootObject.h"
#include "Node.h"

class LinkedList : public RootObject
{
public:
	//LinkedList(std::string name, std::vector<int> number_Mass);

	Node* first;
	Node* last;
	LinkedList(std::string name);
	bool is_empty();
	void push_back(int _val);
	Node* find(int _val);
	void remove_first();
	void remove_last();
	void remove(int _val);
	int size();
};

