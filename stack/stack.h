#pragma once

class Stack
{
public:
	class Node {
	public:
		Node(int val);
		~Node() = default;
		Node(const Node& source);
		Node& operator=(const Node& source);
		int value;
		Node* next = nullptr;
	};

public:
	Stack() = default;
	~Stack();
	Stack(const Stack& source);
	Stack& operator=(const Stack& source);
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;
	void Print() const;

private:
	int value;
	Node* head = nullptr;
};