cmake_minimum_required(VERSION 4.0)
project(azr_eng_2_0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ---------------------------------
# Vulkan
# ---------------------------------
find_package(Vulkan REQUIRED)


file(GLOB_RECURSE ENGINE_SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

add_executable(azr_eng_2_0 ${ENGINE_SOURCES})

target_include_directories(azr_eng_2_0 PUBLIC ${Vulkan_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(azr_eng_2_0 PUBLIC ${Vulkan_LIBRARIES})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if (MSVC)
    target_compile_options(azr_eng_2_0 PRIVATE /W4 /permissive-)
else()
    target_compile_options(azr_eng_2_0 PRIVATE -Wall -Wextra -Wpedantic)
endif()