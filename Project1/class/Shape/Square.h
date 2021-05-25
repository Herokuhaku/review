#pragma once
#include "Shape.h"
class Square:
	public Shape
{
public:
	Square(Parameters param, int mynum);
	~Square();
	// Update
	void Update(float delta, ShapeVec& shapes, VecInt& vecint, ParamVec& pvec)override;
	// DrawBox���Ă�
	void Draw(void)override;
	
	// n�{��Draw
	void Draw(float num)override;

	// offset�𒆐S�Ɋg�嗦������DrawBox�����
	// 1 : offset , 2 : �g�嗦
	void Draw(Float2 offset,float num = 1);
	// �����l�ݒ�
	void Init(void)override;
private:
	// �c���̑傫��
	std::pair<bool,bool> reverse_;
};