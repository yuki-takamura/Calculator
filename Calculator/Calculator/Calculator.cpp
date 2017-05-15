#include <iostream>
#include <string>
#include "Calculator.h"

#define OBJ Calculator:: 
#define END_STRING "0"
#define TAB 4

using namespace std;

///<summary>
/// 実行
///</summary>
void OBJ Run()
{
	savedDegit = 1;

	for(;;)
	{
		OBJ Input();

		//有効な入力であるかを確認
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
/// 入力を取得
///</summary>
void OBJ Input()
{
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
bool OBJ CheckOverString()
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
bool OBJ HasString()
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