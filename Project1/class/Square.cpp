#include <DxLib.h>
#include "Square.h"

void Square::Draw(void)
{
	DrawBox(pos_.x, pos_.y, pos_.x + size_.x, pos_.y + size_.y, 0xffffff,true);
}

void Square::Draw(float num)
{
	DrawBox(pos_.x, pos_.y, (pos_.x + (size_.x * num)), (pos_.y + (size_.y * num)), 0xffffff, false);
}

void Square::Draw(Vector2 offset,float num)
{
	Vector2 off = offset * num;
	Vector2 size = (size_ * num);
	DrawCircle(pos_.x + offset.x,pos_.y + offset.y,5,0xff,true);

	DrawBox(pos_.x + offset.x - off.x-size.x/2, pos_.y + offset.y - off.y - size.y/2,
		pos_.x + (size.x/2) + offset.x + off.x, pos_.y + (size.y/2) + offset.y + off.y, 0xff00ff, false);

	//DrawBox(pos_.x - offset.x, pos_.y - offset.y, pos_.x + offset.x, pos_.y + offset.y, 0xffffff, true);
}

Square::Square(Vector2 pos,Vector2 size):Shape(pos,size)
{
	pos_ = pos;
	size_ = size;
}