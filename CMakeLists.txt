cmake_minimum_required (VERSION 3.10)
project(xbtbinfileutils VERSION 1)
set(DEFAULT_BUILD_TYPE "Release")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Os -fno-rtti ")

# Find source files
file(GLOB SOURCES src/*.cpp)

# Include header files
include_directories(include)

# Create shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION

#                        ARCHIVE DESTINATION lib/${PROJECT_NAME}
#                        LIBRARY DESTINATION lib/${PROJECT_NAME}
#                        RUNTIME DESTINATION bin/${PROJECT_NAME}
                        
                        ARCHIVE DESTINATION lib
                        LIBRARY DESTINATION lib
                        RUNTIME DESTINATION bin
)


# Install library headers
file(GLOB HEADERS include/*.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})

# uninstall target
if(NOT TARGET uninstall)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)

    add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION})
