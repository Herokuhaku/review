#pragma once
#include "Shape.h"

class Circle :
	public Shape
{
public:
	Circle(Float2&& pos, int&& size, int&& mynum);
	~Circle();
	void Update(float delta,ShapeVec& shapes)override;
	// DrawCircle���Ă�
	void Draw(void)override;

	// n�{��Draw
	void Draw(float num)override;

	void Init(void)override;
private:
	int size_;
};

