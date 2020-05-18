#include "EnemySeaUrchin.h"
#include "../Behaviour/BehaviorData.h"
#include "../Behaviour/BehaviorTree.h"
#include "../Behaviour/LoiteringMoveAction.h"
#include "../Behaviour/Node.h"
#include "../Constant.h"
#include "Bullet.h"
#include "Character.h"
#include "../Resource/TextureData.h"
#include "../Collision/Collision.h"
#include "../Level/LevelsResponsible.h"
/// <summary>
/// コンストラクター
/// </summary>
/// <param name="enemynumber">敵の描画番号</param>
/// <param name="aitree">ビヘイビアツリー</param>
/// <param name="nhp">ウニのHP</param>
/// <param name="nspeed">ウニの移動量</param>
/// <param name="vposition">ウニが出現する座標</param>
EnemySeaUrchin::EnemySeaUrchin(int enemynumber, BehaviorTree aitree, int nhp, int nspeed, VECTOR vposition) :
	Activenode_(nullptr),
	AIData_(nullptr),
	bActive_(false)
{
	bLife_ = true;
	AITree_ = aitree;
	nHp_ = nhp;
	nMaxHp_ = nhp;
	nSpeed_ = nspeed;
	nMaxSpeed_ = nspeed;
	nMoveType_ = 0;
	vMove_ = VGet(1.0f, 0.0f, 0.0f);
	vPosition_ = vposition;
	AIData_ = new BehaviorData;
	nTexhandle_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GUrchin);
	nEnemyNumber_ = enemynumber;
	bHitAction_ = true;
}
/// <summary>
/// デストラクター
/// </summary>
EnemySeaUrchin::~EnemySeaUrchin()
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
void EnemySeaUrchin::Update()
{
	bActive_ = false;
	bool bactive = false;
	Rect rc(vPosition_.x - 8.0f, vPosition_.y - 8.0f, 16.0f, 16.0f);
	for (int i = 0; i < 4; i++)
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
			if (Character::GetPos().x + 9.0f >= vPosition_.x + -9.0f && Character::GetPos().y - 7.0f < vPosition_.y + 6.0f &&
				Character::GetPos().x - 9.0f <= vPosition_.x + 9.0f && Character::GetPos().y - 7.0f > vPosition_.y + 9.0f && bHitAction_ == false)
			{
				Character::SetHitDamage(true);
				bHitAction_ = true;
			}

			for (int i = 0; i < 10; i++)
			{
				if (Bullet::GetPosition(i).x - 6.0f >= vPosition_.x - 14.0f && Bullet::GetPosition(i).y < vPosition_.y + 7.0f &&
					Bullet::GetPosition(i).x + 6.0f <= vPosition_.x + 14.0f && Bullet::GetPosition(i).y > vPosition_.y)
				{
					if (nHp_ > 0)
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
void EnemySeaUrchin::Draw()
{
	if (bLife_)
	{
		DrawBillboard3D(vPosition_, 0.5f, 0.5f, 16.0f, 0.0f, nTexhandle_, false);
	}
}
