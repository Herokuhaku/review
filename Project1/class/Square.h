#pragma once
#include "Shape.h"
#include "../common/Vector2.h"
class Square:
	public Shape
{
public:
	Square(Float2&& pos, Float2&& size);
	~Square();
	// Update
	void Update(float delta)override;
	// DrawBox���Ă�
	void Draw(void)override;
	
	// n�{��Draw
	void Draw(float num)override;
	
	bool test() { return true; };
	// offset�𒆐S�Ɋg�嗦������DrawBox�����
	// 1 : offset , 2 : �g�嗦
	void Draw(Float2 offset,float num = 1);
private:
	// �c���̑傫��
	Float2 size_;
};