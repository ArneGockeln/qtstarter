cmake_minimum_required(VERSION 3.7)
project(qtstarter)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Qt
# Set this to your Qt installation
set(CMAKE_PREFIX_PATH ~/sourcecode/sdk/QtLatest/5.9.2/clang_64)
set(RESOURCE_FOLDER res)
set(RESOURCE_FILES ${RESOURCE_FOLDER}/resources.qrc)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Quick REQUIRED)

set(PROJECT_SOURCE_DIR src/)
include_directories(${PROJECT_SOURCE_DIR})

set(SOURCE_FILES src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${RESOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick)
