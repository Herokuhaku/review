#include <DxLib.h>
#include "Shape.h"

Shape::Shape()
{
	Init();
}

Shape::Shape(Parameters param, int num):pos_(param.p),mynumber_(num),vec_(param.v),size_(param.s)
{
	Init();
}
Shape::~Shape()
{
}

void Shape::Draw(Float2 offset, float num)
{
}

std::pair<SharedShape&,bool> Shape::HitCheck(ShapeVec shapes)
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

void Shape::ChangeRotaFlag()
{
	change_["ROTA"].second = !change_["ROTA"].second;
}

void Shape::ChangeDrawSizeFlag()
{
}

std::pair<double, bool> Shape::GetChange(std::string str)
{
	return change_[str];
}

void Shape::ChangeDrawSize(double plus)
{
	if (change_["MAG"].first < maxmag_ && (change_["MAG"].first - smooth_.first) <= smoothsize_) {
		change_["MAG"].first += plus;
	}
}

void Shape::ChangeColor(void)
{
	color_ = rand() % 0x777777 + 0x123456;
}

void Shape::ChangeVec(float speed, Float2 max = {300,300})
{
	if (abs(vec_.x * speed) <= max.x && abs(vec_.y * speed) <= max.y) {
		vec_ = vec_ * speed;
	}
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
	color_ = (rand ()*mynumber_) % 0xffffff+0x654321;
	hitnow_ = true;
	screenhit_ = false;
	maxmag_ = 3.0f;
	plusmag_ = 0.005;

	change_.try_emplace("ROTA",0.0f,false);
	change_.try_emplace("MAG",1.0f, false);
}