#pragma once
#include "../common/Vector2.h"
class Shape
{
public:
	Shape(Vector2 pos,Vector2 size);
	~Shape();

	// Draw‚ğŒÄ‚Ô
	virtual void Draw(void) = 0;

	// n”{‚ÌDraw
	virtual void Draw(float num) = 0;

	// offset‚ğ’†S‚ÉŠg‘å‚µ‚Ä•`‰æ‚·‚é
	// 1 : offset , 2 : Šg‘å—¦
	virtual void Draw(Vector2 offset, float num = 1) = 0;
protected:
	// À•W
	Vector2 pos_;
	// c‰¡‚Ì‘å‚«‚³
	Vector2 size_;
};