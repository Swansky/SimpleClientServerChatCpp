cmake_minimum_required(VERSION 3.20)
project(serverChat)

set(CMAKE_CXX_STANDARD 23)

add_executable(serverChat main.cpp managers/CommandManager.cpp managers/CommandManager.h models/SimpleCommand.cpp models/SimpleCommand.h managers/ServerManager.cpp managers/ServerManager.h)
