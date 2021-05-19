#pragma once
#include <vector>
#include <array>
#include "Shape.h"
class Heart :
	public Shape
{
public:
	Heart(Float2&& pos, int&& size, HitCircle& hit, int mynum);
	~Heart();
	// Update
	void Update(float delta, ShapeVec& shapes)override;
	// DrawBox‚ðŒÄ‚Ô
	void Draw(void)override;

	// n”{‚ÌDraw
	void Draw(float num)override;
	void Init(void)override;
private:
	std::vector<Float2> point;
	float height_;
	double angle_;
	float size_;
	int scr_;
	int heart_;

	bool reverse_;
};

