#include "semaphore.h"
#include "thread.h"

int main(){
    // Create threads
    Thread t1(1);
    Thread t2(2);
    Thread t3(3);
    Thread t4(4);
    Thread t5(5);

    Semaphore sem; // create semaphore object

    // call the wait function for each thread
    sem.wait(t1);
    sem.wait(t2);
    sem.wait(t3);
    sem.wait(t4);
    sem.wait(t5);

    sem.execute(); // execute tasks
    return 0;
}