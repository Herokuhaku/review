#include <DxLib.h>
#include "class/Shape.h"

bool SysInit()
{
	SetGraphMode(640, 480, 32);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1){
		return false;
	}
	return true;
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	if (!SysInit()){
		return 0;
	}
	Shape shape;

	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();

		shape.Draw();
		
		ScreenFlip();
	}
	return 1;
}