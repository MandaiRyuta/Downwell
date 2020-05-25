#pragma once
#include "EnemyParameter.h"
#include "../Behaviour/BehaviorTree.h"
class BehaviorData;
class Node;

class EnemyTurtle : public EnemyParameter
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	/// <param name="nEnemyNumber">�G�̕`��ԍ�</param>
	/// <param name="AiTree">�r�w�C�r�A�c���[</param>
	/// <param name="nHp">�T��HP</param>
	/// <param name="vPosition">�T���o��������W</param>
	EnemyTurtle(int nEnemyNumber, BehaviorTree AiTree, int nHp, VECTOR vPosition);
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~EnemyTurtle();
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
	void TurtleHitCollision();
	/// <summary>
	/// �T���s�����s���֐�
	/// </summary>
	void TurtleMoveAction();
private:
	BehaviorData* AIData_;	//�r�w�C�r�A�f�[�^�N���X
	BehaviorTree AITree_;	//�r�w�C�r�A�c���[�N���X
	Node* Activenode_;	//�m�[�h�N���X
	int nTexhandle_;	//�e�N�X�`���[�n���h��
	bool bHitAction_;	//�Փ˃t���O
	bool bActive_;	//�A�N�e�B�u�t���O
};