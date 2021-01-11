cmake_minimum_required(VERSION 3.17)
project(OfflineMessenger)

set(CMAKE_CXX_STANDARD 14)

add_executable(OfflineMessenger svMessenger.cpp server.cpp server.h client.cpp client.h clMessenger.cpp)