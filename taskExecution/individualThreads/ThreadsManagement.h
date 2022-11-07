#pragma once

void joinThreads(std::vector<std::thread *> &threads);

void deallocateThreads(std::vector<std::thread *> &threads);