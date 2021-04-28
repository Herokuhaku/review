#pragma once
#include "Shape.h"
#include "../common/Vector2.h"
class Square:
	public Shape
{
public:
	Square(Float2 pos, Float2 size);

	// DrawBox���Ă�
	void Draw(void)override;
	
	// n�{��Draw
	void Draw(float num)override;
	
	// offset�𒆐S�Ɋg�嗦������DrawBox�����
	// 1 : offset , 2 : �g�嗦
	void Draw(Float2 center,float num = 1);
};