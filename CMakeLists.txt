# CMakeList.txt : CMake project for ShanissEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("ShanissEngine")


# Add source to this project's executable.
# TODO: setup glob to auto grab every needed file
#include_directories(${PROJECT_SOURCE_DIR})
#file(GLOB ShanissEngine_SRC
#  ${PROJECT_SOURCE_DIR}/*.h
#  ${PROJECT_SOURCE_DIR}/*.cpp
#)

add_library (ShanissEngine SHARED 
"src/ShanissEngine.cpp" 
"src/ShanissEngine.h"  
"src/ecs/entity.cpp" 
"src/ecs/entity.h" 
"src/ecs/component.h" 
"src/ecs/component_collection.h" 
"src/ecs/component_manager.h" 
"src/ecs/component_manager.cpp" 
"src/ecs/component_collection.cpp"
"src/ecs/system.h"
"src/gamestate.h"
"test/bla.cpp"
)

target_include_directories(ShanissEngine PUBLIC ${CMAKE_SOURCE_DIR})



# TODO: Add tests and install targets if needed.
set_property (TARGET ${PROJECT_NAME}
  PROPERTY
    # Enable C++17 standard compliance
    CXX_STANDARD 17
)