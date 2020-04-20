#pragma once

namespace FPS
{
	constexpr int Fps_N = 60;
	constexpr int FpsFrame = 60;

	class FpsCounter
	{
	public:
		FpsCounter() {
			StartTime_ = 0;
			TimeCount_ = 0;
			Fps_ = 0;
		}
		~FpsCounter()
		{
			StartTime_ = 0;
			TimeCount_ = 0;
			Fps_ = 0;
		}
		void Update();
		void Draw();
		void WaitTime();
	private:
		unsigned int StartTime_;
		unsigned int TimeCount_;
		float Fps_;
	};
}