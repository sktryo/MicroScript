cmake_minimum_required(VERSION 3.10)
project(MicroScript C)

set(CMAKE_C_STANDARD 11)

# ソースファイルのリスト
set(SOURCES
    src/main.c
    src/microscript.c
)

# デバッグフラグの設定
option(DEBUG "Build with debug mode" OFF)

if(DEBUG)
    add_definitions(-DDEBUG)
endif()

# 実行可能ファイルの生成
add_executable(microscript ${SOURCES})
