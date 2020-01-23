cmake_minimum_required(VERSION 3.10)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

set(
        SOURCE_FIlES
        charseq/lcs.h
        common/common.h
        sort/quick_sort.h
        sort/heap_sort.h
        ml/dbscan.h
        main.cpp
        charseq/permutation.h num/sub_sum.h num/repeat_find.h num/max_window.h)


add_executable(Algorithm ${SOURCE_FIlES})
target_link_libraries(Algorithm  )

