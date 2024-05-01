set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(core/)

file(GLOB SOURCES "core/*.c")

add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)


add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}"
                   "${CMAKE_CURRENT_BINARY_DIR}/..")
