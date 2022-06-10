#include "stack.hpp"
#include <iostream>
int main()
{
	Stack stk;
	stk.Push(-1);
	std::cout << stk.Pop();
}
