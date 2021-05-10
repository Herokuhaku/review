#pragma once
#include "../common/Vector2.h"

class Shape
{
public:
	Shape(Float2&& pos, Float2&& size);
	~Shape();

	// Drawを呼ぶ
	virtual void Draw(void) = 0;

	// n倍のDraw
	virtual void Draw(float num) = 0;

	// offsetを中心に拡大して描画する
	// 1 : offset , 2 : 拡大率
	virtual void Draw(Float2 offset, float num = 1) = 0;
protected:
	// 座標
	Float2 pos_;
	// 縦横の大きさ
	Float2 size_;
};