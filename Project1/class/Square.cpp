#include <DxLib.h>
#include "Square.h"

void Square::Draw(void)
{
	DrawBox(pos_.x, pos_.y, pos_.x + size_.x, pos_.y + size_.y, 0xffffff, true);
}

Square::Square(Vector2 pos,Vector2 size):Shape(pos,size)
{
	pos_ = pos;
	size_ = size;
}