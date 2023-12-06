cmake_minimum_required(VERSION 3.0)
project(huffmancodec C)

set(CMAKE_C_STANDARD 23)

#LINK_LIBRARIES(m,huffmancodec) # link math lib

add_executable(huffmancodec main.c
        src/hufftree.c src/hufftree.h
        src/pq.c src/pq.h
        src/sonds.c src/sonds.h
        src/ll.c src/ll.h
        src/codechuff.c
        src/codechuff.h
        src/bench.c
        src/bench.h)

add_executable(sondstest
        src/sonds.c src/sonds.h
        src/sonds_test.c)

add_executable(lltest
        src/ll.c
        src/ll.h
        src/sonds.c
        src/sonds.h
        src/ll_test.c)
