#include <DxLib.h>
#include "Shape.h"

Shape::Shape()
{
	posx_ = 300;
	posy_ = 200;
	sizex_ = 100;
	sizey_ = 100;
}

Shape::~Shape()
{
}

void Shape::Draw(void)
{
	DrawBox(posx_,posy_,posx_ + sizex_,posy_ +sizey_, 0xffffff,true);
}
