#include <DxLib.h>
#include "Shape.h"

//Shape::Shape(int posx, int posy, int sizex, int sizey)
//{
//	posx_ = posx;
//	posy_ = posy;
//	sizex_ = sizex;
//	sizey_ = sizey;
//}

Shape::Shape(Vector2 pos, Vector2 size)
{
	pos_ = pos;
	size_ = size;
}

Shape::~Shape()
{
}

void Shape::Draw(void)
{
	DrawBox(pos_.x,pos_.y,pos_.x + size_.x,pos_.y +size_.y,0xffaaaa,true);
}