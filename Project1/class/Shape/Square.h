#pragma once
#include "Shape.h"
class Square:
	public Shape
{
public:
	Square(Parameters param, int mynum);
	~Square();
	// Update
	void Update(float delta, ShapeVec& shapes, VecInt& vecint, ParamVec& pvec)override;
	// DrawBoxを呼ぶ
	void Draw(void)override;
	
	// n倍のDraw
	void Draw(float num)override;

	// offsetを中心に拡大率を元にDrawBoxを作る
	// 1 : offset , 2 : 拡大率
	void Draw(Float2 offset,float num = 1);
	// 初期値設定
	void Init(void)override;
private:
	// 縦横の大きさ
	std::pair<bool,bool> reverse_;
};