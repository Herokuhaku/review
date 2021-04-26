#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(int x_,int y_);
	int x;
	int y;
	Vector2 operator * (float tmp);
	Vector2 operator / (float tmp);
	Vector2 operator * (Vector2 tmp);
	Vector2 operator / (Vector2 tmp);
	Vector2 operator +(Vector2 tmp);
	Vector2 operator -(Vector2 tmp);
};

