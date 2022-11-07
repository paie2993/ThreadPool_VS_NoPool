cmake_minimum_required(VERSION 3.23)
project(SimpleParallelTasks)

set(CMAKE_CXX_STANDARD 23)

add_executable(SimpleParallelTasks main.cpp
        threadPool/ThreadPool.cpp
        matrixManagement/MatrixOperations.cpp
        matrixManagement/MatrixIOManagement.cpp
        matrixManagement/MatrixMemoryManagement.cpp
        taskExecution/individualThreads/Subtask.cpp
        taskExecution/individualThreads/ThreadsManagement.cpp
        taskExecution/individualThreads/TaskManagement.cpp
        taskExecution/threadPooled/TaskManagement.cpp
        configuration/StaticData.h
        taskExecution/threadPooled/Subtask.cpp
        matrixManagement/MatrixOperations.h
        matrixManagement/MatrixMemoryManagement.h
        matrixManagement/MatrixIOManagement.h taskExecution/individualThreads/ThreadsManagement.h taskExecution/individualThreads/TaskManagement.h taskExecution/threadPooled/TaskManagement.h threadPool/ThreadPool.h taskExecution/individualThreads/Subtask.h taskExecution/threadPooled/Subtask.h)
