#include <DxLib.h>
#include <utility>
#include "Square.h"

void Square::Draw(void)
{
	DrawBox(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
		static_cast<int>(pos_.x + size_.x), static_cast<int>(pos_.y + size_.y), 0xffffff,true);
}

void Square::Draw(float num)
{
	DrawBox(static_cast<int>(pos_.x), static_cast<int>(pos_.y), 
		static_cast<int>((pos_.x + (size_.x * num))), static_cast<int>((pos_.y + (size_.y * num))), 0xffffff,false);
}

void Square::Draw(Float2 offset,float num)
{
	Float2 off = offset * num;
	Float2 size = (size_ * num);
	DrawCircle(static_cast<int>(pos_.x + offset.x), static_cast<int>(pos_.y + offset.y),2,0xff,true);

	DrawBox(static_cast<int>(pos_.x -size.x/2 + offset.x), static_cast<int>(pos_.y - size.y/2 + offset.y),
		static_cast<int>(pos_.x + (size.x/2) + offset.x), static_cast<int>(pos_.y +(size.y/2) + offset.y), 0xff00ff,false);
}

Square::Square(Float2&& pos, Float2&& size):Shape(std::move(pos),std::move(size))
{
	pos_ = pos;
	size_ = size;
}