#include "Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(int x_, int y_)
{
	x = x_;
	y = y_;
}

Vector2 Vector2::operator*(float tmp)
{
	return Vector2(x*tmp,y*tmp);
}

Vector2 Vector2::operator/(float tmp)
{
	return Vector2(x / tmp, y / tmp);
}

Vector2 Vector2::operator*(Vector2 tmp)
{
	return Vector2(x * tmp.x, y * tmp.y);
}

Vector2 Vector2::operator/(Vector2 tmp)
{
	return Vector2(x / tmp.x, y / tmp.y);
}

Vector2 Vector2::operator+(Vector2 tmp)
{
	return Vector2(x+tmp.x,y+tmp.y);
}

Vector2 Vector2::operator-(Vector2 tmp)
{
	return Vector2(x - tmp.x, y - tmp.y);
}
