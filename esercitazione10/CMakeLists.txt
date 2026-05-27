cmake_minimum_required(VERSION 3.20)

project(esercitazione10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS
"${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Werror=vla")

find_package(Eigen3 REQUIRED)

enable_testing()

add_executable(gradiente_coniugato
    gradiente_coniugato_main.cpp
)

target_link_libraries(gradiente_coniugato
    Eigen3::Eigen
)

add_executable(test_gradiente_coniugato
    test_gradiente_coniugato.cpp
)

target_link_libraries(test_gradiente_coniugato
    Eigen3::Eigen
)

add_test(
    NAME test_gradiente_coniugato
    COMMAND test_gradiente_coniugato
)