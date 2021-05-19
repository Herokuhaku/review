#pragma once
#include <vector>
#include "Shape.h"
class Triangle :
	public Shape
{
public:
	Triangle(Float2&& pos,int&& size,int&& mynum);
	~Triangle();
	
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
};

