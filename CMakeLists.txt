cmake_minimum_required(VERSION 3.3)

add_custom_target(
        dragon
        COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)