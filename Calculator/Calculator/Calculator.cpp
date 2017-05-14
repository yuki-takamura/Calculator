#include <iostream>
#include <string>
#include "Calculator.h"

#define END_STRING "0"

using namespace std;

void Calculator :: Run()
{
	for(;;)
	{
		Calculator::Input();

		//�L���ȓ��͂ł��邩���m�F
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
	cout << " ���́���";

	cin >> inputString;
}

bool Calculator::CheckEnd()
{
	if (inputString == END_STRING)
	{
		cout << "�I�����܂���" << endl;
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
		cout << MAX_DIGIT << "���𒴂��Ă��܂�" <<  endl;
		cout << MAX_DIGIT << "���ȓ��œ��͂��Ă�������" << endl;
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
			cout << "���l����͂��Ă�������" << endl;
			return true;
		}
	}

	return false;
}

void Calculator::SetValue()
{
	for (int i = inputString.length() - 1; i >= 0; i--)
	{
		inputValue[inputString.length() - 1 - i] = inputString[i] - '0';
	}
}

void Calculator::Show()
{
	for(int i = 0; i < inputString.length(); i++)
		cout << inputValue[i];

	cout << endl;
}