#pragma once
#include <vector>
#include <array>
#include "Shape.h"
class Heart :
	public Shape
{
public:
	Heart(Float2&& pos, Float2&& vec, int&& size, int mynum);
	~Heart();
	// Update
	void Update(float delta, ShapeVec& shapes)override;
	// DrawBox���Ă�
	void Draw(void)override;

	// n�{��Draw
	void Draw(float num)override;
	void Init(void)override;
private:
	std::vector<Float2> point;
	float height_;
	double angle_;
	float size_;

	bool reverse_;

	int heartsave_;
};

