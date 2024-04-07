cmake_minimum_required(VERSION 3.25)
project(seash LANGUAGES CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Werror -Wextra -Wold-style-cast -pedantic)

find_package(Boost REQUIRED COMPONENTS program_options)

include_directories(src)

add_executable(seash)
target_link_libraries(seash)

add_subdirectory(src)