#include <DxLib.h>
#include "Shape.h"

Shape::Shape(Float2&& pos, int& num):pos_(pos),mynumber_(num)
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

void Shape::Init(void)
{
	stype_ = ShapeType::NON;
}
