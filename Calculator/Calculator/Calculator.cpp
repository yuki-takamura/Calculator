#include <iostream>
#include <string>
#include "Calculator.h"

#define OBJ Calculator:: 
#define END_STRING "0"
#define INITIALIZE_STRING "000"
#define TAB 4

using namespace std;

void OBJ Initialize()
{
	hasError = false;
	subtraction = false;
	savedDigit = 1;
	for (int i = 0; i < MAX_DIGIT; i++)
	{
		savedValue[i] = 0;
		sum[i] = 0;
	}
}

///<summary>
/// ���͂��擾
///</summary>
void OBJ Input()
{
	cout << "   " << END_STRING << " : �I��" << endl;
	cout << " "<< INITIALIZE_STRING <<" : ������" << endl;
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
		cout << " ���܂ł̍��v�� ";
		for (int i = savedDigit - 1; i >= 0; i--)
		{
			cout << savedValue[i];
		}
		cout << " �ł���" << endl;
		cout << " �I�����܂���" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

///<summary>
/// ���������邩�ǂ���
///</summary>
bool OBJ CheckInitialize()
{
	if (inputString == INITIALIZE_STRING)
	{
		cout << " ���������܂���" << endl << endl;
		OBJ Initialize();
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
		cout << MAX_DIGIT << "���𒴂��Ă��܂�" << endl;
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
		if (i == 0)
		{
			if (inputString[i] != '-')
			{
				if (inputString[i] < '0' || inputString[i] > '9')
				{
					cout << "���l����͂��Ă�������" << endl;
					return true;
				}
			}
		}
		else
		{
			if (inputString[i] < '0' || inputString[i] > '9')
			{
				cout << "���l����͂��Ă�������" << endl;
				return true;
			}
		}
	}

	return false;
}

///<summary>
/// ���͂𐔒l��
///</summary>
void OBJ SetValue()
{
	inputDigit = inputString.length();
	
	if (inputString[0] == '-')
	{
		//�������P�����炷
		for (int i = 0; i < inputDigit; i++)
		{
			if (i == MAX_DIGIT - 1)
				inputString[i] = 0;
			inputString[i] = inputString[i + 1];
		}

		//�ŏ�ʂ�-�����猅�������炷
		inputDigit--;
		subtraction = true;
	}

	for (int i = inputDigit - 1; i >= 0; i--)
	{
		inputValue[inputDigit - 1 - i] = inputString[i] - '0';
	}

	//�ŏ�ʂ�0�̂Ƃ����������炷
	if (inputValue[inputDigit - 1] == 0)
		inputDigit--;
}

void OBJ Calculate()
{
	sumDigit = 0;

	if (savedDigit >= inputDigit)
	{
		digit = savedDigit;
	}
	else
	{
		digit = inputDigit;
	}

	if (subtraction)
		OBJ CalculateSubtraction();
	else
		OBJ CalculateAddition();

	if (sumDigit > digit)
		digit = sumDigit;
}

void OBJ CalculateAddition()
{
	//�J��オ��t���O
	bool addLeftDigit = false;

	for (int i = 0; i < digit; i++)
	{
		sum[i] = savedValue[i] + inputValue[i];
		if (addLeftDigit)
		{
			sum[i] ++;
			addLeftDigit = false;
		}
		sumDigit++;

		//�J��オ��
		if (sum[i] >= 10)
		{
			sum[i] -= 10;
			addLeftDigit = true;

			//�J��オ��Ō�����������Ƃ�
			if (i + 1 == digit)
			{
				sum[i + 1] = 1;
				sumDigit++;
			}

			if (i + 1 == MAX_DIGIT)
			{
				hasError = true;
				cout << "ERROR!" << endl;
				OBJ Initialize();
			}
		}
	}
}

void OBJ CalculateSubtraction()
{
	//�J�艺����t���O
	bool subLeftDigit = false;

	for (int i = 0; i < digit; i++)
	{
		sum[i] = savedValue[i] - inputValue[i];
		if (subLeftDigit)
		{
			sum[i]--;
			subLeftDigit = false;
		}
		sumDigit++;

		//�J�艺����
		if (sum[i] < 0)
		{
			sum[i] += 10;
			subLeftDigit = true;
		}
	}

	int newSumDigit = sumDigit;

	//�ŏ�ʂ���0�������ꍇ�A�������炷
	for (int i = sumDigit - 1; i > 0; i--)
	{
		if (sum[i] != 0)
		{
			break;
		}
		
		newSumDigit--;
	}

	sumDigit = newSumDigit;
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

	for (int i = 0; i < digit - savedDigit; i++)
	{
		cout << " ";
	}

	for (int i = savedDigit - 1; i >= 0; i--)
	{
		cout << savedValue[i];
	}
}

void OBJ WriteInputValue()
{
	cout << endl;

	if (subtraction)
		cout << "  -  ";
	else
		cout << "  +  ";

	for (int i = 0; i < digit - inputDigit; i++)
	{
		cout << " ";
	}

	for (int i = inputDigit - 1; i >= 0; i--)
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

	for (int i = 0; i < digit; i++)
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

	for (int i = 0; i < digit - sumDigit; i++)
	{
		cout << " ";
	}

	for (int i = sumDigit - 1; i >= 0; i--)
	{
		cout << sum[i];
	}
}

void OBJ Reset()
{
	for (int i = 0; i < MAX_DIGIT; i++)
		savedValue[i] = sum[i];
	savedDigit = sumDigit;

	//���́��J��オ��̒l�����Z�b�g
	for (int i = 0; i < inputDigit + 1; i++)
		inputValue[i] = 0;

	//�ŏ�ʂ�0�̂Ƃ����������炷
	if (savedValue[savedDigit - 1] == 0)
		savedDigit--;

	subtraction = false;
}