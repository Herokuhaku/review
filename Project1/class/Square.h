#pragma once
#include "Shape.h"

class Square:
	public Shape
{
public:
	Square(Vector2 pos, Vector2 size);

	// DrawBox‚ğŒÄ‚Ô
	void Draw(void)override;
	
	// n”{‚ÌDraw
	void Draw(float num)override;
	
	// offset‚ğ’†S‚ÉŠg‘å—¦‚ğŒ³‚ÉDrawBox‚ğì‚é
	// 1 : offset , 2 : Šg‘å—¦
	void Draw(Vector2 center,float num = 1);
};