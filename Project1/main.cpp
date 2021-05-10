#include <DxLib.h>
#include <memory>
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
	// SquareのDrawを描画する
	// squareをmake_uniqueで作る
	std::unique_ptr<Shape> shape(std::make_unique<Square>(Float2(400, 400), Float2(50, 50)));
	// new で作る
	std::unique_ptr<Shape> shape_(new Square(Float2(400,400),Float2(50,50)));
	// 既にあるやつから所有権を貰う
	std::unique_ptr<Shape> shape__(std::move(shape_));
	// 所有権渡した後に空になってるので作っとく
	shape_.reset(new Square(Float2(100, 100), Float2(50, 50)));

	std::unique_ptr<Shape> test;
	test = std::make_unique<Square>(Float2(400,400),Float2(50,50));
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();
		shape__->Draw(Float2(25, 25), 2);
		shape__->Draw();
		DrawLine(0-1,400-1,800-1,400-1,0xff0000);
		DrawLine(400-1,0-1, 400-1, 800-1, 0xff0000);
		
		ScreenFlip();
	}

	return 1;
}