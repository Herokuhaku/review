#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(int x_,int y_);
	int x;
	int y;

	// ‘ã“ü‰‰ŽZŽq
	Vector2& operator = (const Vector2& vec);

	// ’P€‰‰ŽZŽq
	Vector2& operator += (const Vector2& vec);
	Vector2& operator -= (const Vector2& vec);
	Vector2& operator *= (const Vector2& vec);
	Vector2& operator /= (const Vector2& vec);

	// ”äŠr‰‰ŽZŽq
	bool operator >= (const Vector2& vec)const;
	bool operator <=  (const Vector2& vec)const;
	bool operator > (const Vector2& vec)const;
	bool operator <  (const Vector2& vec)const;
	bool operator ==  (const Vector2& vec)const;
	bool operator != (const Vector2& vec)const;

	// ˜_—‰‰ŽZŽq 
	bool operator && (const Vector2& vec)const;
	bool operator || (const Vector2& vec)const;

	// “Y‚¦Žš‰‰ŽZŽq
	int& operator[](const int& num);

	// 2€‰‰ŽZŽq
	Vector2 operator +(const Vector2& vec)const;
	Vector2 operator -(const Vector2& vec)const;
	Vector2 operator *(const Vector2& vec)const;
	Vector2 operator /(const Vector2& vec)const;
	Vector2 operator %(const Vector2& vec)const;

	Vector2 operator +()const;
	Vector2 operator -()const;

	Vector2& operator++();
	Vector2 operator++(int);
};

// Vector2 ‚Æ int‚ÌŽl‘¥‰‰ŽZ
Vector2 operator +(const Vector2& vec,const int& num);
Vector2 operator -(const Vector2& vec, const int& num);
Vector2 operator *(const Vector2& vec, const int& num);
Vector2 operator /(const Vector2& vec, const int& num);

// int ‚Æ Vector2‚ÌŽl‘¥‰‰ŽZ
Vector2 operator +(const int& num,const Vector2& vec);
Vector2 operator -(const int& num, const Vector2& vec);
Vector2 operator *(const int& num, const Vector2& vec);
Vector2 operator /(const int& num, const Vector2& vec);

// Vector2 ‚Æ float‚ÌŽl‘¥‰‰ŽZ
Vector2 operator + (const Vector2& vec,const float& num);
Vector2 operator - (const Vector2& vec, const float& num);
Vector2 operator * (const Vector2& vec,const float& num);
Vector2 operator / (const Vector2& vec, const float& num);