cmake_minimum_required(VERSION 3.5.1)

#include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers_c.cmake)

project(barcodeScanner)

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
     
#generate project binary
add_executable(
    ${PROJECT_NAME}
        ${INC_DIR}/Defines.h
        ${INC_DIR}/dataInput.h
        ${INC_DIR}/dataProcessing.h
        ${INC_DIR}/checkBarcode.h
        
        ${SRC_DIR}/dataInput.c
        ${SRC_DIR}/dataProcessing.c
        ${SRC_DIR}/checkBarcode.c
        ${SRC_DIR}/main.c
        
)

target_include_directories(
    ${PROJECT_NAME} 
        PRIVATE 
            ${INC_DIR}
)  

#set_target_c_standard(${PROJECT_NAME} 11)
#enable_target_c_warnings(${PROJECT_NAME})