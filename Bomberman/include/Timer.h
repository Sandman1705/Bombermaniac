#ifndef TIMER_H
#define TIMER_H

/**
 *  \file Timer.h
 *
 *  Defines class Timer which is used with SDL.h to calculate elapsed time
 */

class Timer
{
    public:
        Timer();
        /**
         *  \brief Resets the timer
         *
         *  Resets the time elapsed so that the next call of getTimeElapsed()
         *  gives the number of milliseconds since the last reset.
         */
        void resetTimer();
        /**
         *  \brief Gives time elapsed in milliseconds
         *
         *  Value returned is unsigned long which represents time in milliseconds
         *  since last time the timer was reset or since it was created.
         */
        unsigned long getTimeElapsed();

    protected:

    private:
        unsigned long    pastTicks;
};

#endif // TIMER_H
