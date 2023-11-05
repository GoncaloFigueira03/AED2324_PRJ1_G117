cmake_minimum_required(VERSION 3.26)
project(Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(source)

add_executable(Code
        source/Class.cpp
        source/Class.h
        source/main.cpp
        source/Reader.cpp
        source/Reader.h
        source/structs.h
        source/Schedule.h
        source/Schedule.cpp
        source/Menu.cpp
        source/Student.cpp
        source/Uc.cpp
        source/SchedulePrinter.cpp
        source/Writer.cpp
        source/Sort.cpp
)
