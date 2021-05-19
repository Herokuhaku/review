#include <DxLib.h>
#include "Circle.h"

Circle::Circle(Float2&& pos, int&& size, int&& mynum):Shape(std::move(pos),mynum)
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
	Draw();
}

void Circle::Draw(void)
{
	DrawCircle(pos_.x,pos_.y,size_,0x0000FF);
}

void Circle::Draw(float num)
{
	DrawCircle(pos_.x, pos_.y,size_ * num, 0x0000FF);
}

void Circle::Init(void)
{
	stype_ = ShapeType::Circle;
}