#pragma once
#include "EnemyParameter.h"
#include "../Behaviour/BehaviorTree.h"

class BehaviorData;	//�r�w�C�r�A�f�[�^�N���X
class Node;	//�m�[�h�N���X

class EnemyBird : public EnemyParameter
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	/// <param name="nEnemyNumber">�G�̕`��ԍ�</param>
	/// <param name="AiTree">�r�w�C�r�A�c���[</param>
	/// <param name="nHp">����HP</param>
	/// <param name="vPosition">�����o��������W</param>
	EnemyBird(int nEnemyNumber, BehaviorTree AiTree, int nHp, VECTOR vPosition);
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~EnemyBird();
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`��֐�
	/// </summary>
	virtual void Draw() override;

	/// <summary>
	/// �N�A�b�h�c���[���ɂ��邩�ǂ������m�F����֐�
	/// </summary>
	void QuadTreeCheckCollision();
	/// <summary>
	/// �v���C���[��u���b�N�Ƃ̏Փ˔���֐�
	/// </summary>
	void BirdHitCollision();
	/// <summary>
	/// �����s�����s���֐�
	/// </summary>
	void BirdMoveAction();
private:
	BehaviorData* AIData_;	//�r�w�C�r�A�f�[�^�N���X
	BehaviorTree AITree_;	//�r�w�C�r�A�c���[�N���X
	Node* Activenode_;	//�m�[�h�N���X
	int nTexhandle_;	//�e�N�X�`���[�n���h��
	bool bHitAction_;	//�Փ˃t���O
	bool bActive_;	//�A�N�e�B�u�t���O
};