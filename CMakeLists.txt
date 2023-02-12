cmake_minimum_required(VERSION 2.8.12)
project(NeuronNetwork)

add_executable(${PROJECT_NAME} src/main.cpp src/MultiPerceptron.cpp src/Neuron.cpp src/NeuronNetwork.cpp src/PerceptronLayer.cpp src/Perceptron.cpp src/MNIST.cpp)

add_library(neur SHARED src/Perceptron.h src/Perceptron.cpp src/MNIST.h src/MNIST.cpp)

set_target_properties(neur PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/$<0:>)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/$<0:>)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX .exe)