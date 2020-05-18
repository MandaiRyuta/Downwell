#pragma once

namespace FPS
{
	constexpr int FpsFrame = 60;	//フレーム最大値

	class FpsCounter
	{
	public:
		/// <summary>
		/// コンストラクター
		/// </summary>
		FpsCounter() {
			unStartTime_ = 0;
			unTimeCount_ = 0;
			fFps_ = 0;
		}
		/// <summary>
		/// デストラクター
		/// </summary>
		~FpsCounter()
		{
			unStartTime_ = 0;
			unTimeCount_ = 0;
			fFps_ = 0;
		}
		/// <summary>
		/// 更新関数
		/// </summary>
		void Update();
		/// <summary>
		/// 描画関数
		/// </summary>
		void Draw();
		/// <summary>
		/// 待機時間
		/// </summary>
		void WaitTime();
	private:
		unsigned int unStartTime_;	//開始時間
		unsigned int unTimeCount_;	//時間
		float fFps_;	//現在のフレーム
	};
}