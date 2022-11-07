#pragma once

#include <mutex>
#include <condition_variable>
#include <list>
#include <vector>

class ThreadPool {

private:
    std::mutex m_mutex;
    std::condition_variable m_cond;
    std::list<std::function<void()> > m_queue;

    bool m_end;
    std::vector<std::thread> m_threads;

public:
    explicit ThreadPool(size_t nrThreads);

    ~ThreadPool();

    void close();

    void enqueue(const std::function<void()> &func);

private:
    void run();
};
