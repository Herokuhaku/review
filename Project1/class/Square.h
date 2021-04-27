#pragma once
#include "Shape.h"

class Square:
	public Shape
{
public:
	Square(Vector2 pos, Vector2 size);

	// DrawBoxを呼ぶ
	void Draw(void)override;
	
	// n倍のDraw
	void Draw(float num)override;
	
	// offsetを中心に拡大率を元にDrawBoxを作る
	// 1 : offset , 2 : 拡大率
	void Draw(Vector2 center,float num = 1);
};