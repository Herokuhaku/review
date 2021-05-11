#pragma once
#include "Shape.h"

class Circle :
	public Shape
{
public:
	Circle(Float2&& pos, int&& size);
	~Circle();
	void Update(float delta)override;
	// DrawCircle‚ðŒÄ‚Ô
	void Draw(void)override;

	// n”{‚ÌDraw
	void Draw(float num)override;
private:
	int size_;
};

