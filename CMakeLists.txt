cmake_minimum_required(VERSION 2.8)
project(mmix-converter)
add_executable(mmix-convert main.c)
install(TARGETS mmix-convert DESTINATION bin)
