cmake_minimum_required(VERSION 3.13)
project(LinearAlgebra VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

# サブディレクトリを登録
add_subdirectory(src)
add_subdirectory(tests)
