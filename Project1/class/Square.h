#pragma once
#include "Shape.h"

class Square:
	public Shape
{
public:
	// DrawBox���Ă�
	void Draw(void)override;
	Square(Vector2 pos, Vector2 size);
};