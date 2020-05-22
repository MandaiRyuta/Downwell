#pragma once

#include "../Constant.h"

namespace TextureDataBase
{
	/// <summary>
	/// �^�C�g���̃e�N�X�`���[�n���h���ԍ�
	/// </summary>
	enum class TitleTextureNumber
	{
		TBackgroundBlock = 0,
		TOutBlock,
		TBlock,
		TBullet,
		TPlayer,
		TTitleLogo,
	};
	/// <summary>
	/// �Q�[���̃e�N�X�`���[�n���h���ԍ�
	/// </summary>
	enum class GameTextureNumber
	{
		GBackgroundBlock = 0,
		GOutBlock,
		GBlock,
		GSideBlock,
		GBlockInSideBlock,
		GBullet,
		GPlayer,
		GBird,
		GUrchin,
		GTurtle,
		GBulletUI,
		GNonBulletUI,
		GCharacterLife,
		GNotBrokenBlock,
	};
	/// <summary>
	/// ���U���g�̃e�N�X�`���[�n���h���ԍ�
	/// </summary>
	enum class ResultTextureNumber
	{
		RBackgroundBlock = 0,
		ROutBlock,
		RBullet,
		RPlayer,
		RResultLogo,
		RClear,
		RFailed,
	};

	class TextureData
	{
	private:
		/// <summary>
		/// �R���X�g���N�^�[
		/// </summary>
		TextureData() : TitleTexture_(),GameTexture_(),Resulttexture_() {};
		/// <summary>
		/// �f�X�g���N�^�[
		/// </summary>
		~TextureData() {};
	public:
		/// <summary>
		/// �C���X�^���X�擾�֐�
		/// </summary>
		/// <returns>�ÓI��TextureData�C���X�^���X</returns>
		static TextureData& GetInstance()
		{
			static TextureData Inst;
			return Inst;
		}
		/// <summary>
		/// �������֐�
		/// </summary>
		void Init();
		/// <summary>
		/// ���[�f�B���O�֐�
		/// </summary>
		/// <param name="nLevel">���x���ԍ�</param>
		void Loading(int& nLevel);
		/// <summary>
		/// ����֐�
		/// </summary>
		/// <param name="nLevel">���x���ԍ�</param>
		void Release(int& nLevel);

		/// <summary>
		/// �^�C�g���̃e�N�X�`���[�n���h���擾�֐�
		/// </summary>
		/// <param name="Number">�e�N�X�`���[�n���h���ԍ�</param>
		/// <returns>�e�N�X�`���[�n���h��</returns>
		const int& GetTitleTextureData(TextureDataBase::TitleTextureNumber Number);
		/// <summary>
		/// �Q�[���̃e�N�X�`���[�n���h���擾�֐�
		/// </summary>
		/// <param name="Number">�e�N�X�`���[�n���h���ԍ�</param>
		/// <returns>�e�N�X�`���[�n���h��</returns>
		const int& GetGameTextureData(TextureDataBase::GameTextureNumber Number);
		/// <summary>
		/// ���U���g�̃e�N�X�`���[�n���h���擾�֐�
		/// </summary>
		/// <param name="Number">�e�N�X�`���[�n���h���ԍ�</param>
		/// <returns>�e�N�X�`���[�n���h��</returns>
		const int& GetResultTextureData(TextureDataBase::ResultTextureNumber Number);
	private:
		std::array<int, 6> TitleTexture_;	//�^�C�g���̃e�N�X�`���[�n���h��
		std::array<int, 14> GameTexture_;	//�Q�[���̃e�N�X�`���[�n���h��
		std::array<int, 7> Resulttexture_;	//���U���g�̃e�N�X�`���[�n���h��
	};
}