#pragma once
#include "../Constant.h"
#include "../DownwellConstant.h"
class EnemyParameter
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	EnemyParameter();
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	virtual ~EnemyParameter() {};
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// �`��֐�
	/// </summary>
	virtual void Draw() = 0;
	/// <summary>
	/// �G��HP�擾�֐�
	/// </summary>
	/// <returns>�G��HP</returns>
	const int& GetHp()
	{
		return nHp_;
	}
	/// <summary>
	/// �G�̍ő�HP�擾�֐�
	/// </summary>
	/// <returns>�G�̍ő�HP</returns>
	const int& GetMaxHp()
	{
		return nMaxHp_;
	}
	/// <summary>
	/// �G�̍��W�擾�֐�
	/// </summary>
	/// <returns>�G�̌��݂̍��W</returns>
	const VECTOR& GetPosition()
	{
		return vPosition_;
	}
	/// <summary>
	/// �G�̍��W��ݒ肷��֐�
	/// </summary>
	/// <param name="vPosition">�w����W</param>
	void SetPosition(VECTOR vPosition)
	{
		vPosition_.x = vPosition.x;
		vPosition_.y = vPosition.y;
		vPosition_.z = vPosition.z;
	}
	/// <summary>
	/// �G�̈ړ��֐�
	/// </summary>
	/// <param name="vMove">�ړ���</param>
	void MovePosition(VECTOR vMove)
	{
		vMove_.x = vMove.x;
		vMove_.y = vMove.y;
		vMove_.z = vMove.z;
	}
	/// <summary>
	/// �G��Y���W�ړ��֐�
	/// </summary>
	/// <param name="fMovey">Y���W�̈ړ���</param>
	void AddMovePositionY(float fMovey)
	{
		vMove_.y += fMovey;
	}
	/// <summary>
	/// �G��X���W�ړ��֐�
	/// </summary>
	/// <param name="fMovex">X���W�̈ړ���</param>
	void AddMovePositionX(float fMovex)
	{
		vMove_.x += fMovex;
	}
	/// <summary>
	/// �G�̈ړ���ގw��֐�
	/// </summary>
	/// <param name="nType">�ړ����</param>
	void SetMoveType(int nType)
	{
		nMoveType_ = nType;
	}
	/// <summary>
	/// �G�̈ړ����擾�֐�
	/// </summary>
	/// <returns>�w�肵���ړ����</returns>
	const int& GetMoveType()
	{
		return nMoveType_;
	}
	/// <summary>
	/// �G�̏Փˊ֐�
	/// </summary>
	/// <param name="bBottomtouch">true : ���n	false : ���n���Ă��Ȃ�</param>
	void SetBottomTouch(bool bBottomtouch)
	{
		bBottomtouch_ = bBottomtouch;
	}
	/// <summary>
	/// �G�̕`��ԍ��ݒ�֐�
	/// </summary>
	/// <param name="nNumber">�`��ԍ�</param>
	void SetEnemyNumber(int nNumber)
	{
		nEnemyNumber_ = nNumber;
	}
	/// <summary>
	/// �G�̕`��ԍ��擾�֐�
	/// </summary>
	/// <returns>�w�肵���`��ԍ�</returns>
	const int& GetEnemyNumber()
	{
		return nEnemyNumber_;
	}
	/// <summary>
	/// �G�̐����擾�֐�
	/// </summary>
	/// <returns>true : �������Ă���@false : ����ł���</returns>
	const bool& GetbLifeExist()
	{
		return bLife_;
	}
	/// <summary>
	/// �G�̐����w��֐�
	/// </summary>
	/// <param name="bLife">true : �������Ă���@false : ����ł���</param>
	void SetbLife(bool bLife)
	{
		bLife_ = bLife;
	}
protected:
	bool bLife_;	//�����t���O
	int nEnemyNumber_;	//�G�̕`��ԍ�
	int nMoveType_;	//�G�̈ړ����
	int nHp_;	//�G��HP
	int nMaxHp_;	//�G�̍ő�HP
	bool bBottomtouch_;	//�G�̒n�ʏՓ˃t���O
	VECTOR vPosition_;	//�G�̍��W
	VECTOR vMove_;	//�G�̈ړ���
};