#include "Calculator.h"

#define OBJ Calculator:: 

///<summary>
/// ���s
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

		//�L���ȓ��͂ł��邩���m�F
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