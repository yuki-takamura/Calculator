#include <iostream>
#include <iomanip>
#include <string>
#include "Calculator.h"

#define END_STRING "0"

using namespace std;

void Calculator :: Run()
{
	for(;;)
	{
		Calculator::Input();

		//有効な入力であるかを確認
		if (Calculator::CheckEnd())
			break;
		if (Calculator::CheckOverString())
			continue;
		if (Calculator::HasString())
			continue;

		Calculator::SetValue();

		Calculator::Show();
	}
}

void Calculator :: Input()
{
	cout << " 入力＞＞";

	cin >> inputString;
}

bool Calculator::CheckEnd()
{
	if (input == END_STRING)
	{
		cout << "終了しました" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool Calculator::CheckOverString()
{
	if (inputString.length() > MAX_DIGIT)
	{
		cout << MAX_DIGIT << "桁を超えています" <<  endl;
		cout << MAX_DIGIT << "桁以内で入力してください" << endl;
		return true;
	}
	else 
	{
		return false;
	}
}

bool Calculator::HasString()
{
	for (int i = 0; i < inputString.length(); i++)
	{
		if (inputString[i] < '0' || inputString[i] > '9')
		{
			cout << "数値を入力してください" << endl;
			return true;
		}
	}

	return false;
}

void Calculator::SetValue()
{
	for (int i = 0; i < inputString.length(); i++)
	{
		inputValue[i] = inputString[i] - '0';
	}
}

void Calculator::Show()
{
	for(int i = 0; i < inputString.length(); i++)
		cout << inputValue[i];

	cout << endl;
}