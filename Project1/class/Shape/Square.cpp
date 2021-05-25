#include <DxLib.h>
#include <utility>
#include <math.h>
#include "Square.h"

void Square::Draw(void)
{
	DrawBox(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
		static_cast<int>(pos_.x + size_.x), static_cast<int>(pos_.y + size_.y), color_,true);
	HitPair hit_box(Float2(pos_.x + size_.x/2,pos_.y + size_.y/2),size_.x/2);
	hit_.clear();
	hit_.emplace_back(hit_box);
}

void Square::Draw(float num)
{
	DrawBox(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
		static_cast<int>((pos_.x + (size_.x * num))), static_cast<int>((pos_.y + (size_.y * num))),color_, true);
	HitPair hit_box(Float2(pos_.x + (size_.x * num) / 2, pos_.y + (size_.y * num) / 2), (size_.x * num) / 2);
	hit_.clear();
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
	hit_.clear();
	hit_.emplace_back(hit_box);
}

void Square::Init(void)
{
	stype_ = ShapeType::Square;
	if (mynumber_ % 2 == 0) {
		reverse_.first = true;
		reverse_.second = true;
		ChangeColor();
	}
	smoothsize_ = 1;
}
Square::Square(Parameters param, int mynum):Shape(param, mynum)
{
	Init();
}

Square::~Square()
{
}

void Square::Update(float delta, ShapeVec& shapes, VecInt& vecint, ParamVec& pvec)
{
	pos_ += (vec_ * delta);
	std::pair<SharedShape, bool> hitchecktmp = HitCheck(shapes);
	if (hitchecktmp.first != nullptr && hitchecktmp.second)
	{	
		//é©ï™ÇÃèàóù
		smooth_ = std::make_pair(change_["MAG"].first,true);
		//smooth_ = std::pair<double, bool>(change_["MAG"].first, true);
		change_["MAG"].second = true;	
		hitchecktmp.first->ChangeColor();
		// é©ï™Ç∂Ç·Ç»Ç©Ç¡ÇΩÇÁêFÇïœÇ¶ÇÈ
		if (hitchecktmp.first->GetMynum() != mynumber_)
		{
			hitchecktmp.first->ChangeColor();
		}	

	}
	Shape::ChangeDrawSize(plusmag_);
}