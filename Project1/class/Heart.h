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
	// DrawBoxを呼ぶ
	void Draw(void)override;

	// n倍のDraw
	void Draw(float num)override;

	// offsetを中心に拡大率を元にDrawBoxを作る
	// 1 : offset , 2 : 拡大率
	void Draw(Float2 offset, float num = 1);
private:
	Float2 pos_;
	int size_;
};

