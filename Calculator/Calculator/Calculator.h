#ifndef ___Class_Calculator
#define ___Class_Calculator
#include <iostream>
#include <string>

#define MAX_DIGIT 50

class Calculator
{
	public:

		void Run();

	private:

		std :: string inputString;
		int savedValue[MAX_DIGIT] = { 0 };
		int inputValue[MAX_DIGIT];
		int sum[MAX_DIGIT];
		int tabCount;


		void Input();

		bool CheckEnd();
		bool CheckOverString();
		bool HasString();

		void SetValue();

		void Show();
};

#endif
