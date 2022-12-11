cmake_minimum_required(VERSION 2.8.12)
project(NeuronNetwork)
add_executable(${PROJECT_NAME} src/Neuron.cpp src/main.cpp src/NeuronNetwork.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/$<0:>)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX .exe)