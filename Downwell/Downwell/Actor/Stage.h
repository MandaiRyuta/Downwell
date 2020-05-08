#pragma once
#include "Actor.h"
#include <array>
#include <algorithm>
#include "../Constant.h"
#include "../Collision/QuadTree.h"

constexpr int StageWidth = 20;
constexpr int StageHeigh = 350;
constexpr int OneBlockHeight = 50;
constexpr int OneBlockWidth = 20;
constexpr int BlockWidth = 18;
constexpr int BlockHeight = 18;
constexpr int BlockSize = 18;

class Stage : public Actor
{
public:
	Stage();
	~Stage();
public:
	virtual void Update() override;
	virtual void Draw() override;

	static const VECTOR& GetStagePos(int x, int y);
	static const int& GetStageType(int x, int y);
	static const Rect& GetStageRect(int x, int y);
	static void SetStageType(int type, int x, int y);
private:
	static std::array<std::array<int, StageWidth>, StageHeigh> Stage_;
	static std::array<std::array<VECTOR, StageWidth>, StageHeigh> Blockpos_;
	static std::array<std::array<Rect, StageWidth>, StageHeigh> Blockrect_;
	int StageBlockHandle_;
	int BlockTexture_;
	int NonBlockTexture_;
	int InSideBlockTexture_;
};