@echo off
g++ -Wall -c test.cpp
g++ -o result.exe test.o -L.\shad5\lib\ -lshad5