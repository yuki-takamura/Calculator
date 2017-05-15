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
		int degit;
		int savedValue[MAX_DIGIT] = { 0 };
		int savedDegit;
		int inputValue[MAX_DIGIT];
		int inputDegit;
		int sum[MAX_DIGIT];
		int sumDegit;

		int tabCount;


		void Input();

		bool CheckEnd();
		bool CheckOverString();
		bool HasString();

		void SetValue();

		void Show();
		void WriteSavedValue();
		void WriteInputValue();
		void WriteBar();
		void WriteSumValue();
};

#endif
