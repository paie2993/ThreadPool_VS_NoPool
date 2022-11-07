//
// Created by PopescuAd on 11/7/2022.
//

#include <vector>
#include <thread>
#include "ThreadsManagement.h"

void joinThreads(std::vector<std::thread *> &threads) {
    for (auto thread: threads) {
        thread->join();
    }
}

void deallocateThreads(std::vector<std::thread *> &threads) {
    for (auto thread: threads) {
        delete thread;
    }
}
