cmake_minimum_required(VERSION 3.23)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab4 main.cpp Input.cpp Input.h rand.cpp executor.cpp output.cpp)

# 增加一个子目录准备使用gtest自带的cmakelists.txt去编译gtest
add_subdirectory(gtest_demo/lib)
# 指定gtest的头文件目录
include_directories(gtest_demo/lib/googletest/include gtest_demo/lib/googletest)
# 指定gmock的头文件目录
include_directories(gtest_demo/lib/googlemock/include gtest_demo/lib/googlemock)
# 指定自己源代码中的头文件目录
include_directories(gtest_demo/head)
# 指定自己的源代码所在的目录，并把所有的源代码文件名用GTEST_DEMO_SRC变量代替
aux_source_directory(gtest_demo/src GTEST_DEMO_SRC)
# 指定生成gtest01(可执行程序的名字)的工程(即gtest01.exe)所需要的源文件
add_executable(gtest01 gtest_demo/test/gtest01.cpp ${GTEST_DEMO_SRC} gtest_demo/test/gtest01.cpp)
# 指定将gtest gtest_main两个链接库，链接到gtest01工程中
target_link_libraries(gtest01 gtest gtest_main)
## 指定生成gtest01(可执行程序的名字)的工程(即gtest01.exe)所需要的源文件
#add_executable(gtest02 gtest_demo/test/gtest01.cpp ${GTEST_DEMO_SRC} gtest_demo/test/gtest02.cpp)
## 指定将gtest gtest_main两个链接库，链接到gtest01工程中
#target_link_libraries(gtest02 gtest gtest_main)
