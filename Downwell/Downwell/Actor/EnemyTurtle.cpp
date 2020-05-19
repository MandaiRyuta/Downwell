#include "EnemyTurtle.h"
#include "../Behaviour/BehaviorData.h"
#include "../Behaviour/BehaviorTree.h"
#include "../Behaviour/TurnMoveAction.h"
#include "../Behaviour/Node.h"
#include "../Constant.h"
#include "Bullet.h"
#include "Character.h"
#include "CharacterJump.h"
#include "../Resource/TextureData.h"
#include "../Collision/Collision.h"
#include "../Level/LevelsResponsible.h"
/// <summary>
/// コンストラクター
/// </summary>
/// <param name="enemynumber">敵の描画番号</param>
/// <param name="aitree">ビヘイビアツリー</param>
/// <param name="nhp">亀のHP</param>
/// <param name="nspeed">亀の移動量</param>
/// <param name="vposition">亀が出現する座標</param>
EnemyTurtle::EnemyTurtle(int enemynumber, BehaviorTree aitree, int nhp, VECTOR vposition) :
	Activenode_(nullptr),
	AIData_(nullptr),
	bActive_(bInitActive)
{
	bLife_ = bInitEnemyLife;
	AITree_ = aitree;
	nHp_ = nhp;
	nMaxHp_ = nhp;
	nMoveType_ = nInitEnemyMoveType;
	vMove_ = VGet(fDefaultPos, fDefaultPos, fDefaultPos);
	vPosition_ = vposition;
	AIData_ = new BehaviorData;
	nTexhandle_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GTurtle);
	nEnemyNumber_ = enemynumber;
	bHitAction_ = bInitEnemyHitAction;
}
/// <summary>
/// デストラクター
/// </summary>
EnemyTurtle::~EnemyTurtle()
{
	if (AIData_ != nullptr)
	{
		delete AIData_;
	}

	AITree_.Release();
}
/// <summary>
/// 更新関数
/// </summary>
void EnemyTurtle::Update()
{
	bActive_ = false;
	bool bactive = false;
	Rect rc(vPosition_.x - fTurtleRectPadding, vPosition_.y - fTurtleRectPadding, fTurtleTextureScale, fTurtleTextureScale);
	for (int i = 0; i < nQuadTreeMaxCount; i++)
	{
		bactive = LevelsResponsible::GetInstance().GetQuadTree(i).HitCheck(rc);

		if (bactive)
		{
			bActive_ = true;
		}
	}

	if (bActive_)
	{
		if (bLife_)
		{
			bHitAction_ = false;

			for (int i = 0; i < nBulletMaxCount; i++)
			{
				if (Bullet::GetPosition(i).x - 6.0f >= vPosition_.x - 14.0f && Bullet::GetPosition(i).y < vPosition_.y + 7.0f &&
					Bullet::GetPosition(i).x + 6.0f <= vPosition_.x + 14.0f && Bullet::GetPosition(i).y > vPosition_.y)
				{
					if (nHp_ > nZeroLife)
					{
						nHp_--;
					}
				}
			}

			if (Character::GetPos().x - 9.0f <= vPosition_.x + 9.0f && Character::GetPos().y + 8.0f < vPosition_.y + 9.0f &&
				Character::GetPos().x - 9.0f >= vPosition_.x + 6.0f && Character::GetPos().y - 8.0f > vPosition_.y - 9.0f && bHitAction_ == false)
			{
				Character::SetHitLeftDamage(true);
				bHitAction_ = true;
			}
			if (Character::GetPos().x + 9.0f <= vPosition_.x - 6.0f && Character::GetPos().y + 8.0f < vPosition_.y + 9.0f &&
				Character::GetPos().x + 9.0f >= vPosition_.x - 9.0f && Character::GetPos().y - 8.0f > vPosition_.y - 9.0f && bHitAction_ == false)
			{
				Character::SetHitRightDamage(true);
				bHitAction_ = true;
			}

			if (Character::GetPos().x - 6.0f >= vPosition_.x - 16.0f && Character::GetPos().y < vPosition_.y + 7.0f &&
				Character::GetPos().x + 6.0f <= vPosition_.x + 16.0f && Character::GetPos().y > vPosition_.y && Character::GetJumpExist() == false)
			{
				Character::SetHitEnemy(true);
				if (nHp_ > nZeroLife)
				{
					nHp_--;
				}
			}

			if (Activenode_ == nullptr)
			{
				Activenode_ = AITree_.Inference(this, AIData_);
			}
			if (Activenode_ != nullptr)
			{
				Activenode_ = AITree_.Run(this, Activenode_, AIData_);
			}

			vPosition_.x += vMove_.x;
			vPosition_.y += vMove_.y;
		}
	}
}
/// <summary>
/// 描画関数
/// </summary>
void EnemyTurtle::Draw()
{
	if (bLife_)
	{
		DrawBillboard3D(vPosition_, 0.5f, 0.5f, 18.0f, 0.0f, nTexhandle_, false);
	}
}