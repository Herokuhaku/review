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
	void Draw(float num);
	void Draw(Vector2 center,float num);
};