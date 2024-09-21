cmake_minimum_required(VERSION 3.5.0)
project(CallCenter VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(CONAN_SOURCE_DIR "${CMAKE_BINARY_DIR}/conan")
FetchContent_Declare(conan
    GIT_REPOSITORY https://github.com/conan-io/cmake-conan
    GIT_TAG 0.18.1
    SOURCE_DIR ${CONAN_SOURCE_DIR}
)
FetchContent_Populate(conan)

include(${CONAN_SOURCE_DIR}/conan.cmake)
conan_cmake_autodetect(settings)
conan_cmake_install(
    PATH_OR_REFERENCE ${CMAKE_SOURCE_DIR}
    INSTALL_FOLDER ${CMAKE_BINARY_DIR}
    BUILD missing
    REMOTE conancenter
    SETTINGS ${settings}
    ENV "CONAN_CMAKE_GENERATOR=${CMAKE_GENERATOR}"
    CONF="tools.cmake.cmaketoolchain:generator=${CMAKE_GENERATOR}"
)
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

find_package(Boost 1.86.0 EXACT REQUIRED COMPONENTS thread)
find_package(RapidJSON REQUIRED)
find_package(spdlog 1.14.1 EXACT REQUIRED)

add_subdirectory(src)