#include <DxLib.h>
#include "Shape.h"

Shape::Shape(Float2&& pos, int num, HitCircle& hit, int& allnum):pos_(pos),mynumber_(num),Allhit_(hit)
{
	Init();
}
Shape::~Shape()
{
}

void Shape::Draw(Float2 offset, float num)
{
}

bool Shape::HitCheck(ShapeVec& shapes)
{
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
						hitnow_ = true;
						rtnflag_ = true;
					}
				}
			}
		}
	}
	// “–‚½‚Á‚Ä‚¢‚é”»’è‚Å‚Í‚ ‚é‚¯‚Ç1‚Â‚É‚à“–‚½‚Á‚Ä‚¢‚È‚¢ê‡‚É
	// “–‚½‚Á‚Ä‚¢‚È‚¢”»’è‚É–ß‚·
	if (hitnow_ && !otherflag) {
	hitnow_ = false;
	}
	return rtnflag_;
}

void Shape::HitDraw(void)
{
	for (auto& hit : hit_)
	{
		DrawCircle(hit.first.x, hit.first.y,hit.second,0xffffff);
	}
}

void Shape::ClearHitCheck(void)
{
	hit_.clear();
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
	Allhit_.try_emplace(mynumber_);
	color_ = 0xffffff;
	hitnow_ = false;
}
