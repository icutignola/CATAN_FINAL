cmake_minimum_required(VERSION 3.14)
project(Tp-final-eda)

set(CMAKE_CXX_STANDARD 14)

add_executable(CATAN_FINAL AbstractBuilding.cpp AbstractToken.cpp Catan.cpp City.cpp client.cpp Coordinates.cpp Dock.cpp errorC.cpp eventHandling.cpp FSMImplementation.cpp genericFSM.cpp io.cpp Island.cpp main.cpp Map.cpp Player.cpp Port.cpp Road.cpp Robber.cpp Rules.cpp server.cpp simpleEventGenerator.cpp Town.cpp)
