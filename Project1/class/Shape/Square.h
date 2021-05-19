#pragma once
#include "Shape.h"
class Square:
	public Shape
{
public:
	Square(Float2&& pos, Float2&& size,HitCircle& hit,int mynum,int& allnum);
	~Square();
	// Update
	void Update(float delta, ShapeVec& shapes)override;
	// DrawBox���Ă�
	void Draw(void)override;
	
	// n�{��Draw
	void Draw(float num)override;

	// offset�𒆐S�Ɋg�嗦������DrawBox�����
	// 1 : offset , 2 : �g�嗦
	void Draw(Float2 offset,float num = 1);

	// �����蔻��
	bool HitCheck(ShapeVec& shapes)override;

	void Init(void)override;
private:
	// �c���̑傫��
	Float2 size_;
	std::pair<bool,bool> reverse_;
	int* allnumber_;
};