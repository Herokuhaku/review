#pragma once
#include <vector>
#include "Shape.h"
class Star :
	public Shape
{
public:
	Star(Parameters param, int mynum);
	~Star();

	void Update(float delta, ShapeVec& shapes, VecInt& vecint, ParamVec& pvec)override;

	// DrawBox���Ă�
	void Draw(void)override;

	// n�{��Draw
	void Draw(float num)override;

	void Init(void)override;
private:
	std::vector<Float2> point;
	int degree_;
	double angle_;
};