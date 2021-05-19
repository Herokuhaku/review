#pragma once
#include <vector>
#include "Shape.h"
class Star :
	public Shape
{
public:
	Star(Float2&& pos, int&& size, int&& mynum);
	~Star();

	void Update(float delta, ShapeVec& shapes)override;

	// DrawBox‚ðŒÄ‚Ô
	void Draw(void)override;

	// n”{‚ÌDraw
	void Draw(float num)override;

	void Init(void)override;
private:
	std::vector<Float2> point;
	int size_;
	int degree_;
	double angle_;
};