#include "node.hpp"

Node::Node(int data)
{
	this->data = data;
	this->next = nullptr;
}

Node::~Node()
{
	
}
Node::Node()
{
	this->next = nullptr;
}

Node& Node::operator=(const Node& obj)
{
	next = obj.GetNext();
	data = obj.GetValue();
	return *this;
}

void SetValue();

void Node::SetNext(Node* next)
{
	this->next = next;
}

int Node::GetValue() const
{
	return this->data;
}

Node* Node::GetNext()const
{
	return this->next;
}
