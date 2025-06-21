cmake_minimum_required(VERSION 3.20...4.0)

project(LoginRegistration
        VERSION 1.0
        DESCRIPTION "A simple program that allows a user to create an accound and/or access an existing account."
        LANGUAGES CXX
        )

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

set(ALLSOURCES
    src/main.cpp
    src/Logger.cpp
    src/UserAccount.cpp
    src/InputValidation.cpp
)

add_executable(LoginRegistration ${ALLSOURCES})