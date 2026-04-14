/***********************************
* Name: Dyllan Cummings
* Assignment: Semaphore Implentation
* File: semaphore.h
*************************************/
#ifndef SEMAPHORE
#define SEMAPHORE
#include "thread.h"
#include <queue>
#include <iostream>

class Semaphore{
    private:
        int count;
            // count indicates how many resorces are accessing the critical section
            // 1 indicates critical section is free, 0 means resorce is taken
        std::queue<Thread> taskList;
            // queue of tasks to be completed
    public:
        Semaphore();
            // Semaphore constructor
            // sets count to 1 (binary semaphore)
        void wait(Thread);
            // Adds thread to queue
            // if count == 1, then thread is put in the critical section
            // else thread waits
        void signal();
            // when task completes, updates count to indicate
            // critical section is free
        void execute();
            // executes tasks in taskList
};

#endif