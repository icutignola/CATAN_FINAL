cmake_minimum_required(VERSION 3.14)
project(Tp-final-eda)

set(CMAKE_CXX_STANDARD 14)

add_executable(Catan AbstractBuilding.cpp AbstractToken.cpp Catan.cpp City.cpp client.cpp Coordinates.cpp Dock.cpp errorC.cpp eventHandling.cpp FSMImplementation.cpp genericFSM.cpp io.cpp Island.cpp Map.cpp Player.cpp Port.cpp server.cpp simpleEventGenerator.cpp Road.cpp Robber.cpp Rules.cpp Town.cpp main.cpp)
