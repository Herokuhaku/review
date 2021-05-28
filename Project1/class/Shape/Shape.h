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
using VecInt = std::vector<int>;
enum class ShapeType {
	NON,
	Square,
	Circle,
	Triangle,
	Star,
	Heart,
	MAX
};

struct Parameters {
	Parameters() {
		p = Float2(0, 0);
		v = Float2(0, 0);
		s = Float2(0, 0);
	};
	Parameters(Float2 p,Float2 v,Float2 s) {
		Parameters::p = p;
		Parameters::v = v;
		Parameters::s = s;
	};
	// pos
	Float2 p;
	// vec
	Float2 v;
	// size
	Float2 s;
};

using ParamVec = std::vector<Parameters>;
class Shape
{
public:
	Shape();
	Shape(Parameters parm,int num);
	~Shape();

	// Update
	virtual void Update(float delta,ShapeVec& shapes,VecInt& vecint,ParamVec& param) = 0;
	
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
	std::pair<SharedShape&,bool> HitCheck(ShapeVec shapes);
	// 円の判定視覚化
	void HitDraw(void);
	// 当たり判定の削除
	void ClearHitCheck(void);
	// 回転フラグを反転させる
	void ChangeRotaFlag();
	// Drwaの拡大率を変えるフラグ
	void ChangeDrawSizeFlag();

	// Changeの中身を呼ぶ
	std::pair<double, bool> GetChange(std::string str);

	// Drawのサイズを変える
	void ChangeDrawSize(double plus);
	// Drawの色を変える
	void ChangeColor(void);

	// スピードを上げる
	void ChangeVec(float speed,Float2 max = { 300,300 },Float2 min = { 20,20 });

private:
	// 初期値設定
	virtual void Init(void);

protected:
	// 座標
	Float2 pos_;
	Float2 size_;
	Float2 vec_;
	int mynumber_;
	HitPairVec hit_;
	ShapeType stype_;
	int color_;
	std::function<bool(UniqueShape& shape1, UniqueShape& shape2)> hitCheckShapes_;
	
	// 当たり判定
	bool hitnow_;
	bool otherflag;
	bool screenhit_;
	bool allscreenhit_;

	// 拡大
	std::map<std::string, std::pair<double, bool>> change_;
	std::pair<double, bool> smooth_;
	int smoothsize_;
	int maxmag_;
	double plusmag_;
};