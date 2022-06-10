#include "operand.hpp"

Operand::Operand()
{
	this->Value = "";
}

Operand::Operand(std::string Value)
{
	this->Value = Value;
}

bool Operand::IsNegative()
{
	std::stringstream ss(this->Value);
	char Current;
	while(ss >> Current)
	{
		if (Current == '-')
		{
			return true;
		}	
	}	
	return false;
}

std::string Operand::GetValue()const
{
	return this->Value;
}

int Operand::GetNumberOfDigits()
{
	std::stringstream ss(this->Value);
	char Current;
	int Count = 0;
	while(ss >> Current)
	{
		++Count;
	}
	return Count;
}

void Operand::Pad(int NumToPad)
{
	std::stringstream ss;
	for (int i = 0; i < NumToPad; ++i)
	{
	ss << 0;
	}
	ss << this->Value;
	this->SetValue(ss.str());
}

void Operand::SetValue(std::string Value)
{
	this->Value = Value;
}

void Operand::FlipSign()
{
	std::stringstream StringStreamIn(this->Value);
	std::stringstream StringStreamOut;
	char Current;
	while(StringStreamIn >> Current)
	{
		if (Current == '-')
		{
			continue;
		}	
		else
		{
			StringStreamOut << Current;
		}
	}
	this->SetValue(StringStreamOut.str());	
}
