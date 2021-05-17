#pragma once
#include <vector>
#include "Shape.h"
#include "../common/Vector2.h"
class Star :
	public Shape
{
public:
	Star(Float2&& pos, int&& size);
	~Star();

	void Update(float delta)override;

	// DrawBox���Ă�
	void Draw(void)override;

	// n�{��Draw
	void Draw(float num)override;

	void Init(void);
private:
	std::vector<Float2> point;
	int size_;
	int degree_;
	double angle_;
};