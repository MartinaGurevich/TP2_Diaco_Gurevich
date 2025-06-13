# Requiere al menos esta versión de CMake
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(programa)

# Usar C++20
set(CMAKE_CXX_STANDARD 20)

# Incluir encabezados (headers)
include_directories(headers)

# Archivos fuente
file(GLOB SRC_FILES src/*.cpp)
set(MAIN_FILE example/main.cpp)

# Crear el ejecutable
add_executable(programa ${MAIN_FILE} ${SRC_FILES})

# Directorio de salida del ejecutable
set_target_properties(programa PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Agregar warnings comunes para compilar con g++
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(programa PRIVATE 
        -Wall        # Habilita todos los warnings importantes
        -Wextra      # Más warnings adicionales
        -Wpedantic   # Warnings por cosas que no son estándar
    )
endif()






