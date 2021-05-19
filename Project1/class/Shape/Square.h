#pragma once
#include "Shape.h"
class Square:
	public Shape
{
public:
	Square(Float2&& pos, Float2&& size,HitCircle& hit,int mynum,int& allnum);
	~Square();
	// Update
	void Update(float delta, ShapeVec& shapes)override;
	// DrawBoxを呼ぶ
	void Draw(void)override;
	
	// n倍のDraw
	void Draw(float num)override;

	// offsetを中心に拡大率を元にDrawBoxを作る
	// 1 : offset , 2 : 拡大率
	void Draw(Float2 offset,float num = 1);

	// 当たり判定
	bool HitCheck(ShapeVec& shapes)override;

	void Init(void)override;
private:
	// 縦横の大きさ
	Float2 size_;
	std::pair<bool,bool> reverse_;
	int* allnumber_;
};