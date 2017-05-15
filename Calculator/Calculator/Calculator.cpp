#include <iostream>
#include <string>
#include "Calculator.h"

#define END_STRING "0"

using namespace std;

///<summary>
/// ���s
///</summary>
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
	//�������l-----------------------------------
	cout << endl;
	cout << " ";
	for (int i = 0; i < 4; i++)
	{
		cout << " ";
	}
	for (int i = 50 - 1; i >= 0; i--)
	{
		cout << savedValue[i];
	}

	//�����l--------------------------------------
	cout << endl;
	cout << "  +  ";

	for (int i = inputString.length() - 1; i >= 0; i--)
	{
		cout << inputValue[i];
	}

	//�C�R�[��------------------------------------
	cout << endl;
	cout << " ";
	for (int i = 0; i < 4; i++)
	{
		cout << "-";
	}

	for (int i = inputString.length() - 1; i >= 0; i--)
	{
		cout << "-";
	}

	//���v�l-------------------------------------
	cout << endl;
	cout << " ";
	for (int i = 0; i < 4; i++)
	{
		cout << " ";
	}

	for (int i = inputString.length() - 1; i >= 0; i--)
	{
		cout << inputValue[i];
	}

	cout << endl << endl;
}