#include "big-integer-arithmetic.hpp"

BigIntegerArithmetic::BigIntegerArithmetic(ArithmeticExpression* AE)
{
	this->AE = AE;
}

bool BigIntegerArithmetic::Op1IsBigger(std::string Op1, std::string Op2)
{
	if (Op1 > Op2)
	{
		return true;
	}

	else 
	{
		return false;
	}
}

std::string BigIntegerArithmetic::ShowResults()
{
	Stack Op1(this->AE->GetOp1()->GetValue());
	Stack Op2(this->AE->GetOp2()->GetValue());
	std::string result = " ";	
	if (this->AE->GetOperation() == '-' )
	{
		result = this->Subtract(Op1, Op2);		
	}
	else 
	{
		result = this->Add(Op1, Op2);
	}	

	return " " + this->AE->GetOp1()->GetValue() + "\n" + this->AE->GetOperation()  + this->AE->GetOp2()->GetValue() + "\n" + result; 	
}

void BigIntegerArithmetic::Carry(Stack& Stk, int Carried, char Operation)
{
	if (Operation == '+')
	{
		int Previous = Stk.Pop() + 1;
		if (Previous >= 10)
		{
			this->Carry(Stk, Previous, Operation);
			Stk.Push(Carried % 10);
		}
		else
		{
			Stk.Push(Previous);
			Stk.Push(Carried % 10);
		}
	}
	else
	{
		int Previous = Stk.Pop() -1 ;
		if (Previous < 0)
		{
			if (Stk.IsEmpty())
			{
				Stk.Push(Previous);
				Stk.Push(10 - abs(Carried));

			}	
			
			this->Carry(Stk, Previous, Operation);
			Stk.Push(10 - abs(Carried));
		}
		else
		{
			Stk.Push(Previous);
			Stk.Push(10 - abs(Carried));
	
		}
	}
}

std::string BigIntegerArithmetic::Add(Stack& Op1, Stack& Op2)
{	Stack Value;
	Stack FlipStack;
	int Added;
	int Previous;
	std::ostringstream oss;
	while(!(Op1.IsEmpty()))
	{
		Added = Op1.Pop() + Op2.Pop();

		if (Added >= 10)
		{
			if (Value.IsEmpty())
			{
				Value.Push(Added/10);
				Value.Push(Added%10);		
			}
			else
			{
				this->Carry(Value, Added, '+');	
			}
		}	
		else
		{
			Value.Push(Added);
		}
	}

	while(!(Value.IsEmpty()))
	{
		FlipStack.Push(Value.Pop());
	
	}
	while(!(FlipStack.IsEmpty()))
	{
		oss << FlipStack.Pop();
	
	}
	return oss.str();

}


std::string BigIntegerArithmetic::Subtract(Stack& Op1, Stack& Op2)
{	
	Stack Value;
	Stack FlipStack;
	int Difference;
	int Previous;
	std::ostringstream oss;
	
	while(!(Op1.IsEmpty()))
	{
		Difference  = Op1.Pop() -  Op2.Pop();
		if (Difference < 0)
		{
			if (Value.IsEmpty())
			{
				Value.Push(Difference);
			}	
			else
			{
				this->Carry(Value, Difference, '-');
			}
		}
		else
		{
			Value.Push(Difference);
		}
	}
	while(!(Value.IsEmpty()))
	{
		FlipStack.Push(Value.Pop());
	
	}
	while(!(FlipStack.IsEmpty()))
	{
		oss << FlipStack.Pop();
	
	}
	return oss.str();
}
