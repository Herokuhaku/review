#include <DxLib.h>
#include "class/Shape.h"
#include "class/Square.h"

bool SysInit()
{
	SetGraphMode(800, 800, 32);
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
	// Square‚ÌDraw‚ð•`‰æ‚·‚é
	Shape *shape1 = new Square(Vector2(400, 400), Vector2(50, 50));
	Vector2 a = {1,1};
	Vector2 b = {0,0};
	Vector2 c = {0,0};

	int k = 1;
	int j = 0;
	int l = 0; 
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();
		
		shape1->Draw();
		shape1->Draw(Vector2(0,0),3);

		DrawLine(0-1,400-1,800-1,400-1,0xff0000);
		DrawLine(400-1,0-1, 400-1, 800-1, 0xff0000);


		ScreenFlip();
	}

	delete shape1;
	return 1;
}