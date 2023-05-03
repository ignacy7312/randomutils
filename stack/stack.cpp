#include "Stack.h"
#include <iostream>

Stack::~Stack()
{
	int size = Size();
	int crap;
	for (int i = 0; i < size; i++) {
		crap = this->Pop();
	}
}

Stack::Stack(const Stack& source)
{
	*this = source;
}

Stack& Stack::operator=(const Stack& source)
{
	Node* tmp = source.head;
	while (tmp->next != nullptr) {
		this->Push(tmp->value);
		tmp = tmp->next;
	}
	this->Push(tmp->value);
	return *this;
}

void Stack::Push(int val)
{
	if (Empty()) {
		head = new Node(val);
	}
	else {
		Node* tmp = head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = new Node(val);
	}
}

int Stack::Pop()
{
	if (Empty()) {
		return -1;
	}
	
	int val;

	if (Size() == 1) {
		val = head->value;
		delete head;
		head = nullptr;

	}
	else {
		Node* tmp = head;

		while (tmp->next->next != nullptr) {
			tmp = tmp->next;
		}
		val = tmp->next->value;

		delete tmp->next;
		tmp->next = nullptr;
	}
	return val;
}

int Stack::Size() const
{
	int n = 0;
	Node* tmp = head;
	while (tmp != nullptr) {
		tmp = tmp->next;
		n++;
	}
	return n;
}

bool Stack::Empty() const
{
	return head == nullptr;
}

void Stack::Print() const
{
	Node* tmp = head;
	while (tmp->next != nullptr) {
		std::cout << tmp->value << ' ';
		tmp = tmp->next;
	}
	std::cout << tmp->value << ' ';
	std::cout << std::endl;
}

Stack::Node::Node(int val)
	:
	value (val)
{
}

//Stack::Node::~Node()
//{
//
//}

Stack::Node::Node(const Node& source)
{
	*this = source;
}

Stack::Node& Stack::Node::operator=(const Node& source)
{
	this->value = source.value;
	this->next = source.next;
	return *this;
}
