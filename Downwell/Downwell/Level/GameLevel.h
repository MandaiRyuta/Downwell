#pragma once
#include "Level.h"
#include "../Constant.h"
#include "../Actor/Actor.h"
#include "../Widget/Widget.h"

class GameLevel : public Level
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="type">シーン番号</param>
	GameLevel(int type);
	/// <summary>
	/// デストラクター
	/// </summary>
	~GameLevel();
public:
	/// <summary>
	/// 更新関数
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw() override;

private:
	int nNowLevel_;	//現在のシーン番号
	std::list<Actor*> Obj_[3];	//Actor情報
	std::list<Widget*> Widgetobj_[3];	//Widget情報
};