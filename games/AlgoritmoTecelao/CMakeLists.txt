cmake_minimum_required(VERSION 3.7)
project(main)
add_executable(main src/main.cpp)

# cmake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../../common/cmakes")

# pig
include_directories("../../common/pig-0.5.1")

# sdl2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(main ${SDL2_LIBRARY})

# sdl2_image
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(main ${SDL2_IMAGE_LIBRARIES})

# sdl2_ttf
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(main ${SDL2_TTF_LIBRARIES})

# gsl
find_package(GSL REQUIRED)
target_link_libraries(main GSL::gsl GSL::gslcblas)
