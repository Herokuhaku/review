#pragma once
#include "Shape.h"
class Triangle :
	public Shape
{
public:
	Triangle(Float2&& pos,int&& size);
	~Triangle();

	// DrawBox‚ðŒÄ‚Ô
	void Draw(void)override;

	// n”{‚ÌDraw
	void Draw(float num)override;
private:
	int size_;
};

