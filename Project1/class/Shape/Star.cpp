#include <DxLib.h>
#include <cmath>
#include <utility>
#include <vector>
#include "Star.h"

Star::Star(Float2&& pos, Float2&& vec, int&& size,int mynum):Shape(std::move(pos),vec, mynum)
{
    pos_ = pos;
    size_ = size;
    Init();
}

Star::~Star()
{
}

void Star::Update(float delta, ShapeVec& shapes)
{
    pos_ += (vec_ * delta);
    std::pair<SharedShape&, bool> hitchecktmp = HitCheck(shapes);
    if (hitchecktmp.second)
    {
        if (hitchecktmp.first != nullptr && hitchecktmp.first->GetType() == ShapeType::Triangle) {
            hitchecktmp.first->SetRotaFlag_();
        }
        rotaflag_ = !rotaflag_;
    }
    if (rotaflag_) {
        rota_++;
    }
}

void Star::Draw(void)
{
    for (int i = 0; i < 5; i++)
    {
        point[i] = Float2(pos_.x, pos_.y - size_);
    }
    
    for (int i = 0; i < 5; i++)
    {
        angle_ = (i* static_cast<double>(degree_)+rota_) * 3.141592 / 180;

        point[i] -= pos_;

        Float2 n;
        n.x = (std::cos(angle_) * point[i].x) + (std::sin(angle_) * point[i].y);
        n.y = (-std::sin(angle_) * point[i].x) + (std::cos(angle_) * point[i].y);

        point[i] = pos_ + n;
    }
    if (point.size() >= 5) {
        DrawLine(point[0].x, point[0].y, point[2].x, point[2].y, 0xffffff, true);
        DrawLine(point[2].x, point[2].y, point[4].x, point[4].y, 0xffffff, true);
        DrawLine(point[4].x, point[4].y, point[1].x, point[1].y, 0xffffff, true);
        DrawLine(point[1].x, point[1].y, point[3].x, point[3].y, 0xffffff, true);
        DrawLine(point[3].x, point[3].y, point[0].x, point[0].y, 0xffffff, true);
    }
    DrawCircle(pos_.x,pos_.y,2,0xffffff);
    hit_.emplace_back(Float2(pos_.x,pos_.y),size_);
}

void Star::Draw(float num)
{
    for (int i = 0; i < 5; i++)
    {
        point[i] = Float2(pos_.x, pos_.y - (size_*num));
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
        DrawLine(point[0].x, point[0].y, point[2].x, point[2].y, 0xffffff, true);
        DrawLine(point[2].x, point[2].y, point[4].x, point[4].y, 0xffffff, true);
        DrawLine(point[4].x, point[4].y, point[1].x, point[1].y, 0xffffff, true);
        DrawLine(point[1].x, point[1].y, point[3].x, point[3].y, 0xffffff, true);
        DrawLine(point[3].x, point[3].y, point[0].x, point[0].y, 0xffffff, true);
    }
    DrawCircle(pos_.x, pos_.y, 2, 0xffffff);
    hit_.emplace_back(Float2(pos_.x, pos_.y), size_*num);
}

void Star::Init(void)
{
    stype_ = ShapeType::Star;
    degree_ = 72;
    point.resize(5);
    rota_ = 0;
}
