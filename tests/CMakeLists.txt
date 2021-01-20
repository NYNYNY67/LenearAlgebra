# GoogleTestのライブラリをインクルード
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(LAtest.out Main.cpp)
# LAtest.outをコンパイルする際にLinearAlgebraをリンクする
target_link_libraries(LAtest.out LinearAlgebra GTest::GTest GTest::Main)

include_directories(
  ${PROJECT_SOURCE_DIR}/include/
  ${GTEST_INCLUDE_DIRS}
)
