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

		std::string inputString;
		int digit;
		int savedValue[MAX_DIGIT];
		int savedDigit;
		int inputValue[MAX_DIGIT];
		int inputDigit;
		int sum[MAX_DIGIT];
		int sumDigit;
		bool hasError;

		///<summary>
		/// å∏éZÇçsÇ§Ç∆Ç´ÇÃÉtÉâÉOïœêî
		///</summary>
		bool subtraction;

		void Initialize();

		void Input();

		bool CheckEnd();
		bool CheckInitialize();
		bool CheckOverString();
		bool HasString();

		void SetValue();
		void Calculate();
		void CalculateAddition();
		void CalculateSubtraction();

		void Draw();
		void WriteSavedValue();
		void WriteInputValue();
		void WriteBar();
		void WriteSumValue();

		void Reset();
};

#endif