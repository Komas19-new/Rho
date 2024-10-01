cmake_minimum_required(VERSION 3.10)
project(RhoWebEngine)

set(CMAKE_CXX_STANDARD 11)

# Find required packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(CURL REQUIRED libcurl)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(LIBXML2 REQUIRED libxml-2.0)

# Include directories for libraries
include_directories(${CURL_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS} ${LIBXML2_INCLUDE_DIRS})

# Add executable
add_executable(RhoWebEngine src/main.cpp src/Fetcher.cpp src/GUI.cpp src/Renderer.cpp)

# Link libraries
target_link_libraries(RhoWebEngine ${CURL_LIBRARIES} ${SDL2_LIBRARIES} ${LIBXML2_LIBRARIES})
