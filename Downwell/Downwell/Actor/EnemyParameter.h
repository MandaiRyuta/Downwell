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
	/// <param name="position">�w����W</param>
	void SetPosition(VECTOR position)
	{
		vPosition_.x = position.x;
		vPosition_.y = position.y;
		vPosition_.z = position.z;
	}
	/// <summary>
	/// �G�̈ړ��֐�
	/// </summary>
	/// <param name="move">�ړ���</param>
	void MovePosition(VECTOR move)
	{
		vMove_.x = move.x;
		vMove_.y = move.y;
		vMove_.z = move.z;
	}
	/// <summary>
	/// �G��Y���W�ړ��֐�
	/// </summary>
	/// <param name="fmovey">Y���W�̈ړ���</param>
	void AddMovePositionY(float fmovey)
	{
		vMove_.y += fmovey;
	}
	/// <summary>
	/// �G��X���W�ړ��֐�
	/// </summary>
	/// <param name="fmovex">X���W�̈ړ���</param>
	void AddMovePositionX(float fmovex)
	{
		vMove_.x += fmovex;
	}
	/// <summary>
	/// �G�̈ړ���ގw��֐�
	/// </summary>
	/// <param name="ntype">�ړ����</param>
	void SetMoveType(int ntype)
	{
		nMoveType_ = ntype;
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
	/// <param name="bbottomtouch">true : ���n	false : ���n���Ă��Ȃ�</param>
	void SetBottomTouch(bool bbottomtouch)
	{
		bBottomtouch_ = bbottomtouch;
	}
	/// <summary>
	/// �G�̕`��ԍ��ݒ�֐�
	/// </summary>
	/// <param name="nnumber">�`��ԍ�</param>
	void SetEnemyNumber(int nnumber)
	{
		nEnemyNumber_ = nnumber;
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
	/// <param name="blife">true : �������Ă���@false : ����ł���</param>
	void SetbLife(bool blife)
	{
		bLife_ = blife;
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