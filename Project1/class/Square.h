#pragma once
#include "Shape.h"

class Square:
	public Shape
{
public:
	Square(Vector2 pos, Vector2 size);
	// DrawBox‚ðŒÄ‚Ô
	void Draw(void)override;
	// n”{‚ÌDraw
	void Draw(float num);
	void Draw(Vector2 center,float num);
};