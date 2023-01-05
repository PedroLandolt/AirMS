cmake_minimum_required(VERSION 3.24)
project(AED_Projeto_2)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

add_executable(AED_Projeto_2
        cpps/Graph.cpp
        headers/Graph.h
        main.cpp headers/Companhia.h cpps/Companhia.cpp cpps/Ler.cpp headers/Aeroporto.h cpps/Aeroporto.cpp headers/Distancias.h cpps/Distancias.cpp)
