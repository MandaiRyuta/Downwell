#include "LevelsResponsible.h"
#include "GameLevel.h"
#include "../Resource/TextureData.h"
#include "../Input/Input.h"
#include "../Actor/Character.h"

/// <summary>
/// 初期化関数
/// </summary>
void LevelsResponsible::Init()
{
	bLevelState_ = false;
	nNowLevel_ = nTitleLevel;
	bChangeLevel_ = false;
	TextureDataBase::TextureData::GetInstance().Init();
	nNowStage_ = nFirstStage;
	Level_ = new GameLevel(nTitleLevel);
}
/// <summary>
/// 更新関数
/// </summary>
void LevelsResponsible::Update()
{
	if (nNowLevel_ >= 2 && bChangeLevel_ == false)
	{
		if (Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x001)
		{
			nNowLevel_ = 0;
			bChangeLevel_ = true;
		}
	}

	if (Level_ == nullptr) return;

	if (nNowLevel_ == 1)
	{
		Quadtree_[0].x = 0.0f;
		Quadtree_[0].y = Character::GetPos().y + 0.0f;
		Quadtree_[0].width = Character::GetPos().x + static_cast<float>(ScreenWidth) * 0.5f;
		Quadtree_[0].height = ScreenHeight * 0.5f;

		Quadtree_[1].x = (static_cast<float>(ScreenWidth) * 0.5f) + Character::GetPos().x;
		Quadtree_[1].y = (static_cast<float>(-ScreenHeight) * 0.5f) + Character::GetPos().y;
		Quadtree_[1].width = static_cast<float>(ScreenWidth) * 0.5f;
		Quadtree_[1].height = static_cast<float>(ScreenHeight) * 0.5f;

		Quadtree_[2].x = 0.0f;
		Quadtree_[2].y = (static_cast<float>(-ScreenHeight) * 0.5f) + Character::GetPos().y;
		Quadtree_[2].width = Character::GetPos().x + static_cast<float>(ScreenWidth) * 0.5f;
		Quadtree_[2].height = static_cast<float>(ScreenHeight) * 0.5f;
		
		Quadtree_[3].x = (static_cast<float>(ScreenWidth) * 0.5f) + Character::GetPos().x;
		Quadtree_[3].y = 0.0f + Character::GetPos().y;
		Quadtree_[3].width = static_cast<float>(ScreenWidth) * 0.5f;
		Quadtree_[3].height = static_cast<float>(ScreenHeight) * 0.5f;
	}

	Level_->Update();

	if (!bChangeLevel_) return;

	switch (nNowLevel_)
	{
	case 0:
		ChangeLevel(0);
		break;
	case 1:
		ChangeLevel(1);
		break;
	case 2:
		ChangeLevel(2);
		break;
	default:
		break;
	}

	bChangeLevel_ = false;
}
/// <summary>
/// 描画関数
/// </summary>
void LevelsResponsible::Draw()
{
	if (Level_ == nullptr) return;
	Level_->Draw();
}
/// <summary>
/// 解放関数
/// </summary>
void LevelsResponsible::Release()
{
	delete Level_;
}
/// <summary>
/// 終了関数
/// </summary>
void LevelsResponsible::Exit()
{
	nNowLevel_ = nMaxLevel;
}
/// <summary>
/// レベル切り替え関数
/// </summary>
/// <param name="nType">切り替えたいレベル</param>
void LevelsResponsible::ChangeLevel(int nType)
{
	if (Level_ != nullptr)
	{
		delete Level_;
	}

	auto chengelevel = [](int nType)
	{
		switch (nType)
		{
		case 0:
			return new GameLevel(nType);
			break;
		case 1:
			return new GameLevel(nType);
			break;
		case 2:
			return new GameLevel(nType);
			break;
		default:
			return new GameLevel(0);
			break;
		}
	};

	Level_ = chengelevel(nType);
}
/// <summary>
/// レベル取得関数
/// </summary>
/// <returns>現在のレベル</returns>
const int& LevelsResponsible::GetNowLevel()
{
	return nNowLevel_;
}
/// <summary>
/// レベル切り替えフラグ設定関数
/// </summary>
/// <param name="bChangeScene">	true : 切り替える	false : 切り替えない</param>
void LevelsResponsible::SetChangeLevel(bool bChangeScene)
{
	bChangeLevel_ = bChangeScene;
}
/// <summary>
/// レベル切り替えフラグ取得関数
/// </summary>
/// <returns>レベル切り替えフラグ</returns>
const bool& LevelsResponsible::GetChengeLevelExist()
{
	return bChangeLevel_;
}
/// <summary>
/// レベル設定関数
/// </summary>
/// <param name="nLevel">指定したいレベル</param>
void LevelsResponsible::SetNowLevel(int nLevel)
{
	nNowLevel_ = nLevel;
}
/// <summary>
/// 現在のレベルを切り替えてるか確認する関数
/// </summary>
/// <returns>true : 切り替える		false : 切り替えない</returns>
const bool& LevelsResponsible::GetLevelState()
{
	return bLevelState_;
}
/// <summary>
/// 現在のレベルを切り替えるか指定する関数
/// </summary>
/// <param name="bState">true : 切り替える		false : 切り替えない</param>
void LevelsResponsible::SetLevelState(bool bState)
{
	bLevelState_ = bState;
}
/// <summary>
/// 次のレベルを呼ぶ関数
/// </summary>
void LevelsResponsible::NextStage()
{
	if (bNextStage_ == false)
	{
		nNowStage_ += 1;
		bNextStage_ = true;
	}
}
/// <summary>
/// 現在の区画情報を初期化する関数
/// </summary>
void LevelsResponsible::ResetNowStage()
{
	nNowStage_ = nFirstStage;
}
/// <summary>
/// 現在プレイヤーがいる区画を取得する関数
/// </summary>
/// <returns>現在プレイヤーが位置する区画</returns>
const int& LevelsResponsible::GetNowStage()
{
	return nNowStage_;
}
/// <summary>
/// 次の区画に切り替える関数
/// </summary>
/// <param name="bNextStage">true : 切り替える	false : 切り替えない</param>
void LevelsResponsible::SetNextStage(bool bNextStage)
{
	bNextStage_ = bNextStage;
}
/// <summary>
/// 次のレベルに切り替えたか確認する関数
/// </summary>
/// <returns>true : 切り替えている	false : 切り替えてない</returns>
const bool& LevelsResponsible::GetNextStageExist()
{
	return bNextStage_;
}
/// <summary>
/// エリア情報取得関数
/// </summary>
/// <param name="nArea">エリア番号</param>
/// <returns></returns>
Rect& LevelsResponsible::GetQuadTree(int nArea)
{
	return Quadtree_[nArea];
}