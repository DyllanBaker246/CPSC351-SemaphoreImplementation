#include "semaphore.h"

Semaphore::Semaphore(){
    count = 1;
}

void Semaphore::wait(Thread task){
    taskList.push(task);
    if(count == 1){
        count--;
        std::cout << "Task " << task.getId() << " in critical section\n";
    } else{
        std::cout << "Task " << task.getId() << " waiting...\n";
    }
}

void Semaphore::signal(){
    if(count == 0){
        count++;
        std::cout << "Task " << taskList.front().getId() << " is leaving critical section\n";
        taskList.pop();
    }else{
        std::cout << "Critical Section is free\n";
    }

    if(taskList.size() > 0){
        std::cout << "Task " << taskList.front().getId() << " in critical section\n";
        count--;
    }
}

void Semaphore::execute(){
    int taskCount = 0;
    if(count == 1){
        std::cout << "No tasks to be compleated\n";
        return;
    }

    while(taskList.size() > 0){
        taskList.front().work();
        signal();
        //std::cout << "COUNT: " << count << '\n';
        taskCount++;
    }
    if(count == 1)
        std::cout << "\nCritical Section is free\nNumber of tasks completed: " << taskCount << '\n';
}