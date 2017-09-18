project("HomeWork2")

cmake_minimum_required(VERSION 3.5)
cmake_minimum_required(VERSION 2.8)

project(HomeWork2 CXX)

set(HOMEWORK2_MAJOR_VERSION 1)
set(HOMEWORK2_MINOR_VERSION 0)
set(HOMEWORK2_PATCH_VERSION 0)
set(HOMEWORK2_VERSION
	${HOMEWORK2_MAJOR_VERSION}.${HOMEWORK2_MINOR_VERSION}.${HOMEWORK2_PATCH_VERSION})

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

include_directories(inc)

file(GLOB SOURCES "src/*.cpp")

add_executable(HomeWork2 ${SOURCES})

#set_target_properties(HomeWork2 
#	PROPERTIES
 #   CXX_STANDARD 11
 #   CXX_STANDARD_REQUIRED ON
 #   CXX_EXTENSIONS OFF)
