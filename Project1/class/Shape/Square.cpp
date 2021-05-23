#include <DxLib.h>
#include <utility>
#include <math.h>
#include "Square.h"

void Square::Draw(void)
{
	DrawBox(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
		static_cast<int>(pos_.x + size_.x), static_cast<int>(pos_.y + size_.y), color_,true);
	HitPair hit_box(Float2(pos_.x + size_.x/2,pos_.y + size_.y/2),size_.x/2);

	hit_.emplace_back(hit_box);
}

void Square::Draw(float num)
{
	DrawBox(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
		static_cast<int>((pos_.x + (size_.x * num))), static_cast<int>((pos_.y + (size_.y * num))),color_, true);
	HitPair hit_box(Float2(pos_.x + (size_.x * num) / 2, pos_.y + (size_.y * num) / 2), (size_.x * num) / 2);
	hit_.emplace_back(hit_box);
}
void Square::Draw(Float2 offset,float num)
{
	Float2 off = offset * num;
	Float2 size = (size_ * num);
	DrawCircle(static_cast<int>(pos_.x + offset.x), static_cast<int>(pos_.y + offset.y),2,0xff,true);

	DrawBox(static_cast<int>(pos_.x -size.x/2 + offset.x), static_cast<int>(pos_.y - size.y/2 + offset.y),
		static_cast<int>(pos_.x + (size.x/2) + offset.x), static_cast<int>(pos_.y +(size.y/2) + offset.y), 0x00FF00,false);
	HitPair hit_box(Float2(pos_.x + (size_.x / 2)+ offset.x, pos_.y + (size_.y / 2)+offset.y),(size_.x*num)/2);
	hit_.emplace_back(hit_box);
}

void Square::Init(void)
{
	stype_ = ShapeType::Square;
	if (mynumber_ % 2 == 0) {
		reverse_.first = true;
		reverse_.second = true;
		color_ = 0xffffff;
	}
	smoothsize_ = 1;
}
Square::Square(Float2&& pos, Float2&& vec, Float2&& size,int mynum):Shape(std::move(pos), vec, mynum)
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
	//reverse_.first ? pos_.x += delta * 100:pos_.x -= delta * 100;
	pos_ += (vec_ * delta);

	if (HitCheck(shapes).second)
	{
		smooth_ = std::pair<double,bool>(change_["MAG"].first,true);
		change_["MAG"].second = true;
		color_ = rand() % 0x777777 + 0x123456;
	}
	Shape::ChangeDrawSize(plusmag_);
}