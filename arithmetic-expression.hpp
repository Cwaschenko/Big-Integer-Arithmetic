#ifndef ARITHMETIC_EXPRESSION_HPP
#define ARITHMETIC_EXPRESSION_HPP
#include "operand.hpp"
#include <string>
#include <sstream>
#include <iostream>

class ArithmeticExpression 
{
	private:
		Operand* Operand1;
		Operand* Operand2;
		char Operation;
	public:
		ArithmeticExpression(std::string Operand1, std::string Operand2, char Operation);
		~ArithmeticExpression();
		char GetOperation()const;
		Operand* GetOp1()const;
		Operand* GetOp2()const;

		friend std::ostream& operator << (std::ostream& out, const ArithmeticExpression& AE);
};

#endif
