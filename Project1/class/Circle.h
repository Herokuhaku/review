#pragma once
#include "Shape.h"

class Circle :
	public Shape
{
public:
	Circle(Float2&& pos, int&& size);
	~Circle();
	// DrawCircle���Ă�
	void Draw(void)override;

	// n�{��Draw
	void Draw(float num)override;
private:
	int size_;
};
