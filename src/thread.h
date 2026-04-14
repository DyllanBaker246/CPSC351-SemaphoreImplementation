#ifndef THREAD
#define THREAD
#include <iostream>

class Thread{
    private:
        int id;
    public:
        Thread(int);
        int getId();
        void work();
};

#endif