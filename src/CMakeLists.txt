add_library(LinearAlgebra
  STATIC
    cond.cpp
    det.cpp
    Gauss.cpp
    LU.cpp
    VecUtil.cpp
    Pivot.cpp
    )

target_include_directories(LinearAlgebra
  PUBLIC ${PROJECT_SOURCE_DIR}/include
  )
