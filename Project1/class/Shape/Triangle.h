#pragma once
#include <vector>
#include <map>
#include "Shape.h"
class Triangle :
	public Shape
{
public:
	Triangle(Parameters param, int mynum);
	~Triangle();
	
	void Update(float delta, ShapeVec& shapes, VecInt& vecint, ParamVec& pvec)override;

	// DrawBox‚ðŒÄ‚Ô
	void Draw(void)override;

	// n”{‚ÌDraw
	void Draw(float num)override;

	void Init(void)override;
private:
	std::vector<Float2> point;
	float height_;
	double angle_;

	std::map<ShapeType, int> hitcount_;
};

