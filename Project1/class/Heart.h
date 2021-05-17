#pragma once
#include "../common/Vector2.h"
#include "Shape.h"
class Heart :
	public Shape
{
public:
	Heart(Float2&& pos, int&& size);
	~Heart();
	// Update
	void Update(double delta)override;
	// DrawBox‚ğŒÄ‚Ô
	void Draw(void)override;

	// n”{‚ÌDraw
	void Draw(float num)override;

	// offset‚ğ’†S‚ÉŠg‘å—¦‚ğŒ³‚ÉDrawBox‚ğì‚é
	// 1 : offset , 2 : Šg‘å—¦
	void Draw(Float2 offset, float num = 1);
private:
	Float2 pos_;
	int size_;
};

