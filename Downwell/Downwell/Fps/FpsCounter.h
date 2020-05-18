#pragma once

namespace FPS
{
	constexpr int FpsFrame = 60;	//�t���[���ő�l

	class FpsCounter
	{
	public:
		/// <summary>
		/// �R���X�g���N�^�[
		/// </summary>
		FpsCounter() {
			unStartTime_ = 0;
			unTimeCount_ = 0;
			fFps_ = 0;
		}
		/// <summary>
		/// �f�X�g���N�^�[
		/// </summary>
		~FpsCounter()
		{
			unStartTime_ = 0;
			unTimeCount_ = 0;
			fFps_ = 0;
		}
		/// <summary>
		/// �X�V�֐�
		/// </summary>
		void Update();
		/// <summary>
		/// �`��֐�
		/// </summary>
		void Draw();
		/// <summary>
		/// �ҋ@����
		/// </summary>
		void WaitTime();
	private:
		unsigned int unStartTime_;	//�J�n����
		unsigned int unTimeCount_;	//����
		float fFps_;	//���݂̃t���[��
	};
}