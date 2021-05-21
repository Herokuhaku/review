#include <DxLib.h>
#include "Shape.h"

Shape::Shape(Float2&& pos, Float2& vec, int num):pos_(pos),mynumber_(num),vec_(vec)
{
	Init();
}
Shape::~Shape()
{
}

void Shape::Draw(Float2 offset, float num)
{
}

std::pair<SharedShape&,bool> Shape::HitCheck(ShapeVec& shapes)
{
	SharedShape hitshape;
	screenhit_ = false;
	otherflag = false;
	bool rtnflag_ = false;
	Float2 circle(0, 0);
	float val = 0;
	for (auto& shape : shapes)
	{
		if (shape->GetMynum() != mynumber_){
			for (auto myhit : hit_)
			{
				for (auto hit : shape->GetHitPairVec())
				{
					circle = myhit.first - hit.first;
					val = sqrt((circle.x * circle.x) + (circle.y * circle.y));
					bool flag = (val <= (myhit.second + hit.second));
					if (flag) {
						otherflag = true;
					}
					if (flag && !hitnow_)
					{
						hitshape = shape;
						hitnow_ = true;
						rtnflag_ = true;
					}
				}
			}
		}
	}
	for (auto& hit : hit_)
	{
		if (!allscreenhit_) {
			if (hit.first.x <= hit.second) {
				vec_.x = -vec_.x;
				allscreenhit_ = true;
				hitnow_ = true;
				otherflag = true;
				rtnflag_ = true;
			}
			if (SCREEN - hit.first.x <= hit.second)
			{
				vec_.x = -vec_.x;
				allscreenhit_ = true;
				hitnow_ = true;
				otherflag = true;
				rtnflag_ = true;
			}
			else if (hit.first.y <= hit.second) {
				vec_.y = -vec_.y;
				allscreenhit_ = true;
				hitnow_ = true;
				otherflag = true;
				rtnflag_ = true;
			}
			if (SCREEN - hit.first.y <= hit.second)
			{
				vec_.y = -vec_.y;
				allscreenhit_ = true;
				hitnow_ = true;
				otherflag = true;
				rtnflag_ = true;
			}
		}
	}
	for (auto& hit : hit_)
	{
		if(!(!(hit.first.x <= hit.second) && !(SCREEN - hit.first.x <= hit.second) && !(hit.first.y <= hit.second) && !(SCREEN - hit.first.y <= hit.second)))
		{
			screenhit_ = true;
		}
	}
	if (!screenhit_) {
		allscreenhit_ = false;
	}
	// “–‚½‚Á‚Ä‚¢‚é”»’è‚Å‚Í‚ ‚é‚¯‚Ç1‚Â‚É‚à“–‚½‚Á‚Ä‚¢‚È‚¢ê‡‚É
	// “–‚½‚Á‚Ä‚¢‚È‚¢”»’è‚É–ß‚·
	if (hitnow_ && !otherflag) {
		hitnow_ = false;
	}
	return std::pair<SharedShape&,bool>(hitshape,rtnflag_);
}

void Shape::HitDraw(void)
{
	for (auto& hit : hit_)
	{
		DrawCircle(hit.first.x, hit.first.y,hit.second,0xffffff,false);
	}
}

void Shape::ClearHitCheck(void)
{
	hit_.clear();
}

void Shape::SetRotaFlag_()
{
	rotaflag_ = !rotaflag_;
}

ShapeType Shape::GetType(void)
{
	return stype_;
}

HitPairVec Shape::GetHitPairVec(void)
{
	return hit_;
}

int Shape::GetMynum(void)
{
	return mynumber_;
}

void Shape::Init(void)
{
	stype_ = ShapeType::NON;
	color_ = (rand ()*mynumber_) % 0xffffff;
	hitnow_ = false;
	screenhit_ = false;
}