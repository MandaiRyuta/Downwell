#include "FpsCounter.h"
#include "../Constant.h"
/// <summary>
/// 更新関数
/// </summary>
void FPS::FpsCounter::Update()
{
	if (unTimeCount_ == 0)
	{
		unStartTime_ = GetNowCount();
	}
	else if (unTimeCount_ == FPS::FpsFrame)
	{
		int t = GetNowCount();
		fFps_ = 1000.f / ((t - unStartTime_) / (float)FPS::FpsFrame);
		unTimeCount_ = 0;
		unStartTime_ = t;
	}
	unTimeCount_++;
}
/// <summary>
/// 描画関数
/// </summary>
void FPS::FpsCounter::Draw()
{
#ifdef DEBUG
	DrawFormatString(0, 0, GetColor(255,255,255), "%.1f", fFps_);
#endif
}
/// <summary>
/// 待機時間
/// </summary>
void FPS::FpsCounter::WaitTime()
{
	int passagetime = GetNowCount() - unStartTime_;
	int waittime = unTimeCount_ * 1000 / FPS::FpsFrame - passagetime;

	if (waittime > 0)
	{
		Sleep(waittime);
	}
}
