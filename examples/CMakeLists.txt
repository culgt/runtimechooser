project(runtimechooser_examples)

cmake_minimum_required(VERSION 2.8.3)

option( ENABLE_C++11 "enables C++11 features" ON )

include_directories( ../include )

find_package( CUDA )
find_package( Boost REQUIRED )

if( ENABLE_C++11 )
    add_definitions(-std=c++11)
    set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -std=c++11" )
endif()

add_executable( example example.cc )
add_executable( example_one_sequence example_one_sequence.cc )
add_executable( example_two_sequences example_two_sequences.cc )

if( NOT CUDA-NOTFOUND )
    cuda_add_executable( example_cuda example_cuda.cu )
else()
    message( STATUS "Cuda not available: example_cuda not build" )
endif()

add_executable( example_to_string example_to_string.cc )
