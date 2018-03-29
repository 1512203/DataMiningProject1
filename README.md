# Bài tập Lab #1 - Môn Data Mining
## Yêu cầu hệ thống:
* Hệ điều hành Ubuntu 16.04
* Hỗ trợ g++ 5.4.0
* Hỗ trợ Makefile
## Cấu trúc tập tin:
```
./
|-- README.md
|-- source/
|   |-- lib/
|   |   |-- BangBit
|   |   |   |-- BangBit.cpp
|   |   |   |-- BangBit.h
|   |   |-- Apriori
|   |   |   |-- Apriori.cpp
|   |   |   |-- Apriori.h
|   |   |-- FPTree
|   |   |   |-- FPTree.cpp
|   |   |   |-- FPTree.h
|   |   |   |-- FPTree_Support.cpp
|   |   |   |-- FPTree_Support.h
|   |   |   |-- Sorting_Support.cpp
|   |   |   |-- Sorting_Support.h
|   |   |-- MiningAbstractClass.cpp
|   |   |-- MiningAbstractClass.h
|   |   |-- Makefile
|   |-- test/
|   |   |-- data.csv
|   |   |-- meta-data.txt
|   |   |-- test_MiningUsingApriori.cpp
|   |   |-- test_MiningUsingFPTree.cpp
|   |   |-- Makefile
|   |-- Makefile
|   |-- RunApriori.sh
|   |-- RunFPTree.sh
```
## Huớng dẫn cách build:
Tại thư mục gốc của project, chạy
```ShellScript
make all
```
## Huớng dẫn cách chạy:
