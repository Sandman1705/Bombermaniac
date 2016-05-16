#ifndef SCREENTIMER_H
#define SCREENTIMER_H

/**
 *  \file ScreenTimer.h
 *
 *  Defines class ScreenTimer which is used with SDL.h to calculate elapsed time
 */

/** \class ScreenTimer
 *  \brief class for measuring time
 *  \details This is an utility class for measuring time which can be used for
 *           properly timing events.
 */
class ScreenTimer
{
    public:

        static ScreenTimer* Instance();

        void ResetTimer();
        void DecreaseTimer(unsigned long interval);
        unsigned long GetTimeElapsed() const;
        void Pause();
        void Unpause();
        bool IsPaused() const;


    protected:

        ScreenTimer();

    private:
        unsigned long       m_past_ticks;
        unsigned long       m_paused_ticks;
        bool                m_paused;

        static ScreenTimer* s_instance;

};

#endif // SCREENTIMER_H
