#include <iostream>
#include <string>
#include "Calculator.h"

#define OBJ Calculator:: 
#define END_STRING "0"
#define TAB 4

using namespace std;

///<summary>
/// ���s
///</summary>
void OBJ Run()
{
	savedDegit = 1;

	for(;;)
	{
		OBJ Input();

		//�L���ȓ��͂ł��邩���m�F
		if (OBJ CheckEnd())
			break;
		if (OBJ CheckOverString())
			continue;
		if (OBJ HasString())
			continue;

		OBJ SetValue();

		OBJ Calculate();

		OBJ Draw();
	}
}

///<summary>
/// ���͂��擾
///</summary>
void OBJ Input()
{
	cout << " ���� --�� ";

	cin >> inputString;
}

///<summary>
/// �I�����邩�ǂ���
///</summary>
bool OBJ CheckEnd()
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
bool OBJ CheckOverString()
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
bool OBJ HasString()
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

void OBJ SetValue()
{
	for (int i = inputString.length() - 1; i >= 0; i--)
	{
		inputValue[inputString.length() - 1 - i] = inputString[i] - '0';
	}

	inputDegit = inputString.length();
}

void OBJ Calculate()
{
	if (savedDegit > inputDegit)
		degit = savedDegit;
	else if (inputDegit > savedDegit)
		degit = inputDegit;

	for (int i = 0; i < degit; i++)
	{
		sum[i] = savedValue[i] + inputValue[i];
		if (sum[i] >= 10)
		{
			sum[i] -= 10;
			sum[i + 1] ++;
		}
	}
}

void OBJ Draw()
{
	OBJ WriteSavedValue();

	OBJ WriteInputValue();

	OBJ WriteBar();

	OBJ WriteSumValue();

	cout << endl << endl;
}

void OBJ WriteSavedValue()
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

void OBJ WriteInputValue()
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

void OBJ WriteBar()
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

void OBJ WriteSumValue()
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
		cout << sum[i];
	}

	/*for (int i = 0; i < 50; i++)
	{
		savedValue[i] = sum[i];
		savedDegit = sumDegit;
	}*/
}