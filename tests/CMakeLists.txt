add_executable(LAtest.out Main.cpp)
# LAtest.outをコンパイルする際にLinearAlgebraをリンクする
target_link_libraries(LAtest.out LinearAlgebra)
