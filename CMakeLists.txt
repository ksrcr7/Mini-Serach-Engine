cmake_minimum_required(VERSION 3.27)
project(Mini_Search_Engine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(Mini_Search_Engine src/main.cpp
        include/Document.h
        src/Document.cpp
        include/DocumentReader.h
        src/DocumentReader.cpp
        include/Tokenizer.h
        src/Tokenizer.cpp
        include/Indexer.h
        src/Indexer.cpp
        include/SearchEngine.h
        src/SearchEngine.cpp)
