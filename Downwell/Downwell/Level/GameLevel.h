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
	GameLevel(int nType);
	/// <summary>
	/// デストラクター
	/// </summary>
	~GameLevel();
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
	std::list<Actor*> Obj_[2];	//Actor情報
	std::list<Widget*> Widgetobj_[1];	//Widget情報
};