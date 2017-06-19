cmake_minimum_required(VERSION 3.6)
project(AdventOfCode)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES 2016/Day8/main.c)

# searching for include directory
include_directories(/usr/local/Cellar/netpbm/10.76_1/include)

# searching for library file
link_directories(/usr/local/Cellar/netpbm/10.76_1/lib)

add_executable(AdventOfCode ${SOURCE_FILES})

target_link_libraries(AdventOfCode libnetpbm.a)

