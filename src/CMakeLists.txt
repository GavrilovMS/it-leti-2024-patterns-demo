cmake_minimum_required(VERSION 3.5.0)

set(PROJECT_NAME CallCenter)

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
file(GLOB_RECURSE SOURCE_LIST "${SOURCE_DIR}/*")

add_executable(${PROJECT_NAME} ${SOURCE_LIST})

target_include_directories(${PROJECT_NAME}
	PRIVATE
		${SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		Boost::thread
		spdlog::spdlog
		RapidJSON::RapidJSON
)