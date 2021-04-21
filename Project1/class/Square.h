#pragma once
#include "Shape.h"

class Square:
	public Shape
{
public:
	// DrawBox‚ðŒÄ‚Ô
	void Draw(void)override;
	Square(Vector2 pos, Vector2 size);
};