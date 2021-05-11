#pragma once
#include "Shape.h"
#include "../common/Vector2.h"
class Square:
	public Shape
{
public:
	Square(Float2&& pos, Float2&& size);
	~Square();

	// DrawBoxを呼ぶ
	void Draw(void)override;
	
	// n倍のDraw
	void Draw(float num)override;
	
	// offsetを中心に拡大率を元にDrawBoxを作る
	// 1 : offset , 2 : 拡大率
	void Draw(Float2 offset,float num = 1);
private:
	// 縦横の大きさ
	Float2 size_;
};