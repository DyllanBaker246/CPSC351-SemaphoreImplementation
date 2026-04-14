#include "semaphore.h"

Semaphore::Semaphore(){
    count = 1;
}

void Semaphore::wait(Thread task){
    taskList.push(task); // adds task to task queue
    if(count == 1){ // if critical section is free
        count--; // decrement to 0
        std::cout << "Task " << task.getId() << " in critical section\n";
    } else{ // if critical section is occupied
        std::cout << "Task " << task.getId() << " waiting...\n";
    }
}

void Semaphore::signal(){
    if(count == 0){ // if critical section is in use
        count++; // increment count
        std::cout << "Task " << taskList.front().getId() << " is leaving critical section\n";
        taskList.pop(); // remove completed thread from the queue
    }else{ // edge case: if critical section was already free
        std::cout << "Critical Section is free\n";
    }

    if(taskList.size() > 0){
        // if there are still threads in the queue, add the next to the critical section
        std::cout << "Task " << taskList.front().getId() << " in critical section\n";
        count--;
    }
}

void Semaphore::execute(){
    int taskCount = 0; // keeps track of number of tasks completed
    if(count == 1){
        // if critical section is free, nothing to be done
        std::cout << "No tasks to be compleated\n";
        return;
    }

    while(taskList.size() > 0){
        taskList.front().work(); // executes thread operation
        signal(); // indicates thread is completed
        taskCount++;
    }
    if(count == 1) // if critical section is free, nothing more to be done
        std::cout << "\nCritical Section is free\nNumber of tasks completed: " << taskCount << '\n';
}