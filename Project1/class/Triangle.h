#pragma once
#include "Shape.h"
class Triangle :
	public Shape
{
public:
	Triangle(Float2&& pos,int&& size);
	~Triangle();

	// DrawBox���Ă�
	void Draw(void)override;

	// n�{��Draw
	void Draw(float num)override;
private:
	int size_;
};

