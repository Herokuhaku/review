#include <DxLib.h>
#include "Shape.h"

Shape::Shape(Float2&& pos, int num, HitCircle& hit):pos_(pos),mynumber_(num),Allhit_(hit)
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
	return false;
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
	hit_.resize(1);
	color_ = 0xffffff;
}
