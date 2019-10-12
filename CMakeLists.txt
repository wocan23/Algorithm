cmake_minimum_required(VERSION 3.10)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

set(
        SOURCE_FIlES
        charseq/lcs.h
        common.h
        sort/quicksort.h
        sort/heapsort.h
        test/vector_test.h
        ml/meanshift.h
        ml/dbscan.h
        ml/Point.cpp
        ml/Point.h main.cpp
        charseq/Permutation.h)

set(CMAKE_C_COMPILER )
include_directories( /usr/local/opt/sqlite/include /usr/local/opt/libspatialite/include)
link_directories(/usr/local/opt/sqlite/lib /usr/local/opt/libspatialite/lib)
set(CMAKE_C_EXTENSIONS /usr/local/opt/libspatialite/lib/libspatialite.dylib)
set(CMAKE_DEF_OUTPUT_EXTENSION 1)

add_executable(Algorithm ${SOURCE_FIlES})
target_link_libraries(Algorithm sqlite3 spatialite )

