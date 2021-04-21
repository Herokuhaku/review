#include <DxLib.h>
#include "class/Shape.h"
#include "class/Square.h"

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
	// Square‚ÌDraw‚ð•`‰æ‚·‚é
	Square *shape1 = new Square(Vector2(0, 0), Vector2(50, 50));
	// Shape‚ÌDraw‚ð•`‰æ‚·‚é
	Shape * shape2 = new Shape(Vector2(100,100),Vector2(50, 50));
	Square* shape3 = new Square(Vector2(200,200), Vector2(50, 50));

	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();

		(*shape1).Draw();
		(*shape2).Draw();

		(*shape3).Shape::Draw();
		
		ScreenFlip();
	}
	delete shape1;
	return 1;
}