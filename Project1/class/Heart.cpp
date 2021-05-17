#include <DxLib.h>
#include <utility>
#include <math.h>
#include "Heart.h"

Heart::Heart(Float2&& pos, int&& size) :Shape(std::move(pos))
{
	pos_ = pos;
	size_ = size;
	scr = MakeScreen(size_ * 2,size_*2,true);
	heart = MakeScreen(SCREEN,SCREEN,true);
}
Heart::~Heart()
{
}

void Heart::Update(float delta)
{
	Draw(2);
}

void Heart::Draw(void)
{
	SetDrawScreen(scr);
	DrawOval(size_, size_, size_ / 2, size_, 0xffffff, true);
	
	SetDrawScreen(DX_SCREEN_BACK);
	
	DrawRotaGraph(pos_.x - size_/3,pos_.y,1.0f,2.6f,scr,true);
	DrawRotaGraph(pos_.x+size_/3, pos_.y, 1.0f,-2.6f, scr, true);
	//////for (double x = -1.6; x < 1.6; x += 0.01) {
	//////	for (double y = -1.6; y < 1.6; y += 0.01) {
	//////		double Pow = pow((4 - x * x),0.1);
	//////		double Y = (sqrt(cos(1 * x)) * cos(100 * x) + sqrt(abs(x)) - 0.4) *  Pow;
	//////		point.emplace_back(Float2(100+(x *size_),100 + -(Y * size_)));
	//////	}
	//////}
	//////SetDrawScreen(scr);
	//////for (auto& p : point)
	//////{
	//////	DrawCircle(p.x,p.y,1,0xffffff);
	//////}
	//////SetDrawScreen(DX_SCREEN_BACK);
	//////DrawRotaGraph(pos_.x,pos_.y,1.0f,0,scr,true);
	//////point.clear();
}

void Heart::Draw(float num)
{
	SetDrawScreen(scr);
	DrawOval(size_, size_, size_ / 2, size_, 0xffffff, true);

	SetDrawScreen(heart);

	DrawRotaGraph(pos_.x - size_ / 3, pos_.y, 1.0f, 2.6f, scr, true);
	DrawRotaGraph(pos_.x + size_ / 3, pos_.y, 1.0f, -2.6f, scr, true);

	SetDrawScreen(DX_SCREEN_BACK);
	DrawRotaGraph(pos_.x,pos_.y,1.0f * num,0.0f,heart,true);
}