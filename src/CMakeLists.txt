cmake_minimum_required(VERSION 3.5.0)

set(SOURCE_DIR ".")
file(GLOB_RECURSE SOURCE_LIST "${SOURCE_DIR}/*")

add_executable(CallCenter ${SOURCE_LIST})

