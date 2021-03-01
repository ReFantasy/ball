cmake_minimum_required(VERSION 3.0)
project(gl_demo)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})


include_directories("F:/Simulation/d/include")
link_directories("F:/Simulation/d/lib")
link_libraries(glew32 glfw3 soil2 ${OPENGL_LIBRARY})

add_executable(gl_demo main.cpp Utils.h Utils.cpp)
