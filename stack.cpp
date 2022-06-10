#include "stack.hpp"

Stack::Stack()
{
	this->Head = nullptr;	
}

Stack::Stack(std::string value)
{
	this->Head = nullptr;
	this->AddString(value);
	
}

void Stack::AddString(std::string str)
{
	std::istringstream iss;
	iss.str(str);
	std::string Stripped;		
	if (str.length() > 10)
	{

		AddString(str.substr( ((str.length()/2)) , str.length()) );
		AddString(str.substr(0,str.length()/2));

	}
	else
	{
		int Current = 0;
		for(size_t i = 0; i < str.length(); ++i)				      {
			iss >> Current;
			if(Current < 0) 
			{
				this->Push(Current);
			}
			else
			{
				this->Push(Current%10);
				Current = Current/10;
			}
		}
		
	}
}
Stack Stack::Reverse()
{
	Stack Reversed;
	while(!(this->IsEmpty()))
	{
		Reversed.Push(this->Pop());
	}
	return Reversed;
}

void Stack::Push(int data)
{
	Node* NewNode = new Node(data);
	if (this->IsEmpty())
	{
		this->Head = NewNode;
	}
	else
	{
		NewNode->SetNext(this->Head);
	        this->Head = NewNode;	
	}
}

void Stack::DeleteFromHead()
{
	if(this->Head == nullptr)
	{
		return;
	}
	Node* garbage = this->Head;
	this->Head = this->Head->GetNext();
	delete garbage;
}

Stack::~Stack()
{		
	while(this->Head != nullptr)
	{
		this->DeleteFromHead();
	}
}

int Stack::Pop()
{
	if(!IsEmpty())
	{
		int Popped = this->Head->GetValue();
		this->DeleteFromHead();
		return Popped;
	}
	else
	{
		return std::numeric_limits<int>::min();
	}
}

bool Stack::IsEmpty()
{
	if(this->Head == nullptr)
	{
		return true;
	}	
	else
	{
		return false;
	}
}	
