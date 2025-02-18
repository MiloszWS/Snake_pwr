// Cała klasa zaczęrpnięta z  Ather Omar yt GameTimer using Chrono

#include "Timer.h"
namespace EngineUtils {
    EngineUtils::Timer::Timer() {
        Reset();
        mTimeScale=1.0f;
        mDeltaTime=std::chrono::duration<float>(0.0f);
    }

    EngineUtils::Timer::~Timer() {

    }

    Timer* Timer::sInstance= nullptr;

    Timer* Timer::Instance() {
      if(sInstance== nullptr) {
          sInstance = new Timer();
      }
        return sInstance;
    }

    void Timer::Release() {
        delete sInstance;
    }

    void Timer::Reset() {
        mStartTime=std::chrono::system_clock::now();
    }

    float Timer::DeltaTime() {
        return mDeltaTime.count();
    }

    void Timer::TimeScale(float t /*t=1.0f*/) {
        mTimeScale=t;
    }

    float Timer::TimeSclae() {
        return mTimeScale;
    }

    void Timer::Tick() {
        mDeltaTime=std::chrono::system_clock::now()-mStartTime;
    }

}