
### Project Requirements:
Your application must function as described below:

In this project we will add or subtract arbitrarily large numbers. We will add or subtract arbitrarily large unsigned numbers. We must decide:
- if we must reverse operands 
- if we must prepend a minus (-) sign to the result.

The first case, reversing operands, must be performed if we are subtracting and the [subtrahend](https://www.merriam-webster.com/dictionary/subtrahend) has a larger absolute value than the [minuend](https://www.merriam-webster.com/dictionary/minuend).
In that case, we must prepend a minus (-) sign to the result.

The program will involve arbitrarily large operands represented as strings.
This will involve:
- creating three stacks
- padding the shorter operand to the length of the longer one
- pushing chars or int equivalents onto the two operand stacks
- popping
	- applying the appropriate operation
		- possibly setting a carry or borrow flag
- and pushing the result digit-by-digit onto a result stack.

Then, of course, we get the answer by popping the result stack until empty.

#### We will have the following classes
1. `ExpressionReader`: reads a file of arithmetic expressions and creates instances of class `ArithmeticExpression`.
1. `ArithmeticExpression`: class that holds an operator and two operands.
1. `Operand`:  a class to provide a string for the numeric value; it will be able to pad on the left by a specified amount. 
1. `BigIntegerArithmetic`: Takes an `ArithmeticExpression` instance, makes the decisions about reversing operands and sign on result, performs the operation(s) and displays the result.
1. `Stack`: used by `BigIntegerArithmetic` to add or subtract. The program will use three of them, as mentioned.
1. `Node`: used by the stack to hold individual digits.

... and, of course, `main()` to get the whole ball rolling by constructing an `ExpressionReader` with a file name as a parameter to the constructor. `main()` should be very simple since it will mimic [test/test-6-expression-reader.cpp](test/test-6-expression-reader.cpp).

#### Sample data
```
12 + 5
5 + 12
12 - 5
5 - 12
364287462834623846283426384 + 923742938742934723947239847
364287462834623846283426384 - 923742938742934723947239847
```

#### Output for the above input should look like this:
```
12
+5
17
----------
  5
+12
 17
----------
12
-5
 7
----------
  5
-12
 -7
----------
 364287463834623846283426384
+923742938742934723947239847
1288030402577558570230666231
----------
 364287463834623846283426384
-923742938742934723947239847
-559455474908310877663813463
----------
```

