#include "EnemyBird.h"
#include "../Behaviour/BehaviorData.h"
#include "../Behaviour/BehaviorTree.h"
#include "../Behaviour/TrackingMoveAction.h"
#include "../Behaviour/Node.h"
#include "../Constant.h"
#include "Bullet.h"
#include "Character.h"
#include "CharacterJump.h"
#include "../Resource/TextureData.h"
#include "../Level/LevelsResponsible.h"
#include "../Collision/Collision.h"

/// <summary>
/// コンストラクター
/// </summary>
/// <param name="enemynumber">敵の描画番号</param>
/// <param name="aitree">ビヘイビアツリー</param>
/// <param name="nhp">鳥のHP</param>
/// <param name="nspeed">鳥の移動量</param>
/// <param name="vposition">鳥が出現する座標</param>
EnemyBird::EnemyBird(int enemynumber, BehaviorTree aitree, int nhp, VECTOR vposition) :
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
	nTexhandle_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GBird);
	nEnemyNumber_ = enemynumber;
	bHitAction_ = bInitEnemyHitAction;
}
/// <summary>
/// デストラクター
/// </summary>
EnemyBird::~EnemyBird()
{
	if (AIData_ != nullptr)
	{
		AIData_->PopSequenceNode();
		delete AIData_;
	}

	AITree_.Release();
}
/// <summary>
/// 更新関数
/// </summary>
void EnemyBird::Update()
{
	bActive_ = bInitActive;
	bool bactive = bInitActive;
	Rect rc(vPosition_.x - fBirdRectPadding, vPosition_.y - fBirdRectPadding, fBirdTextureScale, fBirdTextureScale);
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
			if (Character::GetPos().x + 9.0f >= vPosition_.x + -9.0f && Character::GetPos().y + 7.0f < vPosition_.y - 6.0f &&
				Character::GetPos().x - 9.0f <= vPosition_.x + 9.0f && Character::GetPos().y + 7.0f > vPosition_.y - 9.0f && bHitAction_ == false)
			{
				Character::SetHitDamage(true);
				bHitAction_ = true;
			}
			if (Character::GetPos().x >= vPosition_.x + -9.0f && Character::GetPos().y + 7.0f < vPosition_.y + 14.0f &&
				Character::GetPos().x <= vPosition_.x + 9.0f && Character::GetPos().y + 7.0f > vPosition_.y + 9.0f && Character::GetJumpExist() == false && bHitAction_ == false)
			{
				Character::SetHitEnemy(true);
				if (nHp_ > nZeroLife)
				{
					nHp_--;
				}
				bHitAction_ = true;
			}

			for (int i = 0; i < nBulletMaxCount; i++)
			{
				if (Bullet::GetPosition(i).x - 6.0f >= vPosition_.x - 18.0f && Bullet::GetPosition(i).y < vPosition_.y + 7.0f &&
					Bullet::GetPosition(i).x + 6.0f <= vPosition_.x + 18.0f && Bullet::GetPosition(i).y > vPosition_.y)
				{
					if (nHp_ > nZeroLife)
					{
						nHp_--;
					}
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
void EnemyBird::Draw()
{
	if (bLife_)
	{
		DrawBillboard3D(vPosition_, 0.5f, 0.5f, 18.0f, 0.0f, nTexhandle_, false);
	}
}