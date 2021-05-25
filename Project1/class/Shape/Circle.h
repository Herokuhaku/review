#pragma once
#include "Shape.h"

class Circle :
	public Shape
{
public:
	Circle(Parameters param, int mynum);
	~Circle();
	void Update(float delta,ShapeVec& shapes, VecInt& vecint,ParamVec& pvec)override;
	// DrawCircle���Ă�
	void Draw(void)override;

	// n�{��Draw
	void Draw(float num)override;

	void Init(void)override;
private:
};

