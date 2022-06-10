#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <sstream>
#include <string>

class Operand
{
	private:
		std::string Value;

	public:
		Operand();
		Operand(std::string Value);
		bool IsNegative();
		std::string GetValue()const;
		int GetNumberOfDigits();
		void Pad(int NumToPad);
		void SetValue(std::string Value);
		void FlipSign();
		
};

#endif
