cmake_minimum_required(VERSION 3.14)
project(CATAN)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES AbstractBuilding.cpp AbstractToken.cpp Catan.cpp City.cpp client.cpp Coordinates.cpp Dock.cpp errorC.cpp eventHandling.cpp FSMImplementation.cpp genericFSM.cpp io.cpp Island.cpp Map.cpp Player.cpp server.cpp simpleEventGenerator.cpp Road.cpp Robber.cpp Rules.cpp Town.cpp main.cpp)
set(IMAGES Clay.png Desert.png eight.png eleven.png Error.jpg five.png four.png houseRed.png InputBuilding.bmp InputCoordinates.bmp InputCoordinates.jpg InputGeneral.bmp InputGeneral.jpg InputTrade.bmp InputYesNo.bmp InputYesNo.jpg nine.png one.png OutputBankTrade.jpg OutputBnakOther.jpg OutputBuilding.jpg OutputCoordineates.jpg OutputGeneral.jpg OutputIntercambioSi.jpg OutputIp.jpg OutputName.jpg OutputSuprRes.jpg OutputTrade1.jpg OutputTrade2.jpg OutputTry.jpg OutputWait.jpg OutputYesNo.jpg Robber.png Rock.png Sea.png seven.png Sheep.png six.png ten.png three.png tradeInput.PNG TurnoOff.png TurnoOn.png twelve.png two.png Wheat.png Wood.png)

add_executable(CATAN ${SOURCE_FILES})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${IMAGES})
INCLUDE_DIRECTORIES(  /usr/local/include )
LINK_DIRECTORIES(/usr/local/lib)

file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.5.0/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")
TARGET_LINK_LIBRARIES(CATAN  ${LIBRARIES})

find_package(Boost 1.69.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")

    include_directories(${Boost_INCLUDE_DIRS})

endif()

if(Boost_FOUND)

    target_link_libraries(CATAN ${Boost_LIBRARIES} ${LIBRARIES})

endif()