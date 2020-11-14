CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

project(unit_tests)
aux_source_directory(./ DIR_SRCS)

find_package(TBB)
find_package(glog)
find_package(GTest REQUIRED CONFIG)

link_directories("../build/src.common")

set(CMAKE_CXX_FLAGS "-std=c++14 -O3 -fPIC -g ${CMAKE_CXX_FLAGS}")
set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS}")

add_executable(app ${DIR_SRCS})
target_link_libraries(app GTest::gtest GTest::gmock GTest::gmock_main glog::glog TBB::tbb Flex_Common)
