cmake_minimum_required(VERSION 3.23)
project(nccTraining)

set(CMAKE_CXX_STANDARD 14)

#add_executable(nccTraining IntroDataStructures.cpp)

add_executable(nccTraining  ./bank_project/bank.c ./bank_project/zoom_online_bank.h)

#add_executable(nccTraining  time_library_lesson.c)
