# Requiere al menos esta versión de CMake
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(PokedexProject)

# Usar C++20
set(CMAKE_CXX_STANDARD 20)

# Incluir encabezados (headers)
include_directories(headers)

# Archivos fuente
file(GLOB SRC_FILES src/*.cpp)
set(MAIN_FILE example/main.cpp)

# Crear el ejecutable
add_executable(PokedexExe ${MAIN_FILE} ${SRC_FILES})

# Directorio de salida del ejecutable
set_target_properties(PokedexExe PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)



COMANDOS 
mkdir build
cd build
cmake ..
make


