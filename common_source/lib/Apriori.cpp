#include "Apriori.h"
#include <new>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>

namespace NguyenQuocHuy {

    /*  ---------- Non-static members ----------  */



    bool Apriori::kiemTraSuPhoBien(const std::vector<int> &danhSachItem) const {
        int soTransactionChuaDanhSachItem = this
                                            ->csdl
                                            ->layANDCuaCacDong(danhSachItem.size(), danhSachItem.data())
                                            .demSoBit1(); 
        return soTransactionChuaDanhSachItem >= (this->minSup / 100.0) * this->soTransaction;
    }

    Apriori::Apriori(const std::string &dataFileName, const std::string &metaDataFileName) {
        this->docMetaData(metaDataFileName.c_str());
        this->docData(dataFileName.c_str());
    }

    Apriori::Apriori(const Apriori &other) {
        this->soItem = other.soItem;
        this->soTransaction = other.soTransaction;
        this->minSup = other.minSup;
        this->minConf = other.minConf;
        this->tenItem = other.tenItem;
        this->csdl = new BangBit(*other.csdl);
    }

    void Apriori::operator = (const Apriori &other) {
        BangBit* temp = this->csdl;
        this->soItem = other.soItem;
        this->soTransaction = other.soTransaction;
        this->minSup = other.minSup;
        this->minConf = other.minConf;
        this->tenItem = other.tenItem;
        this->csdl = new BangBit(*other.csdl);
        delete temp;
    }

    Apriori::~Apriori() {
        delete this->csdl;
    }


    std::vector< std::vector<std::string> > Apriori::mining() {
        std::vector< std::vector<int> > tapPhoBien;
        std::vector<int> itemPhoBien;
        for (int i = 0; i < this->soItem; ++i) {
            std::vector<int> item;
            item.push_back(i);
            if (this->kiemTraSuPhoBien(item)) {
                itemPhoBien.push_back(i);
                tapPhoBien.push_back(item);
            }
        }
        int linhCanh = tapPhoBien.size();

        for (int kichThuoc = 2, dauMang = 0, cuoiMang = linhCanh; 
                dauMang < cuoiMang && kichThuoc <= this->soItem; 
                    ++kichThuoc) {
            for (int i = dauMang; i < cuoiMang; ++i) 
                for (int j = 0; j < linhCanh; ++j) 
                    if (tapPhoBien[i][tapPhoBien[i].size()-1] < itemPhoBien[j]) {
                        std::vector<int> item_set = tapPhoBien[i];
                        item_set.push_back(itemPhoBien[j]);
                        if (this->kiemTraSuPhoBien(item_set)) 
                            tapPhoBien.push_back(item_set);
                    }
            dauMang = cuoiMang;
            cuoiMang = tapPhoBien.size();
        }
        std::vector< std::vector<std::string> > ketQua;
        for (int i = 0, sz = tapPhoBien.size(); i < sz; ++i) 
            ketQua.push_back(layDanhSachTen(tapPhoBien[i]));
        return ketQua;
    }

    /*  ----------------------------------------  */

};
