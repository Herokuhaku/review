#include <DxLib.h>
#include <utility>
#include <math.h>
#include <vector>
#include "Triangle.h"

Triangle::Triangle(Float2&& pos, Float2&& vec, int&& size, int mynum):Shape(std::move(pos), vec, mynum)
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
    pos_ += (vec_ * delta);
    if (HitCheck(shapes).second)
    {
        
    }
    if (change_["ROTA"].second)
    {
        change_["ROTA"].first--;
    }
}

void Triangle::Draw(void)
{
	height_ = static_cast<float>(sqrt(3) / 2.0 * size_);
    for (int i = 0; i < 3; i++)
    {
        point[i] = Float2(pos_.x, pos_.y-height_);
    }
    for (int i = 0; i < 3; i++)
    {
        angle_ = (i * static_cast<double>(120.0) + change_["ROTA"].first) * 3.141592 / 180;

        point[i] -= pos_;

        Float2 n;
        n.x = (std::cos(angle_) * point[i].x) + (std::sin(angle_) * point[i].y);
        n.y = (-std::sin(angle_) * point[i].x) + (std::cos(angle_) * point[i].y);

        point[i] = pos_ + n;
    }
    DrawTriangle(point[0].x,point[0].y,point[1].x,point[1].y,point[2].x,point[2].y,color_,false);
    DrawCircle(pos_.x, pos_.y,2, 0xffffff);
    hit_.clear();
    hit_.emplace_back(Float2(pos_.x - (pos_.x - point[0].x)/2,pos_.y - (pos_.y - point[0].y) / 2), size_ / 2.75);
    hit_.emplace_back(Float2(pos_.x - (pos_.x - point[1].x) / 2, pos_.y - (pos_.y - point[1].y) / 2), size_ / 2.75);
    hit_.emplace_back(Float2(pos_.x - (pos_.x - point[2].x) / 2, pos_.y - (pos_.y - point[2].y) / 2), size_ / 2.75);
    //hit_.emplace_back(Float2(pos_.x, pos_.y), size_ / 3);
    //hit_.emplace_back(Float2(pos_.x, pos_.y), size_ / 3);
}

void Triangle::Draw(float num)
{
    height_ = static_cast<float>(sqrt(3) / 2.0 * size_*num);

    for (int i = 0; i < 3; i++)
    {
        point[i] = Float2(pos_.x, pos_.y - height_);
    }
    for (int i = 0; i < 3; i++)
    {
        angle_ = (i * static_cast<double>(120.0) + change_["ROTA"].first) * 3.141592 / 180;

        point[i] -= pos_;

        Float2 n;
        n.x = (std::cos(angle_) * point[i].x) + (std::sin(angle_) * point[i].y);
        n.y = (-std::sin(angle_) * point[i].x) + (std::cos(angle_) * point[i].y);

        point[i] = pos_ + n;
    }
    DrawTriangle(point[0].x, point[0].y, point[1].x, point[1].y, point[2].x, point[2].y,color_, false);

    hit_.clear();
    hit_.emplace_back(Float2(pos_.x + (pos_.x - point[0].x) / 2, pos_.y - (pos_.y - point[0].y) / 2), (size_*num) / 3);
    hit_.emplace_back(Float2(pos_.x + (pos_.x - point[1].x) / 2, pos_.y - (pos_.y - point[1].y) / 2), (size_ * num) / 3);
    hit_.emplace_back(Float2(pos_.x + (pos_.x - point[2].x) / 2, pos_.y - (pos_.y - point[2].y) / 2), (size_ * num) / 3);
}

void Triangle::Init(void)
{
    stype_ = ShapeType::Triangle;
    point.resize(3);
}
