cmake_minimum_required(VERSION 3.15)
project(Double-Pendulum-Simulation)

set(CMAKE_CXX_STANDARD 14)

set(SFML_ROOT /home/wojkly/Documents/STUDIA/cpp/Double-Pendulum-Simulation/SFML)
#set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "SFML/lib/cmake/SFML")

set(CMAKE_MODULE_PATH "$(CMAKE_CURRENT_LIST_DIR)/cmake_modules")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
find_package(SFML COMPONENTS audio graphics window system)
add_executable(Double-Pendulum-Simulation main.cpp Application.cpp Application.h DoublePendulum.cpp DoublePendulum.h PendulumEquation.cpp PendulumEquation.h Simulation.cpp Simulation.h ArgumentParser.cpp ArgumentParser.h)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Double-Pendulum-Simulation sfml-graphics sfml-audio sfml-window sfml-system)
endif ()