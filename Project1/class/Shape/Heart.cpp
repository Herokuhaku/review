#include <DxLib.h>
#include <utility>
#include <math.h>
#include "Heart.h"

Heart::Heart(Float2&& pos, int&& size,int&& mynum) :Shape(std::move(pos),mynum)
{
	pos_ = pos;
	size_ = size;
	Init();
}
Heart::~Heart()
{
}

void Heart::Update(float delta, ShapeVec& shapes)
{
	reverse_ ? pos_.x += delta * 100: pos_.x -= delta * 100;
	if (pos_.x < 0 || pos_.x > SCREEN) {
		reverse_ = !reverse_;
	}
	Draw();
}

void Heart::Draw(void)
{
	SetDrawScreen(scr_);
	ClsDrawScreen();
	DrawOval(size_, size_, size_ / 2, size_, 0xffffff, true);
	
	SetDrawScreen(DX_SCREEN_BACK);
	
	DrawRotaGraph(pos_.x - size_/3,pos_.y,1.0f,2.6f,scr_,true);
	DrawRotaGraph(pos_.x+size_/3, pos_.y, 1.0f,-2.6f, scr_, true);

	//////for (double x = -1.6; x < 1.6; x += 0.01) {
	//////	for (double y = -1.6; y < 1.6; y += 0.01) {
	//////		double Pow = pow((4 - x * x),0.1);
	//////		double Y = (sqrt(cos(1 * x)) * cos(100 * x) + sqrt(abs(x)) - 0.4) *  Pow;
	//////		point.emplace_back(Float2(100+(x *size_),100 + -(Y * size_)));
	//////	}
	//////}
	//////SetDrawScreen(scr);
	//for (int p = 1000; p < point.size() -1000; p++)
	//{
	//	DrawLine(point[p].x,point[p].y, point[p+1].x, point[p+1].y,0xffffff);
	//}
	//////SetDrawScreen(DX_SCREEN_BACK);
	//////DrawRotaGraph(pos_.x,pos_.y,1.0f,0,scr,true);
	//////point.clear();
}

void Heart::Draw(float num)
{
	SetDrawScreen(scr_);
	ClsDrawScreen();
	DrawOval(size_, size_, size_ / 2, size_, 0xffffff, true);

	SetDrawScreen(heart_);
	ClsDrawScreen();

	DrawRotaGraph(pos_.x - size_ / 3, pos_.y, 1.0f, 2.6f, scr_, true);
	DrawRotaGraph(pos_.x + size_ / 3, pos_.y, 1.0f, -2.6f, scr_, true);

	SetDrawScreen(DX_SCREEN_BACK);
	DrawRotaGraph(pos_.x,pos_.y,1.0f * num,0.0f,heart_,true);
}

void Heart::Init(void)
{
	stype_ = ShapeType::Heart;
	scr_ = MakeScreen(size_ * 2, size_ * 2, true);
	heart_ = MakeScreen(SCREEN, SCREEN, true);
	reverse_ = false;
}
