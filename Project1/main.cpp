#include <DxLib.h>
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
#include "class/Square.h"
#include "class/Circle.h"
#include "class/Triangle.h"
#include "class/Star.h"

bool SysInit()
{
	SetGraphMode(800, 800, 32);
	ChangeWindowMode(true);
	SetWindowText("1916213_佐藤弘哲");
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
	std::vector<std::unique_ptr<Shape>> shapes;
	shapes.reserve(3);
	shapes.emplace_back(std::make_unique<Square>(Float2(375,375), Float2(50, 50)));
	shapes.emplace_back(std::make_unique<Circle>(Float2(400, 400),50));
	shapes.emplace_back(std::make_unique<Triangle>(Float2(400, 400), 50));
	shapes.emplace_back(std::make_unique<Star>(Float2(400, 400), 50));


	std::chrono::system_clock::time_point  start, end;
	end = std::chrono::system_clock::now();
	start = std::chrono::system_clock::now();

	
	auto del = std::remove_if(shapes.begin(), shapes.end(), [&](auto& shape) {
		return true;
		});
	shapes.erase(del,shapes.end());
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		end = std::chrono::system_clock::now();
		double del = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000000.0; //処理に要した時間を秒に変換

		start = std::chrono::system_clock::now();

		ClearDrawScreen();
		for (auto& shape : shapes)
		{
			shape->Update(del);
		}
		DrawLine(0-1,400-1,800-1,400-1,0xff0000);
		DrawLine(400-1,0-1, 400-1, 800-1, 0xff0000);
		
		ScreenFlip();
	}

	return 1;
}