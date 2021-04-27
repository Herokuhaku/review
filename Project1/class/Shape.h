#pragma once
#include "../common/Vector2.h"
class Shape
{
public:
	Shape(Vector2 pos,Vector2 size);
	~Shape();

	// Drawを呼ぶ
	virtual void Draw(void) = 0;

	// n倍のDraw
	virtual void Draw(float num) = 0;

	// offsetを中心に拡大して描画する
	// 1 : offset , 2 : 拡大率
	virtual void Draw(Vector2 offset, float num = 1) = 0;
protected:
	// 座標
	Vector2 pos_;
	// 縦横の大きさ
	Vector2 size_;
};