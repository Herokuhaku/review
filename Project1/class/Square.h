#pragma once
#include "Shape.h"

class Square:
	public Shape
{
public:
	Square(Vector2 pos, Vector2 size);

	// DrawBox���Ă�
	void Draw(void)override;
	
	// n�{��Draw
	void Draw(float num)override;
	
	// offset�𒆐S�Ɋg�嗦������DrawBox�����
	// 1 : offset , 2 : �g�嗦
	void Draw(Vector2 center,float num = 1);
};