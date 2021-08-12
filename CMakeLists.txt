# CMakeList.txt : CMake project for ShanissEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("ShanissEngine")

include_directories(src test)

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
"src/entity.cpp" 
"src/entity.h" 
"src/component.h" 
"src/component_collection.h" 
"src/component_manager.h" 
"src/component_manager.cpp" 
"src/component_collection.cpp"
)

# TODO: Add tests and install targets if needed.
set_property (TARGET ${PROJECT_NAME}
  PROPERTY
    # Enable C++17 standard compliance
    CXX_STANDARD 17
)