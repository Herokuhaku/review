#pragma once
#include <functional>
#include <utility>
#include <vector>
#include <memory>
#include <map>
#include "../../common/Vector2.h"

#define SCREEN 800
class Shape;
using UniqueShape = std::unique_ptr<Shape>;
using SharedShape = std::shared_ptr<Shape>;
using ShapeVec = std::vector<SharedShape>;
using HitPair = std::pair<Float2, int>;
using HitPairVec = std::vector<HitPair>;
using HitCircle = std::map<int,HitPairVec>;

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
	Shape(Float2&& pos,Float2& vec,int num);
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


	// 形
	virtual ShapeType GetType(void);
	// ヒットボックス呼び出し
	virtual HitPairVec GetHitPairVec(void);
	// 自分の生成番号呼び出し
	virtual int GetMynum(void);

	// 当たり判定
	std::pair<SharedShape&,bool> HitCheck(ShapeVec& shapes);
	// 円の判定視覚化
	void HitDraw(void);
	// 当たり判定の削除
	void ClearHitCheck(void);

	void SetRotaFlag_();
private:
	// 初期値設定
	virtual void Init(void);

protected:
	// 座標
	Float2 pos_;
	Float2 vec_;
	int mynumber_;
	HitPairVec hit_;
	ShapeType stype_;
	int color_;
	std::function<bool(UniqueShape& shape1, UniqueShape& shape2)> hitCheckShapes_;
	bool hitnow_;
	bool otherflag;
	bool screenhit_;
	bool allscreenhit_;

	//
	double rota_;
	bool rotaflag_;
};