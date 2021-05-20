#pragma once
#include "Shape.h"
class Square:
	public Shape
{
public:
	Square(Float2&& pos, Float2&& vec, Float2&& size,int mynum);
	~Square();
	// Update
	void Update(float delta, ShapeVec& shapes)override;
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
	Float2 size_;
	std::pair<bool,bool> reverse_;
};