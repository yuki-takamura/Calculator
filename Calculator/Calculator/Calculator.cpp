#include <iostream>
#include <string>
#include "Calculator.h"

#define END_STRING "0"
#define TAB 4

using namespace std;

///<summary>
/// ���s
///</summary>
void Calculator :: Run()
{
	savedDegit = 1;

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

///<summary>
/// ���͂��擾
///</summary>
void Calculator :: Input()
{
	cout << " ���� --�� ";

	cin >> inputString;
}

///<summary>
/// �I�����邩�ǂ���
///</summary>
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

///<summary>
/// ���͐������s��
///</summary>
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

///<summary>
/// ���l�ȊO�̓��͂����邩
///</summary>
bool Calculator::HasString()
{
	for (unsigned int i = 0; i < inputString.length(); i++)
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

	inputDegit = inputString.length();
}

void Calculator::Show()
{
	if (savedDegit > inputDegit)
		degit = savedDegit;
	else if (inputDegit > savedDegit)
		degit = inputDegit;

	Calculator::WriteSavedValue();

	Calculator::WriteInputValue();

	Calculator::WriteBar();

	Calculator::WriteSumValue();

	cout << endl << endl;
}

void Calculator::WriteSavedValue()
{
	cout << endl;
	cout << " ";
	for (int i = 0; i < TAB; i++)
	{
		cout << " ";
	}

	for (int i = 0; i < degit - savedDegit; i++)
	{
		cout << " ";
	}

	for (int i = savedDegit - 1; i >= 0; i--)
	{
		cout << savedValue[i];
	}
}

void Calculator::WriteInputValue()
{
	cout << endl;
	cout << "  +  ";

	for (int i = 0; i < degit - inputDegit; i++)
	{
		cout << " ";
	}

	for (int i = inputDegit - 1; i >= 0; i--)
	{
		cout << inputValue[i];
	}
}

void Calculator::WriteBar()
{
	cout << endl;
	cout << " ";
	for (int i = 0; i < TAB; i++)
	{
		cout << "-";
	}

	for (int i = 0; i < degit; i++)
	{
		cout << "-";
	}
}

void Calculator::WriteSumValue()
{
	cout << endl;
	cout << " ";
	for (int i = 0; i < TAB; i++)
	{
		cout << " ";
	}

	for (int i = 0; i < degit - inputDegit; i++)
	{
		cout << " ";
	}

	for (int i = inputDegit - 1; i >= 0; i--)
	{
		cout << inputValue[i];
	}
}