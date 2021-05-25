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
	// DrawBox‚ğŒÄ‚Ô
	void Draw(void)override;
	
	// n”{‚ÌDraw
	void Draw(float num)override;

	// offset‚ğ’†S‚ÉŠg‘å—¦‚ğŒ³‚ÉDrawBox‚ğì‚é
	// 1 : offset , 2 : Šg‘å—¦
	void Draw(Float2 offset,float num = 1);
	// ‰Šú’lİ’è
	void Init(void)override;
private:
	// c‰¡‚Ì‘å‚«‚³
	std::pair<bool,bool> reverse_;
};