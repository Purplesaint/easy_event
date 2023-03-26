cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(easy_event)

set(CMAKE_CXX_STANDARD 11)


add_executable(${PROJECT_NAME}_tester
    tester.cc
    easy_event.h
    )