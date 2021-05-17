#pragma once
#include <vector>
#include "Shape.h"
#include "../common/Vector2.h"
class Triangle :
	public Shape
{
public:
	Triangle(Float2&& pos,int&& size);
	~Triangle();
	
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
};

