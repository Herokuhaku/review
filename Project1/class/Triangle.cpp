#include <DxLib.h>
#include <utility>
#include <math.h>
#include "Triangle.h"

Triangle::Triangle(Float2&& pos,int&& size):Shape(std::move(pos))
{
	pos_ = pos;
	size_ = size;
}

Triangle::~Triangle()
{
}

void Triangle::Draw(void)
{
	float height = sqrt(3) / 2.0 * size_;
	Float2 teppen(pos_.x,pos_.y - (height/2));
    Float2 left = teppen;
    Float2 right = teppen;

    left.x -= pos_.x;
    left.y -= pos_.y;

    right.x -= pos_.x;
    right.y -= pos_.y;

    int langle = 60 * 3.141592 / 180;
    int rangle = 120 * 3.141592 / 180;
    Float2 n1;
    n1.x = cos(langle) * left.x - sin(langle) * left.y;
    n1.y = sin(langle) * left.x + cos(langle) * left.y;
    
    left.x = n1.x + pos_.x;
    left.y = n1.y + pos_.y;

    Float2 n2;
    n2.x = cos(rangle) * right.x - sin(rangle) * right.y;
    n2.y = sin(rangle) * right.x + cos(rangle) * right.y;

    right.x = n2.x + pos_.x;
    right.y = n2.y + pos_.y;

    DrawTriangle(teppen.x,teppen.y,left.x,left.y,right.x,right.y,0x00ffff,true);
}

void Triangle::Draw(float num)
{
}