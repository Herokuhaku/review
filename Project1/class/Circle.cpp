#include <DxLib.h>
#include <utility>
#include "Circle.h"

Circle::Circle(Float2&& pos, int&& size):Shape(std::move(pos))
{
	pos_ = pos;
	size_ = size;
}

Circle::~Circle()
{
}

void Circle::Update(double delta)
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