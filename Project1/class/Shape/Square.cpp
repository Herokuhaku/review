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
	}
}
Square::Square(Float2&& pos, Float2&& size,HitCircle& hit,int mynum,int& allnum):Shape(std::move(pos),mynum,hit,allnum)
{
	pos_ = pos;
	size_ = size;
	allnumber_ = &allnum;
	Init();
}

Square::~Square()
{
}

void Square::Update(float delta, ShapeVec& shapes)
{
	//reverse_.first ? pos_.x += delta * 100:pos_.x -= delta * 100;
	reverse_.first ? pos_.x += 3 : pos_.x -= 3;
	if ((pos_.x < 0 || pos_.x > SCREEN)) {
		reverse_.first = !reverse_.first;
	}
//	reverse_.second ? pos_.y += delta * 100 : pos_.y-= delta * 100;
	reverse_.second ? pos_.y += 3 : pos_.y -= 3;
	if ((pos_.y < 0 || pos_.y > SCREEN)) {
		reverse_.second = !reverse_.second;
	}

	if (HitCheck(shapes))
	{
		color_ = rand() % 0x777777 + 0x777777;
		//shapes.emplace_back(std::make_unique<Square>(Float2(475, 475), Float2(50, 50), Allhit_,*allnumber_++,*allnumber_));
	}


}