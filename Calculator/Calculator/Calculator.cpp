#include <iostream>
#include <string>
#include "Calculator.h"

#define END_STRING "0"

using namespace std;

///<summary>
/// 実行
///</summary>
void Calculator :: Run()
{
	savedDegit = 1;

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

///<summary>
/// 入力を取得
///</summary>
void Calculator :: Input()
{
	cout << " 入力 --＞ ";

	cin >> inputString;
}

///<summary>
/// 終了するかどうか
///</summary>
bool Calculator::CheckEnd()
{
	if (inputString == END_STRING)
	{
		cout << "終了しました" << endl;
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

///<summary>
/// 数値以外の入力があるか
///</summary>
bool Calculator::HasString()
{
	for (unsigned int i = 0; i < inputString.length(); i++)
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

	//足される値-----------------------------------
	cout << endl;
	cout << " ";
	for (int i = 0; i < 4; i++)
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

	//足す値--------------------------------------
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

	//イコール------------------------------------
	cout << endl;
	cout << " ";
	for (int i = 0; i < 4; i++)
	{
		cout << "-";
	}

	for (int i = 0; i < degit; i++)
	{
		cout << "-";
	}

	//合計値-------------------------------------
	cout << endl;
	cout << " ";
	for (int i = 0; i < 4; i++)
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

	cout << endl << endl;
}