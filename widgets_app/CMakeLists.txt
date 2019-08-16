cmake_minimum_required(VERSION 3.8)
project(widgetsapp)

# Project 
set(PROJECT_COMPANY "Awesome Company")
set(PROJECT_COPYRIGHT "Copyright (c) 2019 Awesome Company. All rights reserved.")
set(PROJECT_DOMAIN "com.awesomecompany.appname")
set(PROJECT_VERSION 1.0)
set(PROJECT_BUNDLE_NAME AppName)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Qt
# Set this to your Qt installation
set(ICON_NAME AppIcon)
set(CMAKE_AUTOMOC ON) # For meta object compiler 
set(CMAKE_AUTOUIC ON) # Resource files
set(CMAKE_AUTORCC ON) # UI Files
set(RESOURCE_FILES 
	res/resources.qrc
	res/${ICON_NAME}.icns
	res/${ICON_NAME}.png
)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

# macOS Bundle building
set(OS_BUNDLE "")
if(CMAKE_BUILD_TYPE STREQUAL "Release")
set(OS_BUNDLE "MACOSX_BUNDLE")
set(MACOSX_BUNDLE_BUNDLE_NAME ${PROJECT_BUNDLE_NAME})
set(MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION})
set(MACOSX_BUNDLE_LONG_VERSION_STRING ${PROJECT_VERSION})
set(MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION})
set(MACOSX_BUNDLE_COPYRIGHT ${PROJECT_COPYRIGHT})
set(MACOSX_BUNDLE_GUI_IDENTIFIER ${PROJECT_DOMAIN})
set(MACOSX_BUNDLE_ICON_FILE ${ICON_NAME})
else(CMAKE_BUILD_TYPE STREQUAL "Release")
set(CMAKE_BUILD_TYPE Debug)
endif()

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)
include_directories(${PROJECT_SOURCE_DIR})

# source files
file(GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

# executable
add_executable(${PROJECT_NAME} ${OS_BUNDLE} ${SOURCE_FILES} ${RESOURCE_FILES})
if(CMAKE_BUILD_TYPE STREQUAL "Release")
set_target_properties(${PROJECT_NAME} PROPERTIES 
	MACOSX_BUNDLE TRUE 
	RESOURCE "${RESOURCE_FILES}"
	OUTPUT_NAME "${PROJECT_BUNDLE_NAME}"
)
endif()

# expose values to c++ files
target_compile_definitions(${PROJECT_NAME} PRIVATE 
	CMAKE_DEF_PROJECT_VERSION="${PROJECT_VERSION}"
	CMAKE_DEF_APP_NAME="${PROJECT_BUNDLE_NAME}"
	CMAKE_DEF_ORG_COMPANY="${PROJECT_COMPANY}"
	CMAKE_DEF_ORG_DOMAIN="${PROJECT_DOMAIN}"
)

# Link Libs
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets)
