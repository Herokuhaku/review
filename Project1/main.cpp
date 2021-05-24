#include <DxLib.h>
#include <map>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
#include "class/Shape/Square.h"
#include "class/Shape/Circle.h"
#include "class/Shape/Triangle.h"
#include "class/Shape/Star.h"
#include "class/Shape/Heart.h"

bool SysInit()
{
	SetGraphMode(800, 800, 32);
	ChangeWindowMode(true);
	SetWindowText("1916213_ç≤ì°çOìN");
	if (DxLib_Init() == -1){
		return false;
	}
	srand((unsigned int)time(NULL));
	return true;
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	if (!SysInit()){
		return 0;
	}

	HitCircle hitcircle_;
	int shapeNum = 0;
	// SquareÇÃDrawÇï`âÊÇ∑ÇÈ
	// squareÇmake_uniqueÇ≈çÏÇÈ
	ShapeVec shapes;
	shapes.emplace_back(std::make_shared<Square>(Float2(375,375),Float2(100,50), Float2(50, 50),shapeNum++));
	shapes.emplace_back(std::make_shared<Square>(Float2(475,475),Float2(50,-100), Float2(50, 50), shapeNum++));
	shapes.emplace_back(std::make_shared<Circle>(Float2(475, 475),Float2(-75,100),25, shapeNum++));
	shapes.emplace_back(std::make_shared<Triangle>(Float2(500, 500), Float2(-120,75), 30, shapeNum++));
	shapes.emplace_back(std::make_shared<Triangle>(Float2(300, 200), Float2(50, -75), 30, shapeNum++));
	shapes.emplace_back(std::make_shared<Triangle>(Float2(200, 400), Float2(80, 25), 30, shapeNum++));
	shapes.emplace_back(std::make_shared<Star>(Float2(205, 105),Float2(-100,100) ,25,shapeNum++));
	shapes.emplace_back(std::make_shared<Star>(Float2(305, 55), Float2(87, -35), 25, shapeNum++));
	shapes.emplace_back(std::make_shared<Star>(Float2(705, 305), Float2(-55,170), 25, shapeNum++));
	shapes.emplace_back(std::make_shared<Heart>(Float2(475, 475), Float2(-100, 50), 25, shapeNum++));

	std::chrono::system_clock::time_point  start, end;
	end = std::chrono::system_clock::now();
	start = std::chrono::system_clock::now();

	
	//auto del = std::remove_if(shapes.begin(), shapes.end(), [](UniqueShape& shape) {
	//	shape->Draw();0
	//	return true;
	//	});
	//shapes.erase(del,shapes.end());
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		end = std::chrono::system_clock::now();
		double del = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000000.0; //èàóùÇ…óvÇµÇΩéûä‘ÇïbÇ…ïœä∑

		start = std::chrono::system_clock::now();

		ClearDrawScreen();
		// êÊÇ…DrawÇçÏÇ¡ÇƒìñÇΩÇËîªíËÇçÏÇÈ
		for (auto& shape : shapes)
		{
			auto ch = shape->GetChange("MAG");
			if (!ch.second) {
				shape->Draw();
			}
			else {
				shape->Draw(ch.first);
			}
		}
		// Update
		for (auto& shape : shapes)
		{
			shape->Update(del,shapes);
		}

		for (auto& shape : shapes) {
			//shape->HitDraw();
		}
		DrawLine(0-1,400-1,800-1,400-1,0xff0000);
		DrawLine(400-1,0-1, 400-1, 800-1, 0xff0000);
		
		ScreenFlip();
	}

	return 1;
}