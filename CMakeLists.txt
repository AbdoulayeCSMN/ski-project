cmake_minimum_required(VERSION 4.0)
project(skic LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(skic src/builtin/fonctions.cpp
        src/ski_core/backend/TYPES.cpp
        include/ski_core/frontend/TYPES.hpp
        src/packages/activations.cpp
        include/packages/activations.hpp)

add_executable(skic_exec src/main.cpp)

target_include_directories(skic
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(skic_exec
        PRIVATE skic
)