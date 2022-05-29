cmake_minimum_required(VERSION 3.22)
project(COMDES___CURRENT_VERSION)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(COMDES___CURRENT_VERSION
        Charmap.h
        Driver.cpp
        KeywordList.h
        Parser.h
        Scanner.h)
