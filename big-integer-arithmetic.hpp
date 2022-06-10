#ifndef BIGINT_HPP
#define BIGINT_HPP
#include <string>
#include <sstream>
#include "arithmetic-expression.hpp"
#include "stack.hpp"
class BigIntegerArithmetic
{
	private:
		ArithmeticExpression* AE;
	public:
		BigIntegerArithmetic(ArithmeticExpression* AE);
		bool Op1IsBigger(std::string Op1, std::string Op2);
		std::string ShowResults();
		std::string Add(Stack& Op1, Stack& Op2);
		std::string Subtract(Stack& Op1, Stack& Op2);
		void Carry(Stack& Stk, int Carried, char Operation);

			
		

};

#endif
