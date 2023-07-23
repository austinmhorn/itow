cmake_minimum_required(VERSION 3.21)

set( ITOW_MAJOR_VERSION 0 )
set( ITOW_MINOR_VERSION 1 )
set( ITOW_REVISION_VERSION 0 )
set( ITOW_VERSION ${ITOW_MAJOR_VERSION}.${ITOW_MINOR_VERSION}.${ITOW_REVISION_VERSION} )

project( itow LANGUAGES CXX VERSION ${ITOW_VERSION} )

set(TARGET ${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Compile target
set(SOURCE_FILES
    "src/main.cpp"
    "src/main.hpp"
    "src/rng.hpp"
    "src/models.hpp"
    "src/dictionary.hpp"
    "src/itow.hpp"
    "src/itow.cpp")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

install(TARGETS ${PROJECT_NAME}
        CONFIGURATIONS Debug
        RUNTIME DESTINATION)
