#pragma once
class Shape
{
public:
	Shape();
	~Shape();

	void Draw(void);
private:
	int posx_;
	int posy_;
	int sizex_;
	int sizey_;
};

