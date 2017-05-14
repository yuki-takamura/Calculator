#ifndef ___Class_Calculator
#define ___Class_Calculator
#include <iostream>
#include <string>

class Calculator
{
public:

	void Run();

private:
	std :: string input;

	void Input();
	bool CheckEnd();
	bool CheckOverString();
	bool HasString();
};

#endif
