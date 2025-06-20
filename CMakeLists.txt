cmake_minimum_required(VERSION 3.20...4.0)

project(User_Login_Program
		VERSION 1.0
		DESCRIPTION "A simple program that allows a user to create an accound and/or access an existing account."
		LANGUAGES CXX
		)

set(CMAKE_CXX_STANDARD 23)

# Set include path
include_directories(include)

# Include the Crypto++ cloned library
#include_directories(external/cryptopp)

# Add cryptopp static lib manually
#file(GLOB CRYPTOPP_SOURCES external/cryptopp/*.cpp)

#set(CRYPTOPP_SOURCES
#	external/cryptopp/cryptlib.cpp
#	external/cryptopp/filters.cpp
#	external/cryptopp/modes.cpp
#	external/cryptopp/rijndael.cpp
#)

#add_library(cryptopp STATIC ${CRYPTOPP_SOURCES})
#target_include_directories(cryptopp PUBLIC external/cryptopp)


# Gather all sources
set(SOURCES
	src/main.cpp
	src/Logger.cpp
	src/UserAccount.cpp
	src/InputValidation.cpp
)

add_executable(User_Login_Program ${SOURCES})
#target_link_libraries(User_Login_Program PRIVATE cryptopp)