cmake_minimum_required(VERSION 3.31)
project(cpp_primer CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_primer
        #   ch_01/Sales_item.h
        #   ch_01/ex_01.cpp
        #   ch_01/ex_02.cpp
        #   ch_01/ex_03.cpp
        #   ch_01/ex_04.cpp
        #   ch_01/ex_05.cpp
        #   ch_01/ex_07.cpp
        #   ch_01/ex_08.cpp
        #   ch_01/ex_09.cpp
        #   ch_01/ex_10.cpp
        #   ch_01/ex_11.cpp
        #   ch_01/ex_13.cpp
        #   ch_01/ex_15.cpp
        #   ch_01/ex_16.cpp
        #   ch_01/ex_18.cpp
        #   ch_01/ex_19.cpp
        #   ch_01/ex_20.cpp
        #   ch_01/ex_21.cpp
        #   ch_01/ex_22.cpp
        #   ch_01/ex_23.cpp
        #   ch_01/ex_24.cpp
        #   ch_01/ex_25.cpp
        #   ch_02/ex_04.cpp
        #   ch_02/ex_08.cpp
        #   ch_02/ex_10.cpp
        #   ch_02/ex_13.cpp
        #   ch_02/ex_14.cpp
        #   ch_02/ex_18.cpp
        #   ch_02/ex_34.cpp
        #   ch_02/ex_35.cpp
        #   ch_02/ex_39.cpp
        #   ch_02/ex_40.cpp
        #   ch_02/ex_41_1.cpp
        #   ch_02/ex_41_2.cpp
        #   ch_02/ex_41_3.cpp
        #   ch_02/ex_42_1.cpp
        #   ch_02/ex_42_2.cpp
        ch_02/ex_42_3.cpp)

install(TARGETS cpp_primer RUNTIME DESTINATION ${CMAKE_SOURCE_DIR})
