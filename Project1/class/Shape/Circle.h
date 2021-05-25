#pragma once
#include "Shape.h"

class Circle :
	public Shape
{
public:
	Circle(Parameters param, int mynum);
	~Circle();
	void Update(float delta,ShapeVec& shapes, VecInt& vecint,ParamVec& pvec)override;
	// DrawCircle‚ðŒÄ‚Ô
	void Draw(void)override;

	// n”{‚ÌDraw
	void Draw(float num)override;

	void Init(void)override;
private:
};

