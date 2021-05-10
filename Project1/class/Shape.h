#pragma once
#include "../common/Vector2.h"

class Shape
{
public:
	Shape(Float2&& pos, Float2&& size);
	~Shape();

	// Draw���Ă�
	virtual void Draw(void) = 0;

	// n�{��Draw
	virtual void Draw(float num) = 0;

	// offset�𒆐S�Ɋg�債�ĕ`�悷��
	// 1 : offset , 2 : �g�嗦
	virtual void Draw(Float2 offset, float num = 1) = 0;
protected:
	// ���W
	Float2 pos_;
	// �c���̑傫��
	Float2 size_;
};