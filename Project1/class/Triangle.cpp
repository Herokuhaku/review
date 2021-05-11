#include <DxLib.h>
#include <utility>
#include <math.h>
#include <vector>
#include "Triangle.h"

Triangle::Triangle(Float2&& pos,int&& size):Shape(std::move(pos))
{
	pos_ = pos;
	size_ = size;
}

Triangle::~Triangle()
{
}

void Triangle::Update(float delta)
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
    std::vector<Float2> point;
    point.resize(3);

	float height = sqrt(3) / 2.0 * size_;
    int angle = 120 * 3.141592 / 180;

    for (int i = 0; i < 3; i++)
    {
        point[i] = Float2(pos_.x, pos_.y - (height));
    }
    for (int i = 1; i < 3; i++)
    {
        i == 1 ? angle = angle :angle = -angle;

        point[i].x -= pos_.x;
        point[i].y -= pos_.y;

        Float2 n;
        n.x = cos(angle) * point[i].x - sin(angle) * point[i].y;
        n.y = sin(angle) * point[i].x + cos(angle) * point[i].y;

        point[i].x = n.x + pos_.x;
        point[i].y = n.y + pos_.y;
    }

    DrawTriangle(point[0].x,point[0].y,point[1].x,point[1].y,point[2].x,point[2].y,0xff00ff,false);
}

void Triangle::Draw(float num)
{
    std::vector<Float2> point;
    point.resize(3);

    float height = sqrt(3) / 2.0 * (size_*num);
    int angle = 120 * 3.141592 / 180;

    for (int i = 0; i < 3; i++)
    {
        point[i] = Float2(pos_.x, pos_.y - (height));
    }
    for (int i = 1; i < 3; i++)
    {
        i == 1 ? angle = angle : angle = -angle;

        point[i].x -= pos_.x;
        point[i].y -= pos_.y;

        Float2 n;
        n.x = cos(angle) * point[i].x - sin(angle) * point[i].y;
        n.y = sin(angle) * point[i].x + cos(angle) * point[i].y;

        point[i].x = n.x + pos_.x;
        point[i].y = n.y + pos_.y;
    }

    DrawTriangle(point[0].x, point[0].y, point[1].x, point[1].y, point[2].x, point[2].y, 0xff00ff,false);
}