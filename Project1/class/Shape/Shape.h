#pragma once
#include <functional>
#include <utility>
#include <vector>
#include <memory>
#include "../../common/Vector2.h"

#define SCREEN 800
class Shape;
using UniqueShape = std::unique_ptr<Shape>;
using SharedShape = std::shared_ptr<Shape>;
using ShapeVec = std::vector<UniqueShape>;

enum class ShapeType {
	NON,
	Square,
	Circle,
	Triangle,
	Star,
	Heart,
	MAX
};

class Shape
{
public:
	Shape(Float2&& pos,int& num);
	~Shape();

	// Update
	virtual void Update(float delta,ShapeVec& shapes) = 0;
	
	// DrawŒn
	// Draw‚ğŒÄ‚Ô
	virtual void Draw(void) = 0;
	// n”{‚ÌDraw
	virtual void Draw(float num) = 0;
	// offset‚ğ’†S‚ÉŠg‘å‚µ‚Ä•`‰æ‚·‚é
	// 1 : offset , 2 : Šg‘å—¦
	virtual void Draw(Float2 offset, float num = 1);

	// “–‚½‚è”»’è
	virtual bool HitCheck(ShapeVec& shapes);

	virtual ShapeType GetType(void);
private:
	// ‰Šú’lİ’è
	virtual void Init(void);

protected:
	// À•W
	Float2 pos_;
	int mynumber_;
	ShapeType stype_;
	std::function<bool(UniqueShape& shape1, UniqueShape& shape2)> hitCheckShapes_;
};