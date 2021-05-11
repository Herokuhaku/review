#include <DxLib.h>
#include <memory>
#include <vector>
#include "class/Square.h"
#include "class/Circle.h"
#include "class/Triangle.h"

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
	// SquareÇÃDrawÇï`âÊÇ∑ÇÈ
	// squareÇmake_uniqueÇ≈çÏÇÈ
	std::vector<std::unique_ptr<Shape>> shape;
	shape.reserve(3);
	shape.emplace_back(std::make_unique<Square>(Float2(375,375), Float2(50, 50)));
	//shape.emplace_back(std::make_unique<Circle>(Float2(400, 400),50));
	shape.emplace_back(std::make_unique<Triangle>(Float2(400, 400), 50));

	//std::unique_ptr<Shape> shape1(std::make_unique<Square>(Float2(400, 400), Float2(50, 50)));
	//std::unique_ptr<Shape> shape2(std::make_unique<Circle>(Float2(400, 400),50));

	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();
		for (auto& sh : shape)
		{
			sh->Draw(2.0);
		}

		DrawLine(0-1,400-1,800-1,400-1,0xff0000);
		DrawLine(400-1,0-1, 400-1, 800-1, 0xff0000);
		
		ScreenFlip();
	}

	return 1;
}