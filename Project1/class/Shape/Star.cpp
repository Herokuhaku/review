#include <DxLib.h>
#include <cmath>
#include <utility>
#include <vector>
#include "Star.h"

Star::Star(Parameters param, int mynum):Shape(param,mynum)
{
    Init();
}

Star::~Star()
{
}

void Star::Update(float delta, ShapeVec& shapes, VecInt& vecint, ParamVec& pvec)
{
    pos_ += (vec_ * delta);
    std::pair<SharedShape, bool> hitchecktmp = HitCheck(shapes);
    if (hitchecktmp.second)
    {
        // �O�p�������瑊�����]������
        if (hitchecktmp.first != nullptr && hitchecktmp.first->GetType() == ShapeType::Triangle) {
            hitchecktmp.first->ChangeRotaFlag();
        }
        // ��������]������
        //rotaflag_ = !rotaflag_;
        change_["ROTA"].second = !change_["ROTA"].second;
    }
    //if (rotaflag_) {
    //    rota_++;
    //}
    if (change_["ROTA"].second)
    {
        change_["ROTA"].first++;
    }
}

void Star::Draw(void)
{
    for (int i = 0; i < 5; i++)
    {
        point[i] = Float2(pos_.x, pos_.y - size_.x);
    }
    
    for (int i = 0; i < 5; i++)
    {
        angle_ = (i* static_cast<double>(degree_)+change_["ROTA"].first) * 3.141592 / 180;

        point[i] -= pos_;

        Float2 n;
        n.x = (std::cos(angle_) * point[i].x) + (std::sin(angle_) * point[i].y);
        n.y = (-std::sin(angle_) * point[i].x) + (std::cos(angle_) * point[i].y);

        point[i] = pos_ + n;
    }
    if (point.size() >= 5) {
        DrawLine(point[0].x, point[0].y, point[2].x, point[2].y,color_, true);
        DrawLine(point[2].x, point[2].y, point[4].x, point[4].y,color_, true);
        DrawLine(point[4].x, point[4].y, point[1].x, point[1].y,color_, true);
        DrawLine(point[1].x, point[1].y, point[3].x, point[3].y,color_, true);
        DrawLine(point[3].x, point[3].y, point[0].x, point[0].y,color_, true);
    }
    DrawCircle(pos_.x,pos_.y,2,0xffffff);
    hit_.clear();
    hit_.emplace_back(Float2(pos_.x,pos_.y),size_.x);
}

void Star::Draw(float num)
{
    for (int i = 0; i < 5; i++)
    {
        point[i] = Float2(pos_.x, pos_.y - (size_.x*num));
    }

    for (int i = 1; i < 5; i++)
    {
        angle_ = (i * static_cast<double>(degree_)) * 3.141592 / 180;

        point[i] -= pos_;

        Float2 n;
        n.x = (std::cos(angle_) * point[i].x) + (std::sin(angle_) * point[i].y);
        n.y = (-std::sin(angle_) * point[i].x) + (std::cos(angle_) * point[i].y);

        point[i] = pos_ + n;
    }
    if (point.size() >= 5) {
        DrawLine(point[0].x, point[0].y, point[2].x, point[2].y, color_, true);
        DrawLine(point[2].x, point[2].y, point[4].x, point[4].y, color_, true);
        DrawLine(point[4].x, point[4].y, point[1].x, point[1].y, color_, true);
        DrawLine(point[1].x, point[1].y, point[3].x, point[3].y, color_, true);
        DrawLine(point[3].x, point[3].y, point[0].x, point[0].y, color_, true);
    }
    DrawCircle(pos_.x, pos_.y, 2, 0xffffff);
    hit_.clear();
    hit_.emplace_back(Float2(pos_.x, pos_.y), size_.x*num);
}

void Star::Init(void)
{
    stype_ = ShapeType::Star;
    degree_ = 72;
    point.resize(5);
   //rota_ = 0;
}
