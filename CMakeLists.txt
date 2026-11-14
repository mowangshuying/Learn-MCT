cmake_minimum_required(VERSION 3.10)

project(LearnModernCppTutorial LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_subdirectory(TowardsModernCpp)
add_subdirectory(LanguageUsabilityEnhancements)
add_subdirectory(LanguageRuntimeEnhancements)
add_subdirectory(Container)
add_subdirectory(SmartPointersAndMemoryManagment)
add_subdirectory(Regex)
