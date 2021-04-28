#pragma once
#include "Shape.h"
#include "../common/Vector2.h"
class Square:
	public Shape
{
public:
	Square(Float2 pos, Float2 size);

	// DrawBox‚ğŒÄ‚Ô
	void Draw(void)override;
	
	// n”{‚ÌDraw
	void Draw(float num)override;
	
	// offset‚ğ’†S‚ÉŠg‘å—¦‚ğŒ³‚ÉDrawBox‚ğì‚é
	// 1 : offset , 2 : Šg‘å—¦
	void Draw(Float2 center,float num = 1);
};