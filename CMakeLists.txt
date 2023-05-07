cmake_minimum_required(VERSION 3.0)
project(Blockchain_Aed)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(Blockchain_Aed main.cpp frames.h frames.cpp)
target_link_libraries(Blockchain_Aed ${wxWidgets_LIBRARIES})
