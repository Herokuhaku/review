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
	
	// Draw系
	// Drawを呼ぶ
	virtual void Draw(void) = 0;
	// n倍のDraw
	virtual void Draw(float num) = 0;
	// offsetを中心に拡大して描画する
	// 1 : offset , 2 : 拡大率
	virtual void Draw(Float2 offset, float num = 1);

	// 当たり判定
	virtual bool HitCheck(ShapeVec& shapes);

	virtual ShapeType GetType(void);
private:
	// 初期値設定
	virtual void Init(void);

protected:
	// 座標
	Float2 pos_;
	int mynumber_;
	ShapeType stype_;
	std::function<bool(UniqueShape& shape1, UniqueShape& shape2)> hitCheckShapes_;
};