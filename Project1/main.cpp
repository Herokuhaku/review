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
	SetWindowText("1916213_佐藤弘哲");
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

	// Shape
	ShapeVec shapes;
	//shapes.emplace_back(std::make_shared<Square>(Parameters(Float2(375,375),Float2(100,50), Float2(50, 50)),shapeNum++));
	shapes.emplace_back(std::make_shared<Square>(Parameters(Float2(475,475),Float2(50,-100), Float2(50, 50)), shapeNum++));
	shapes.emplace_back(std::make_shared<Circle>(Parameters(Float2(475, 475),Float2(-75,100),Float2(25,0)), shapeNum++));
	shapes.emplace_back(std::make_shared<Triangle>(Parameters(Float2(500, 500), Float2(-120,75), Float2(30, 0)), shapeNum++));
	shapes.emplace_back(std::make_shared<Triangle>(Parameters(Float2(300, 200), Float2(50, -75), Float2(30, 0)), shapeNum++));
	shapes.emplace_back(std::make_shared<Triangle>(Parameters(Float2(200, 400), Float2(80, 25), Float2(30, 0)), shapeNum++));
	shapes.emplace_back(std::make_shared<Star>(Parameters(Float2(205, 105),Float2(-100,100) , Float2(25, 0)),shapeNum++));
	shapes.emplace_back(std::make_shared<Star>(Parameters(Float2(305, 55), Float2(87, -35), Float2(25, 0)), shapeNum++));
	shapes.emplace_back(std::make_shared<Star>(Parameters(Float2(705, 305), Float2(-55,170), Float2(25, 0)), shapeNum++));
	shapes.emplace_back(std::make_shared<Heart>(Parameters(Float2(475, 475), Float2(-100, 50), Float2(25, 0)), shapeNum++));

	std::chrono::system_clock::time_point  start, end;
	end = std::chrono::system_clock::now();
	start = std::chrono::system_clock::now();
	// 消すshapeの一時保存リスト
	VecInt eraseno;
	// 追加するshapeのパラメータリスト(vector)
	ParamVec paramvec;

	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		end = std::chrono::system_clock::now();
		double del = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000000.0; //処理に要した時間を秒に変換

		start = std::chrono::system_clock::now();

		ClearDrawScreen();
		// 先にDrawを作って当たり判定を作る
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
			shape->Update(del,shapes,eraseno,paramvec);
		}

		// 当たり判定描画
		for (auto& shape : shapes)
		{
			//shape->HitDraw();
		}

		// 削除処理
		if (eraseno.size() >= 1) {
			auto deleter = std::remove_if(shapes.begin(), shapes.end(), [&](SharedShape& shape) {
				for (auto erase : eraseno) {
					if (shape->GetMynum() == erase) {
						return true;
					}
				}
				return false;
				});
			shapes.erase(deleter, shapes.end());
			eraseno.clear();
		}
		 //追加処理
		if (paramvec.size() >= 1) {
			for (auto& param : paramvec) {
				shapes.emplace_back(std::make_shared<Circle>(param,shapeNum++));
			}
			paramvec.clear();
		}
		DrawLine(0-1,400-1,800-1,400-1,0xff0000);
		DrawLine(400-1,0-1, 400-1, 800-1, 0xff0000);
		
		ScreenFlip();
	}
	if (shapes.size() >= 1) {
		shapes.clear();
	}
	return 1;
}