cmake_minimum_required(VERSION 3.10)

project("Communication between VCU and ABS")

set(CMAKE_CXX_STANDARD 14)   # Use modern C++ version
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(vsomeip3 REQUIRED)
find_package(Boost 1.55 REQUIRED COMPONENTS system thread log)  # Correct lowercase!

include_directories(
    ${Boost_INCLUDE_DIRS}
)

add_executable(abs_app ../src/abs_app.cpp)
target_link_libraries(abs_app
    vsomeip3 vsomeip3-cfg pthread dl
    ${Boost_LIBRARIES}  # Correct one!
)

add_executable(vcu_app ../src/vcu_app.cpp)
target_link_libraries(vcu_app
    vsomeip3 vsomeip3-cfg pthread dl
    ${Boost_LIBRARIES}
)
