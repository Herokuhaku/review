#include <DxLib.h>
#include <utility>
#include <math.h>
#include "Heart.h"

Heart::Heart(Parameters param, int mynum) :Shape(param,mynum)
{
	Init();
}
Heart::~Heart()
{
}

void Heart::Update(float delta, ShapeVec& shapes, VecInt& vecint, ParamVec& pvec)
{
	pos_ += (vec_ * delta);
	HitCheck(shapes);
}

void Heart::Draw(void)
{
	//SetDrawScreen(scr_);
	//ClsDrawScreen();
	//DrawOval(size_, size_, size_ / 2, size_, 0xffffff, true);
	//
	//SetDrawScreen(DX_SCREEN_BACK);
	//
	//DrawRotaGraph(pos_.x - size_/3,pos_.y,1.0f,2.6f,scr_,true);
	//DrawRotaGraph(pos_.x+size_/3, pos_.y, 1.0f,-2.6f, scr_, true);

	DrawRotaGraph(pos_.x, pos_.y, 1.0f, 0,heartsave_, true);
	DrawCircle(pos_.x , pos_.y,2,0xff0000);
	hit_.clear();
	hit_.emplace_back(HitPair(Float2(pos_.x, pos_.y), size_.x));
}

void Heart::Draw(float num)
{
	DrawRotaGraph(pos_.x, pos_.y, 1.0f * num, 0, heartsave_, true);
	DrawCircle(pos_.x, pos_.y, 2, 0xff0000);
	hit_.clear();
	hit_.emplace_back(HitPair(Float2(pos_.x, pos_.y), size_.x));
}

void Heart::Init(void)
{
	stype_ = ShapeType::Heart;
	heartsave_ = MakeScreen(size_.x * 4,size_.x * 4,true);
	reverse_ = false;

	for (double x = -1.6; x < 1.6; x += 0.01) {
		for (double y = -1.6; y < 1.6; y += 0.01) {
			double Pow = pow((4 - x * x),0.1);
			double Y = (sqrt(cos(1 * x)) * cos(100 * x) + sqrt(abs(x)) - 0.4) *  Pow;
			point.emplace_back(Float2((x *size_.x) + size_.x*2,-(Y * size_.x) + size_.x*2));
		}
	}
	SetDrawScreen(heartsave_);
	for (int p = 1000; p < point.size() -1000; p++)
	{
		DrawLine(point[p].x,point[p].y, point[p+1].x, point[p+1].y,0xbb0000);
	}
	SetDrawScreen(DX_SCREEN_BACK);
	point.clear();
}
