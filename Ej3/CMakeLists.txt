cmake_minimum_required(VERSION 3.10)
project(Ej3)

# Requiere C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Agrega el ejecutable usando el archivo fuente
add_executable(programa example/main.cpp)
