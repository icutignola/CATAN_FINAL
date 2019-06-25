cmake_minimum_required(VERSION 3.14)
project(CATAN)
set(CMAKE_CXX_STANDARD 14)
add_executable(CATAN AbstractBuilding.cpp AbstractToken.cpp Catan.cpp City.cpp client.cpp Coordinates.cpp Dock.cpp errorC.cpp eventHandling.cpp FSMImplementation.cpp genericFSM.cpp io.cpp Island.cpp main.cpp Map.cpp Player.cpp Port.cpp Road.cpp Robber.cpp Rules.cpp server.cpp simpleEventGenerator.cpp Town.cpp )

find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
endif()

if(Boost_FOUND)
    target_link_libraries(CATAN ${Boost_LIBRARIES})
endif()

INCLUDE_DIRECTORIES(  /usr/local/include )
LINK_DIRECTORIES(  /usr/local/lib )

file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.5.0/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

TARGET_LINK_LIBRARIES(CATAN  ${LIBRARIES})

set(SOURCE_FILES main.cpp)