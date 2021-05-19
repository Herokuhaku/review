#include <DxLib.h>
#include <utility>
#include "Square.h"

void Square::Draw(void)
{
	DrawBox(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
		static_cast<int>(pos_.x + size_.x), static_cast<int>(pos_.y + size_.y), 0x00FF00,true);
}

void Square::Draw(float num)
{
	DrawBox(static_cast<int>(pos_.x), static_cast<int>(pos_.y), 
		static_cast<int>((pos_.x + (size_.x * num))), static_cast<int>((pos_.y + (size_.y * num))), 0x00FF00,false);
}

void Square::Draw(Float2 offset,float num)
{
	Float2 off = offset * num;
	Float2 size = (size_ * num);
	DrawCircle(static_cast<int>(pos_.x + offset.x), static_cast<int>(pos_.y + offset.y),2,0xff,true);

	DrawBox(static_cast<int>(pos_.x -size.x/2 + offset.x), static_cast<int>(pos_.y - size.y/2 + offset.y),
		static_cast<int>(pos_.x + (size.x/2) + offset.x), static_cast<int>(pos_.y +(size.y/2) + offset.y), 0x00FF00,false);
}

bool Square::HitCheck(ShapeVec& shapes)
{
	for (auto& shape : shapes)
	{
		// ŽlŠp‚ÆŽlŠp‚Ì”»’è
	}
	return false;
}

void Square::Init(void)
{
	stype_ = ShapeType::Square;
}

Square::Square(Float2&& pos, Float2&& size, int&& mynum):Shape(std::move(pos),mynum)
{
	pos_ = pos;
	size_ = size;
	Init();
}

Square::~Square()
{
}

void Square::Update(float delta, ShapeVec& shapes)
{
	reverse_ ? pos_.x += delta * 100 : pos_.x -= delta * 100;
	if (pos_.x < 0 || pos_.x > SCREEN) {
		reverse_ = !reverse_;
	}


	Draw();
}