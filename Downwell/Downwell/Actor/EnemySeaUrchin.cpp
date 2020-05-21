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
/// �R���X�g���N�^�[
/// </summary>
/// <param name="enemynumber">�G�̕`��ԍ�</param>
/// <param name="aitree">�r�w�C�r�A�c���[</param>
/// <param name="nhp">�E�j��HP</param>
/// <param name="nspeed">�E�j�̈ړ���</param>
/// <param name="vposition">�E�j���o��������W</param>
EnemySeaUrchin::EnemySeaUrchin(int enemynumber, BehaviorTree aitree, int nhp, VECTOR vposition) :
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
	nTexhandle_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GUrchin);
	nEnemyNumber_ = enemynumber;
	bHitAction_ = bInitEnemyHitAction;
}
/// <summary>
/// �f�X�g���N�^�[
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
/// �X�V�֐�
/// </summary>
void EnemySeaUrchin::Update()
{
	bActive_ = false;
	bool bactive = false;
	Rect rc(vPosition_.x - fUrchinRectPadding, vPosition_.y - fUrchinRectPadding, fUrchinTextureScale, fUrchinTextureScale);
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

			if (Character::GetPos().x - 8.0f <= vPosition_.x + 8.0f && Character::GetPos().y - 8.0f < vPosition_.y + 8.0f &&
				Character::GetPos().x - 8.0f >= vPosition_.x + 8.0f && Character::GetPos().y + 8.0f > vPosition_.y - 8.0f && bHitAction_ == false)
			{
				Character::SetHitLeftDamage(true);
				bHitAction_ = true;
			}
			if (Character::GetPos().x + 8.0f <= vPosition_.x - 8.0f && Character::GetPos().y - 8.0f < vPosition_.y + 8.0f &&
				Character::GetPos().x + 8.0f >= vPosition_.x - 8.0f && Character::GetPos().y + 8.0f > vPosition_.y - 8.0f && bHitAction_ == false)
			{
				Character::SetHitRightDamage(true);
				bHitAction_ = true;
			}

			if (Character::GetPos().x + 11.0f >= vPosition_.x - 11.0f && Character::GetPos().y + 8.0f < vPosition_.y - 11.0f &&
				Character::GetPos().x <= vPosition_.x - 2.0f && Character::GetPos().y + 8.0f > vPosition_.y - 11.0f && bHitAction_ == false)
			{
				Character::SetHitRightDamage(true);
				bHitAction_ = true;
			}
			if (Character::GetPos().x - 8.0f >= vPosition_.x + 11.0f && Character::GetPos().y + 8.0f < vPosition_.y - 11.0f &&
				Character::GetPos().x <= vPosition_.x + 2.0f && Character::GetPos().y + 11.0f > vPosition_.y - 11.0f && bHitAction_ == false)
			{
				Character::SetHitLeftDamage(true);
				bHitAction_ = true;
			}
			if (Character::GetPos().x + 8.0f >= vPosition_.x - 11.0f && Character::GetPos().y - 8.0f < vPosition_.y + 11.0f &&
				Character::GetPos().x <= vPosition_.x - 2.0f && Character::GetPos().y - 8.0f > vPosition_.y + 11.0f && bHitAction_ == false)
			{
				Character::SetHitRightDamage(true);
				bHitAction_ = true;
			}
			if (Character::GetPos().x - 8.0f >= vPosition_.x + 11.0f && Character::GetPos().y - 8.0f < vPosition_.y + 11.0f &&
				Character::GetPos().x <= vPosition_.x + 2.0f && Character::GetPos().y - 8.0f > vPosition_.y + 11.0f && bHitAction_ == false)
			{
				Character::SetHitLeftDamage(true);
				bHitAction_ = true;
			}

			for (int i = 0; i < nBulletMaxCount; i++)
			{
				if (Bullet::GetPosition(i).x - 6.0f >= vPosition_.x - 11.0f && Bullet::GetPosition(i).y - 6.0f < vPosition_.y + 11.0f &&
					Bullet::GetPosition(i).x + 6.0f <= vPosition_.x + 11.0f && Bullet::GetPosition(i).y + 6.0f > vPosition_.y - 11.0f)
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
/// �`��֐�
/// </summary>
void EnemySeaUrchin::Draw()
{
	if (bLife_)
	{
		DrawBillboard3D(vPosition_, 0.5f, 0.5f, 16.0f, 0.0f, nTexhandle_, false);
	}
}
