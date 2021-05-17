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
	// DrawBox‚ğŒÄ‚Ô
	void Draw(void)override;
	
	// n”{‚ÌDraw
	void Draw(float num)override;
	
	bool test() { return true; };
	// offset‚ğ’†S‚ÉŠg‘å—¦‚ğŒ³‚ÉDrawBox‚ğì‚é
	// 1 : offset , 2 : Šg‘å—¦
	void Draw(Float2 offset,float num = 1);
private:
	// c‰¡‚Ì‘å‚«‚³
	Float2 size_;
};