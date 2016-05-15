#ifndef TIMER_H
#define TIMER_H

/**
 *  \file Timer.h
 *
 *  Defines class Timer which is used with SDL.h to calculate elapsed time
 */

/** \class Timer
 *  \brief class for measuring time
 *  \details This is an utility class for measuring time which can be used for
 *           properly timing events.
 */
class Timer
{
    public:
        /**
         *  \brief Make new timer and set it to 0.
         *
         *  Basic constructor which makes new timer class and sets it's value
         *  to 0.
         */
        Timer();
        /**
         *  \brief Resets the timer
         *
         *  Resets the time elapsed so that the next call of getTimeElapsed()
         *  gives the number of milliseconds since the last reset.
         *
         *  \return void
         */
        void ResetTimer();

        void DecreaseTimer(unsigned long interval);
        /**
         *  \brief Gives time elapsed in milliseconds
         *
         *  Value returned is unsigned long which represents time in
         *  milliseconds since last time the timer was reset or since it was
         *  created.
         *
         *  \return number of milliseconds since last reset
         */
        unsigned long GetTimeElapsed();

    protected:

    private:
        unsigned long    m_pastTicks;
};

#endif // TIMER_H
