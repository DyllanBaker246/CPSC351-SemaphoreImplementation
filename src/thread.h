#ifndef THREAD
#define THREAD
#include <iostream>

class Thread{
    private:
        int id;
            // Identification number of thread
    public:
        Thread(int);
            // thread constructor, need thread id
        int getId();
            // returns thread id
        void work();
            // function simulates thread completing an operation in critical section
};

#endif