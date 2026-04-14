#include "thread.h"

Thread::Thread(int num){
    id = num;
}

int Thread::getId(){
    return id;
}
void Thread::work(){
    std::cout << "Thread " << id << " is executing...\n";

    // Use of critical section would be here

    std::cout << "Thread " << id << " is complete\n";
}