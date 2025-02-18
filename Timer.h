// Cała klasa zaczęrpnięta z  Ather Omar yt GameTimer using Chrono

#ifndef SPACEGAME_TIMER_H
#define SPACEGAME_TIMER_H
#include <chrono>

namespace EngineUtils{

    class Timer {
    static Timer* sInstance;

    std::chrono::system_clock::time_point mStartTime;
    std::chrono::duration<float> mDeltaTime;
    float mTimeScale;

    public:

        static Timer* Instance();
        static void Release();
        void Reset();
        float DeltaTime();
        void TimeScale(float t=1.0f);
        float TimeSclae();
        void Tick();

    private:
        Timer();
        ~Timer();
    };
}



#endif //SPACEGAME_TIMER_H
