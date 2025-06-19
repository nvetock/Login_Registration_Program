cmake_minimum_required(VERSION 3.20...4.0)

project(User_Login_Program
		VERSION 1.0
		DESCRIPTION "A simple program that allows a user to create an accound and/or access an existing account."
		LANGUAGES CXX
		)

set(CMAKE_CXX_STANDARD 23)

# Set include path
include_directories(include)

# Gather all sources
set(SOURCES
	src/main.cpp
	src/Logger.cpp
	src/UserAccount.cpp
	src/InputValidation.cpp
)

add_executable(User_Login_Program ${SOURCES})