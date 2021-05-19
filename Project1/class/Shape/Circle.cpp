#include <DxLib.h>
#include "Circle.h"

Circle::Circle(Float2&& pos, int&& size, HitCircle& hit, int mynum, int& allnum):Shape(std::move(pos),mynum, hit,allnum)
{
	pos_ = pos;
	size_ = size;
	Init();
}

Circle::~Circle()
{
}

void Circle::Update(float delta, ShapeVec& shapes)
{
	pos_.x += (delta * 100);
	pos_.y += (delta * 100);
	if (pos_.y > SCREEN + size_ && pos_.x > SCREEN)
	{
		pos_.y = -size_;
		pos_.x = -size_;
	}
	if (HitCheck(shapes))
	{
		color_ = rand() % 0x777777 + 0x777777;
		//shapes.emplace_back(std::make_unique<Square>(Float2(475, 475), Float2(50, 50), Allhit_,*allnumber_++,*allnumber_));
	}

}

void Circle::Draw(void)
{
	DrawCircle(pos_.x,pos_.y,size_,color_);
	hit_.emplace_back(HitPair(Float2(pos_.x,pos_.y),size_));
}

void Circle::Draw(float num)
{
	DrawCircle(pos_.x, pos_.y,size_ * num, color_);
	hit_.emplace_back(HitPair(Float2(pos_.x, pos_.y), size_*num));
}

void Circle::Init(void)
{
	stype_ = ShapeType::Circle;
}