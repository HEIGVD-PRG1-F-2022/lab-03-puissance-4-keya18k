cmake_minimum_required(VERSION 3.23)
project(Mandelbrot)

set(CMAKE_CXX_STANDARD 20)

add_executable(Mandelbrot main.cpp gameEndedVerification.cpp gameEndedVerification.h gameInputOutput.cpp gameInputOutput.h gameLogic.cpp gameLogic.h cellType.cpp cellType.h)
