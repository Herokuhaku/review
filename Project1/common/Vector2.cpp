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

Vector2& Vector2::operator=(const Vector2& vec)
{
	x = vec.x;
	y = vec.y;
	return *this;
}

Vector2& Vector2::operator+=(const Vector2& vec)
{
	x += vec.x;
	y += vec.y;
	return *this;
	// TODO: return ステートメントをここに挿入します
}

Vector2& Vector2::operator-=(const Vector2& vec)
{
	x -= vec.x;
	y -= vec.y;
	return *this;
	// TODO: return ステートメントをここに挿入します
}

Vector2& Vector2::operator*=(const Vector2& vec)
{
	x *= vec.x;
	y *= vec.y;
	return *this;
	// TODO: return ステートメントをここに挿入します
}

Vector2& Vector2::operator/=(const Vector2& vec)
{
	!vec.x ? x = 1000000000 : x /= vec.x;
	!vec.y ? y = 1000000000 : y /= vec.y;
	return *this;
	// TODO: return ステートメントをここに挿入します
}

bool Vector2::operator>=(const Vector2& vec)const
{
	return (x >= vec.x && y >= vec.y);
}

bool Vector2::operator<=(const Vector2& vec) const
{
	return (x <= vec.x && y <= vec.y);
}

bool Vector2::operator>(const Vector2& vec) const
{
	return (x > vec.x && y > vec.y);
}

bool Vector2::operator<(const Vector2& vec) const
{
	return (x < vec.x && y < vec.y);
}

bool Vector2::operator==(const Vector2& vec) const
{
	return (x == vec.x && y == vec.y);
}

bool Vector2::operator!=(const Vector2& vec) const
{
	return (x != vec.x && y != vec.y);
}

bool Vector2::operator&&(const Vector2& vec) const
{
	return ((x && vec.x) && (y && vec.y));
}

bool Vector2::operator||(const Vector2& vec) const
{
	return ((x || vec.x) || (y || vec.y));
}

int& Vector2::operator[](const int& num)
{
	if (!num)
	{
		return x;
	}
	else if (num == 1)
	{
		return y;
	}
	return x;
	// TODO: return ステートメントをここに挿入します
}

Vector2 Vector2::operator+(const Vector2& vec)const
{
	return Vector2(x + vec.x,y + vec.y);
}

Vector2 Vector2::operator-(const Vector2& vec)const
{
	return Vector2(x - vec.x,y - vec.y);
}

Vector2 Vector2::operator*(const Vector2& vec)const
{
	return Vector2(x * vec.x, y * vec.y);
}

Vector2 Vector2::operator/(const Vector2& vec)const
{
	Vector2 tmp(0,0);
	!vec.x ? tmp.x = 1000000000 : x / vec.x;
	!vec.y ? tmp.y = 1000000000 : y / vec.y;

	return tmp;
}

Vector2 Vector2::operator%(const Vector2& vec) const
{
	Vector2 tmp(0,0);
	!vec.x ? tmp.x = 1000000000 : x % vec.x;
	!vec.y ? tmp.y = 1000000000 : y % vec.y;
	return tmp;
}

Vector2 Vector2::operator+()const
{
	return Vector2(x,y);
	//return Vector2(x+tmp.x,y+tmp.y);
}

Vector2 Vector2::operator-()const
{
	return Vector2(-x,-y);
}

Vector2& Vector2::operator++()
{
	x++;
	y++;
	return *this;
}

Vector2 Vector2::operator++(int)
{
	Vector2 tmp = *this;
	++*this;
	return tmp;
	// TODO: return ステートメントをここに挿入します
}

Vector2 operator+(const Vector2& vec, const int& num)
{
	return Vector2(vec.x + num,vec.y + num);
}

Vector2 operator-(const Vector2& vec, const int& num)
{
	return Vector2(vec.x - num, vec.y - num);
}

Vector2 operator*(const Vector2& vec, const int& num)
{
	return Vector2(vec.x * num, vec.y * num);
}

Vector2 operator/(const Vector2& vec, const int& num)
{
	if (!num)
	{
		return Vector2(1000000000, 1000000000);
	}
	return Vector2(vec.x / num, vec.y / num);
}

Vector2 operator+(const int& num, const Vector2& vec)
{
	return Vector2(num + vec.x,num + vec.y);
}

Vector2 operator-(const int& num, const Vector2& vec)
{
	return Vector2(num - vec.x, num - vec.y);
}

Vector2 operator*(const int& num, const Vector2& vec)
{
	return Vector2(num * vec.x,num * vec.y);
}

Vector2 operator/(const int& num, const Vector2& vec)
{
	return Vector2(num / vec.x,num/vec.y);
}

Vector2 operator+(const Vector2& vec, const float& num)
{
	return Vector2(vec.x + num,vec.y + num);
}

Vector2 operator-(const Vector2& vec, const float& num)
{
	return Vector2(vec.x - num, vec.y - num);
}

Vector2 operator*(const Vector2& vec, const float& num)
{
	return Vector2(vec.x * num, vec.y * num);
}

Vector2 operator/(const Vector2& vec, const float& num)
{
	if (!num)
	{
		return Vector2(1000000000, 1000000000);
	}
	return Vector2(vec.x / num, vec.y / num);
}
