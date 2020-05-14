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
EnemyBird::EnemyBird(int enemynumber, BehaviorTree aitree, int nhp, int nspeed, VECTOR vposition) :
	Activenode_(nullptr),
	AIData_(nullptr)
{
	bLife_ = true;
	AITree_ = aitree;
	nHp_ = nhp;
	nMaxHp_ = nhp;
	nSpeed_ = nspeed;
	nMaxSpeed_ = nspeed;
	nMoveType_ = 0;
	vMove_ = VGet(0.0f, 0.0f, 0.0f);
	vPosition_ = vposition;
	AIData_ = new BehaviorData;
	nTexhandle_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GBird);
	nEnemyNumber_ = enemynumber;
	bHitAction_ = false;
}

EnemyBird::~EnemyBird()
{
	if (AIData_ != nullptr)
	{
		AIData_->PopSequenceNode();
		delete AIData_;
	}

	AITree_.Release();
}

void EnemyBird::Update()
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
		if (Character::GetPos().x + 9.0f <= vPosition_.x -6.0f && Character::GetPos().y + 8.0f < vPosition_.y + 9.0f &&
			Character::GetPos().x + 9.0f >= vPosition_.x -9.0f && Character::GetPos().y - 8.0f > vPosition_.y - 9.0f && bHitAction_ == false)
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
			Character::GetPos().x <= vPosition_.x + 9.0f && Character::GetPos().y + 7.0f > vPosition_.y + 9.0f&& CharacterJump::GetJumpExist() == false && bHitAction_ == false)
		{
			Character::SetHitEnemy(true);
			if (nHp_ > 0)
			{
				nHp_--;
			}
			bHitAction_ = true;
		}
		
		for (int i = 0; i < 10; i++)
		{
			if (Bullet::GetPosition(i).x - 6.0f >= vPosition_.x + -14.0f && Bullet::GetPosition(i).y < vPosition_.y + 7.0f &&
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

void EnemyBird::Draw()
{
	if (bLife_)
	{
		DrawBillboard3D(vPosition_, 0.5f, 0.5f, 18.0f, 0.0f, nTexhandle_, false);
	}
}