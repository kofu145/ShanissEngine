# CMakeList.txt : CMake project for ShanissEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("ShanissEngine")

# Add source to this project's executable.
# TODO: setup glob to auto grab every needed file
add_library (ShanissEngine SHARED "ShanissEngine.cpp" "ShanissEngine.h"  "entity.cpp" "entity.h" "component.h" "component_array.h" "component_manager.h" "component_manager.cpp" "component_array.cpp")

# TODO: Add tests and install targets if needed.
set_property (TARGET ${PROJECT_NAME}
  PROPERTY
    # Enable C++17 standard compliance
    CXX_STANDARD 17
)