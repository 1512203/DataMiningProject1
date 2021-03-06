# Bài tập Lab #1 - Môn Data Mining
## Người cài đặt
* Họ và tên: Nguyễn Quốc Huy
* Truờng Đại học Khoa học tự nhiên TP. Hồ Chí Minh
* Lớp 15CNTN

## Yêu cầu hệ thống:
* Hệ điều hành Ubuntu 16.04
* Hỗ trợ g++ 5.4.0 (c++11)
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
|   |-- Apriori_res/
|   |   |-- MiningUsingApriori.cpp
|   |   |-- Makefile
|   |-- FPTree_res/
|   |   |-- MiningUsingFPTree.cpp
|   |   |-- Makefile
|   |-- meta-data.txt
|   |-- data.csv
|   |-- RunApriori.sh
|   |-- RunFPTree.sh
|   |-- Makefile
```
## Huớng dẫn cách chạy:
### Build:
Trong terminal, __tại thư mục ./source của project__, chạy lệnh
```ShellScript
make all
```
### Chạy:
Trong terminal, __tại thư mục ./source của project__:
* Để sinh tập phổ biến dùng thuật toán Apriori
```ShellScript
bash RunApriori.sh
```
* Để sinh tập phổ biến dùng FP-Tree
```ShellScript
bash RunFPTree.sh
```
Các tập phổ biến sẽ đưọc xuất ra màn hình
## Bộ dữ liệu
Dữ liệu đưọc tạo truớc và lưu trong 2 file _meta-data.txt_ và _data.csv_, trong đó:
* _meta-data.txt_: Chứa 4 số lần luợt là: số item, số transaction, minSupport và minConfidence
* _data.csv_: chứa các transaction: 
    * dòng đầu là danh sách tên các item (phân biệt nhau bởi dấu ```,```)
    * các dòng sau, mỗi dòng là một transaction, gồm các số 0 và 1, cách nhau bởi dấu ```,```

