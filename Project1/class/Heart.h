#pragma once
#include <vector>
#include <array>
#include "../common/Vector2.h"
#include "Shape.h"
class Heart :
	public Shape
{
public:
	Heart(Float2&& pos, int&& size);
	~Heart();
	// Update
	void Update(float delta)override;
	// DrawBox‚ðŒÄ‚Ô
	void Draw(void)override;

	// n”{‚ÌDraw
	void Draw(float num)override;
private:
	std::vector<Float2> point;
	float height_;
	double angle_;
	float size_;
	int scr;
	int heart;
};

