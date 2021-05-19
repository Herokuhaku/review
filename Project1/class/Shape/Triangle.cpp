#include <DxLib.h>
#include <utility>
#include <math.h>
#include <vector>
#include "Triangle.h"

Triangle::Triangle(Float2&& pos,int&& size, HitCircle& hit, int mynum, int& allnum):Shape(std::move(pos),mynum, hit,allnum)
{
	pos_ = pos;
	size_ = size;
    Init();
}

Triangle::~Triangle()
{
}

void Triangle::Update(float delta, ShapeVec& shapes)
{
    pos_.y += (delta * 100);
    if (pos_.y  > SCREEN + size_)
    {
        pos_.y = -size_;
    }
    Draw();
}

void Triangle::Draw(void)
{
	height_ = static_cast<float>(sqrt(3) / 2.0 * size_);

    for (int i = 0; i < 3; i++)
    {
        point[i] = Float2(pos_.x, pos_.y-height_);
    }
    for (int i = 1; i < 3; i++)
    {
        angle_ = (120.0 * i) * 3.141592 / 180;

        point[i] -= pos_;

        Float2 n;
        n.x = cos(angle_) * point[i].x + sin(angle_) * point[i].y;
        n.y = -sin(angle_) * point[i].x + cos(angle_) * point[i].y;

        point[i] = n + pos_;
    }
    DrawTriangle(point[0].x,point[0].y,point[1].x,point[1].y,point[2].x,point[2].y,0xff00ff,false);
    DrawCircle(pos_.x, pos_.y,2, 0xffffff);

}

void Triangle::Draw(float num)
{
    height_ = static_cast<float>(sqrt(3) / 2.0 * size_*num);

    for (int i = 0; i < 3; i++)
    {
        point[i] = Float2(pos_.x, pos_.y - height_);
    }
    for (int i = 1; i < 3; i++)
    {
        angle_ = (120.0 * i) * 3.141592 / 180;

        point[i] -= pos_;

        Float2 n;
        n.x = cos(angle_) * point[i].x + sin(angle_) * point[i].y;
        n.y = -sin(angle_) * point[i].x + cos(angle_) * point[i].y;

        point[i] = n + pos_;
    }
    DrawTriangle(point[0].x, point[0].y, point[1].x, point[1].y, point[2].x, point[2].y, 0xff00ff, false);
    DrawCircle(pos_.x, pos_.y, 50, 0xffffff, false);
    DrawCircle(pos_.x, pos_.y, 2, 0xffffff);
}

void Triangle::Init(void)
{
    stype_ = ShapeType::Triangle;
    point.resize(3);
}
