#include "Calculator.h"

#define OBJ Calculator:: 

///<summary>
/// 実行
///</summary>
void OBJ Run()
{
	OBJ Initialize();

	while (1)
	{
		OBJ Input();

		if (OBJ CheckEnd())
			break;
		if (OBJ CheckInitialize())
			continue;

		//有効な入力であるかを確認
		if (OBJ CheckOverString())
			continue;
		if (OBJ HasString())
			continue;

		OBJ SetValue();

		OBJ Calculate();

		if (hasError)
			continue;

		OBJ Draw();

		OBJ Reset();
	}
}