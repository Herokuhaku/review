#pragma once
#include "../common/Vector2.h"
class Shape
{
public:
	//Shape();
	//Shape(int posx,int posy,int sizex,int sizey);
	Shape(Vector2 pos,Vector2 size);
	~Shape();

	// Draw‚ðŒÄ‚Ô
	virtual void Draw(void);
protected:
	Vector2 pos_;
	Vector2 size_;
	//int posx_;
	//int posy_;
	//int sizex_;
	//int sizey_;
};