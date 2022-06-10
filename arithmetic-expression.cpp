#include "arithmetic-expression.hpp"

ArithmeticExpression::ArithmeticExpression(std::string Operand1, std::string Operand2, char Operation)
{
	this->Operand1 = new Operand(Operand1);
	this->Operand2 = new Operand(Operand2);
	this->Operation = Operation;

	if (this->Operand1->GetNumberOfDigits() > this->Operand2->GetNumberOfDigits())
	{
		if(this->Operand2->IsNegative())
		{
			if (this->Operation == '-')
			{
				this->Operand2->FlipSign();
				this->Operation = '+';
			}
			else
			{
				this->Operand2->FlipSign();
				this->Operation = '-';

			}
		}
		int Num = this->Operand1->GetNumberOfDigits() - this->Operand2->GetNumberOfDigits();  
		this->Operand2->Pad(Num);
	}
	else
	{
		int Num = this->Operand2->GetNumberOfDigits() - this->Operand1->GetNumberOfDigits();  
		this->Operand1->Pad(Num);		
	}
}

ArithmeticExpression::~ArithmeticExpression()
{
	delete this->Operand1;
	delete this->Operand2;
}

char ArithmeticExpression::GetOperation()const
{
	return this->Operation;
}

Operand* ArithmeticExpression::GetOp2()const
{
	return this->Operand2;
}

Operand* ArithmeticExpression::GetOp1() const
{
	return this->Operand1;
}

std::ostream& operator << (std::ostream& out, const ArithmeticExpression& AE)
{
	out << AE.GetOp1()->GetValue() << " " << AE.GetOp2()->GetValue() << " " << AE.GetOperation();

	return out;
}
