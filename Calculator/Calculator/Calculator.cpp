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
/// 入力を取得
///</summary>
void OBJ Input()
{
	cout << "   " << END_STRING << " : 終了" << endl;
	cout << " "<< INITIALIZE_STRING <<" : 初期化" << endl;
	cout << " 入力 --＞ ";

	cin >> inputString;
}

///<summary>
/// 終了するかどうか
///</summary>
bool OBJ CheckEnd()
{
	if (inputString == END_STRING)
	{
		cout << " 今までの合計は ";
		for (int i = savedDigit - 1; i >= 0; i--)
		{
			cout << savedValue[i];
		}
		cout << " でした" << endl;
		cout << " 終了しました" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

///<summary>
/// 初期化するかどうか
///</summary>
bool OBJ CheckInitialize()
{
	if (inputString == INITIALIZE_STRING)
	{
		cout << " 初期化しました" << endl << endl;
		OBJ Initialize();
		return true;
	}
	else
	{
		return false;
	}
}

///<summary>
/// 入力制限を行う
///</summary>
bool OBJ CheckOverString()
{
	if (inputString.length() > MAX_DIGIT)
	{
		cout << MAX_DIGIT << "桁を超えています" << endl;
		cout << MAX_DIGIT << "桁以内で入力してください" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

///<summary>
/// 数値以外の入力があるか
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
					cout << "数値を入力してください" << endl;
					return true;
				}
			}
		}
		else
		{
			if (inputString[i] < '0' || inputString[i] > '9')
			{
				cout << "数値を入力してください" << endl;
				return true;
			}
		}
	}

	return false;
}

///<summary>
/// 入力を数値化
///</summary>
void OBJ SetValue()
{
	inputDigit = inputString.length();
	
	if (inputString[0] == '-')
	{
		//符号分１桁ずらす
		for (int i = 0; i < inputDigit; i++)
		{
			if (i == MAX_DIGIT - 1)
				inputString[i] = 0;
			inputString[i] = inputString[i + 1];
		}

		//最上位が-だから桁数を減らす
		inputDigit--;
		subtraction = true;
	}

	for (int i = inputDigit - 1; i >= 0; i--)
	{
		inputValue[inputDigit - 1 - i] = inputString[i] - '0';
	}

	//最上位が0のとき桁数を減らす
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
	//繰り上がりフラグ
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

		//繰り上がり
		if (sum[i] >= 10)
		{
			sum[i] -= 10;
			addLeftDigit = true;

			//繰り上がりで桁数が増えるとき
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
	//繰り下がりフラグ
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

		//繰り下がり
		if (sum[i] < 0)
		{
			sum[i] += 10;
			subLeftDigit = true;
		}
	}

	int newSumDigit = sumDigit;

	//最上位から0が続く場合、桁を減らす
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

	//入力＆繰り上がりの値をリセット
	for (int i = 0; i < inputDigit + 1; i++)
		inputValue[i] = 0;

	//最上位が0のとき桁数を減らす
	if (savedValue[savedDigit - 1] == 0)
		savedDigit--;

	subtraction = false;
}