#include <DxLib.h>
#include "Circle.h"

Circle::Circle(Float2&& pos, Float2&& vec, int&& size, int mynum):Shape(std::move(pos),vec,mynum)
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
	pos_ += (vec_ * delta);

	if (HitCheck(shapes).second)
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