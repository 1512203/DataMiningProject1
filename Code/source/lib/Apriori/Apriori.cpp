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

    std::vector<int> Apriori::joinTwoItemsets(const std::vector<int> &x, const std::vector<int> &y) const {
        std::vector<int> res;
        int n = x.size(), m = y.size();
        if (n != m) return res;

        for (int i = 0; i < n-1; ++i)
            if (x[i] != y[i])
                return res;
        
        if (x[n-1] < y[n-1]) {
            res = x;
            res.push_back(y[n-1]);
        }
        else {
            res = y;
            res.push_back(x[n-1]);
        }

        return res;
    }

    bool Apriori::hasInfrequentSubset(const std::vector<int> &itemset, const std::vector< std::vector<int> > &L) const {
        for (int i = 0, sz = itemset.size(); i < sz; ++i) {
            std::vector<int> tmp(itemset.begin(), itemset.begin() + i);
            tmp.insert(tmp.end(), itemset.begin() + i + 1, itemset.end());

            bool reallyFound = false;
            for (int j = 0, sz_L = L.size(); j < sz_L; ++j) {
                bool found = true;
                for (int k = 0, sz_tmp = tmp.size(); k < sz_tmp; ++k) 
                    if (tmp[k] != L[j][k]) {
                        found = false;
                        break;
                    }
                if (found) {
                    reallyFound = true;
                    break;
                }
            }
            if (!reallyFound) 
                return false;
        }
        return true;
    }

    std::vector< std::vector<int> > Apriori::AprioriGen(const std::vector< std::vector<int> > &L) const {
        std::vector< std::vector<int> > result;
        int size_L = L.size();
        for (int i = 0; i < size_L; ++i) 
            for (int j = i+1; j < size_L; ++j) {
                std::vector<int> itemset = this->joinTwoItemsets(L[i], L[j]);
                if (itemset.size() > 0 && this->hasInfrequentSubset(itemset, L) && this->kiemTraSuPhoBien(itemset)) 
                    result.push_back(itemset);
            }
        return result;
    }

    std::vector< std::vector<std::string> > Apriori::mining() {
        std::vector< std::vector<int> > tapPhoBien;
        for (int i = 0; i < this->soItem; ++i) {
            std::vector<int> item;
            item.push_back(i);
            if (this->kiemTraSuPhoBien(item)) 
                tapPhoBien.push_back(item);
        }

        std::vector< std::vector<int> > tapPhoBienCu = tapPhoBien;
        for (int kichThuoc = 2; kichThuoc <= this->soItem; ++kichThuoc) {
            std::vector< std::vector<int> > tapPhoBienMoi = this->AprioriGen(tapPhoBienCu);
            tapPhoBien.insert(tapPhoBien.end(), tapPhoBienMoi.begin(), tapPhoBienMoi.end());
            tapPhoBienCu = tapPhoBienMoi;
        }

        std::vector< std::vector<std::string> > ketQua;
        for (int i = 0, sz = tapPhoBien.size(); i < sz; ++i) 
            ketQua.push_back(layDanhSachTen(tapPhoBien[i]));
        return ketQua;
    }

    /*  ----------------------------------------  */

};
