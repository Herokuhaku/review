#include <DxLib.h>
#include "Circle.h"

Circle::Circle(Parameters param, int mynum):Shape(param,mynum)
{
	Init();
}

Circle::~Circle()
{
}

void Circle::Update(float delta, ShapeVec& shapes, VecInt& vecint, ParamVec& pvec)
{
	pos_ += (vec_ * delta);

	std::pair<SharedShape, bool> hitchecktmp = HitCheck(shapes);

	if (hitchecktmp.first != nullptr && hitchecktmp.second)
	{
		//Ž©•ª‚Ìˆ—
		if (size_ >= Float2(10,0)) {
			Parameters tmpparam;
			tmpparam.p = pos_;
			tmpparam.s = size_ / 2;

			pvec.emplace_back(Parameters(tmpparam.p, Float2(vec_.x, vec_.y), tmpparam.s));
			pvec.emplace_back(Parameters(tmpparam.p, Float2(vec_.x, -vec_.y), tmpparam.s));
			pvec.emplace_back(Parameters(tmpparam.p, Float2(-vec_.x, vec_.y), tmpparam.s));
			pvec.emplace_back(Parameters(tmpparam.p, Float2(-vec_.x, -vec_.y), tmpparam.s));
			vecint.emplace_back(mynumber_);
		}
		if (hitchecktmp.first->GetMynum() != mynumber_)
		{
			//hitchecktmp.first->ChangeColor();
		}
		//shapes.emplace_back(std::make_unique<Square>(Float2(475, 475), Float2(50, 50), Allhit_,*allnumber_++,*allnumber_));
	}

}

void Circle::Draw(void)
{
	DrawCircle(pos_.x,pos_.y,size_.x,color_);
	hit_.clear();
	hit_.emplace_back(HitPair(Float2(pos_.x,pos_.y),size_.x));
}

void Circle::Draw(float num)
{
	DrawCircle(pos_.x, pos_.y,size_.x * num, color_);	
	hit_.clear();
	hit_.emplace_back(HitPair(Float2(pos_.x, pos_.y), size_.x*num));
}

void Circle::Init(void)
{
	stype_ = ShapeType::Circle;
}