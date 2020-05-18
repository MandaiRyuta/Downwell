#pragma once

class StageDataBase
{
private:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	StageDataBase() : nStage_() {}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~StageDataBase() {}
public:
	/// <summary>
	/// �C���X�^���X�擾�֐�
	/// </summary>
	/// <returns>�ÓI��StageDataBase�C���X�^���X</returns>
	static StageDataBase& GetInstance()
	{
		static StageDataBase Inst;
		return Inst;
	}
	/// <summary>
	/// �X�e�[�W�������֐�
	/// </summary>
	void InitStage();
	/// <summary>
	/// �w�肵���u���b�N�̏����擾����֐�
	/// </summary>
	/// <param name="type">���</param>
	/// <param name="x">X���W</param>
	/// <param name="y">Y���W</param>
	/// <returns></returns>
	int GetStageType(int type, int x, int y);
private:
	int nStage_[12][50][20];	//�����
};