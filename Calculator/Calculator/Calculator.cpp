#include <iostream>
#include <string>
#include "Calculator.h"

#define MAX_DIGIT 50
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
	}
}

void Calculator :: Input()
{
	cout << "入力＞＞";

	cin >> input;
}

bool Calculator::CheckEnd()
{
	if (input == END_STRING)
		return true;
	else
		return false;
}

bool Calculator::CheckOverString()
{
	if (input.length() > MAX_DIGIT)
		return true;
	else
		return false;
}

bool Calculator::HasString()
{
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] < '0' || input[i] > '9')
			return true;
	}

	return false;
}