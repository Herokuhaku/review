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

void Circle::Draw(void)
{
	DrawCircle(pos_.x,pos_.y,size_,0x0000FF);
}

void Circle::Draw(float num)
{
	DrawCircle(pos_.x, pos_.y,size_ * num, 0x0000FF);
}