#pragma once
#include "../common/Vector2.h"
class Shape
{
public:
	Shape(Vector2 pos,Vector2 size);
	~Shape();

	// Draw���Ă�
	virtual void Draw(void) = 0;

	// n�{��Draw
	virtual void Draw(float num) = 0;

	// offset�𒆐S�Ɋg�債�ĕ`�悷��
	// 1 : offset , 2 : �g�嗦
	virtual void Draw(Vector2 offset, float num = 1) = 0;
protected:
	// ���W
	Vector2 pos_;
	// �c���̑傫��
	Vector2 size_;
};