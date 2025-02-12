cmake_minimum_required(VERSION 3.20)
project(DissensionFramework CXX)

message(STATUS "${PROJECT_NAME} V 0.0.0 by PouPeuu")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR src)
set(HEADER_DIR headers)
set(RES_DIR res)

file(GLOB SOURCES "${SRC_DIR}/*.cpp")
file(GLOB HEADERS "${HEADER_DIR}/${PROJECT_NAME}/*.hpp" "${HEADER_DIR}/*.h")

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LUAJIT REQUIRED luajit)

target_link_libraries(${PROJECT_NAME} PUBLIC
    OpenGL::GL
    glfw
    GLEW::GLEW
    ${LUAJIT_LIBRARIES}
)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${HEADER_DIR}>
    $<INSTALL_INTERFACE:include>
    ${LUAJIT_INCLUDE_DIRS}
)

install(TARGETS ${PROJECT_NAME}
    EXPORT DissensionFrameworkTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY ${HEADER_DIR}/DissensionFramework DESTINATION include)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/DissensionFrameworkConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/DissensionFrameworkConfig.cmake
    INSTALL_DESTINATION lib/cmake/DissensionFramework
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/DissensionFrameworkConfigVersion.cmake
    VERSION 1.0.0
    COMPATIBILITY SameMajorVersion
)

install(EXPORT DissensionFrameworkTargets
    FILE DissensionFrameworkTargets.cmake
    DESTINATION lib/cmake/DissensionFramework
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/DissensionFrameworkConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/DissensionFrameworkConfigVersion.cmake
    DESTINATION lib/cmake/DissensionFramework
)