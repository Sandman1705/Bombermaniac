#ifndef TIMER_H
#define TIMER_H

class Timer
{
    public:
        Timer();
        void resetTimer();
        unsigned int getTimeElapsed();

    protected:

    private:
        unsigned int    pastTicks;
};

#endif // TIMER_H
