#pragma once
#include "../common/Vector2.h"
#include "Shape.h"
class Heart :
	public Shape
{
public:
	Heart(Float2&& pos, int&& size);
	~Heart();
	// Update
	void Update(double delta)override;
	// DrawBox���Ă�
	void Draw(void)override;

	// n�{��Draw
	void Draw(float num)override;

	// offset�𒆐S�Ɋg�嗦������DrawBox�����
	// 1 : offset , 2 : �g�嗦
	void Draw(Float2 offset, float num = 1);
private:
	Float2 pos_;
	int size_;
};

