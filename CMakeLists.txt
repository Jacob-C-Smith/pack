# Need CMake 3.28
cmake_minimum_required (VERSION 3.28.0)

# This is the name of the repository
project ("pack")

# Set the correct paths
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/extern/)

# Comment out for Debug mode
set(IS_DEBUG_BUILD CMAKE_BUILD_TYPE STREQUAL "Debug")

# Set debug mode
if (${IS_DEBUG_BUILD})
    add_compile_definitions(NDEBUG)
endif()

# Add the pack project
if ( NOT "${HAS_PACK}")

    # Log
    message("[pack] Adding pack project")

    # Set the include directory
    set (PACK_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)

    # Let any parent project know that it has the pack project
    if(NOT PROJECT_IS_TOP_LEVEL)
        set(HAS_PACK true PARENT_SCOPE)
        set(PACK_INCLUDE_DIR ${PACK_INCLUDE_DIR} PARENT_SCOPE)
    endif()
endif()

# Add source to this project's executable.
add_executable(pack_example "main.c")
add_dependencies(pack_example pack)
target_include_directories(pack_example PUBLIC ${PACK_INCLUDE_DIR})
target_link_libraries(pack_example pack)

# Add source to the library
add_library(pack SHARED "pack.c")
target_include_directories(pack PUBLIC ${PACK_INCLUDE_DIR})
