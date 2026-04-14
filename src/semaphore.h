#ifndef SEMAPHORE
#define SEMAPHORE
#include "thread.h"
#include <queue>
#include <iostream>

class Semaphore{
    private:
        int count;
        std::queue<Thread> taskList;
    public:
        Semaphore();
        void wait(Thread);
        void signal();
        void execute();
};

#endif