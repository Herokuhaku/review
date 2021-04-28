#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(int x_,int y_);
	int x;
	int y;

	// γόZq
	Vector2& operator = (const Vector2& vec);

	// PZq
	Vector2& operator += (const Vector2& vec);
	Vector2& operator -= (const Vector2& vec);
	Vector2& operator *= (const Vector2& vec);
	Vector2& operator /= (const Vector2& vec);

	// δrZq
	bool operator >= (const Vector2& vec)const;
	bool operator <=  (const Vector2& vec)const;
	bool operator > (const Vector2& vec)const;
	bool operator <  (const Vector2& vec)const;
	bool operator ==  (const Vector2& vec)const;
	bool operator != (const Vector2& vec)const;

	// _Zq 
	bool operator && (const Vector2& vec)const;
	bool operator || (const Vector2& vec)const;

	// Y¦Zq
	int& operator[](const int& num);

	// 2Zq
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

// Vector2 Ζ intΜl₯Z
Vector2 operator +(const Vector2& vec,const int& num);
Vector2 operator -(const Vector2& vec, const int& num);
Vector2 operator *(const Vector2& vec, const int& num);
Vector2 operator /(const Vector2& vec, const int& num);

// int Ζ Vector2Μl₯Z
Vector2 operator +(const int& num,const Vector2& vec);
Vector2 operator -(const int& num, const Vector2& vec);
Vector2 operator *(const int& num, const Vector2& vec);
Vector2 operator /(const int& num, const Vector2& vec);

// Vector2 Ζ floatΜl₯Z
Vector2 operator + (const Vector2& vec,const float& num);
Vector2 operator - (const Vector2& vec, const float& num);
Vector2 operator * (const Vector2& vec,const float& num);
Vector2 operator / (const Vector2& vec, const float& num);