
#ifndef STACK_HPP
#define STACK_HPP
#include <limits>
#include "node.hpp"
#include <string>
#include <sstream>
class Stack
{
	private:
		Node* Head;		
	public:
		Stack();
		Stack(std::string str);
		~Stack();
		void AddString(std::string str);
		void DeleteFromHead();
		void Push(int data);
		int Pop();
		bool IsEmpty();
		Stack Reverse();
};
#endif
