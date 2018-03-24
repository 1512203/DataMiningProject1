#include "CSDLNhiPhan.h"
#include <new>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>

namespace NguyenQuocHuy {
    /*  ---------- Static methods ---------- */

    std::vector<std::string> CSDLNhiPhan::tachChuoiDungDelimiter(std::string s, char delim) {
        std::vector<std::string> ketQua;
        std::string token = "";
        
        s += delim;
        
        for (int i = 0, n = s.length(); i < n; ++i) 
            if (s[i] == delim) {
                if (token.length() > 0) 
                    ketQua.push_back(token);
                token = "";
            }
            else 
                token += s[i];
        return ketQua;
    }

    /*  ------------------------------------ */


    /*  ---------- Non-static methods ----------  */

    void CSDLNhiPhan::docMetaData(const char* metaDataFileName) {
        std::ifstream fi(metaDataFileName, std::ifstream::in);
        fi >> this->soTransaction >> this->soItem >> this->minSup >> this->minConf;
        this->csdl = new BangBit(this->soItem, this->soTransaction);
        fi.close();
    }

    void CSDLNhiPhan::docData(const char* dataFileName) {
        std::ifstream fi(dataFileName, std::ifstream::in);
        std::string buff = "";
        std::vector<std::string> motTransaction;

        std::getline(fi, buff);
        this->tenItem = tachChuoiDungDelimiter(buff, ',');

        for (int tid = 0; tid < this->soTransaction; ++tid) {
            std::getline(fi, buff);
            motTransaction = tachChuoiDungDelimiter(buff, ',');
            for (int iid = 0; iid < this->soItem; ++iid) 
                if (motTransaction[iid].length() > 0) 
                    this->csdl->ganO(iid, tid, motTransaction[iid][0]-'0');
        }

        fi.close();
    }

    bool CSDLNhiPhan::kiemTraSuPhoBien(const std::vector<int> &danhSachItem) const {
        int soTransactionChuaDanhSachItem = this
                                            ->csdl
                                            ->layANDCuaCacDong(danhSachItem.size(), danhSachItem.data())
                                            .demSoBit1(); 
        return soTransactionChuaDanhSachItem >= (this->minSup / 100.0) * this->soTransaction;
    }

    CSDLNhiPhan::CSDLNhiPhan(const std::string &dataFileName, const std::string &metaDataFileName) {
        this->docMetaData(metaDataFileName.c_str());
        this->docData(dataFileName.c_str());
    }

    std::vector<std::string> CSDLNhiPhan::layDanhSachTen(const std::vector<int> &danhSachItem) const {
        std::vector<std::string> ketQua;
        for (int i = 0, sz = danhSachItem.size(); i < sz; ++i)
            ketQua.push_back(this->tenItem[danhSachItem[i]]);
        return ketQua;
    }

    CSDLNhiPhan::CSDLNhiPhan(const CSDLNhiPhan &other) {
        this->soItem = other.soItem;
        this->soTransaction = other.soTransaction;
        this->minSup = other.minSup;
        this->minConf = other.minConf;
        this->tenItem = other.tenItem;
        this->csdl = new BangBit(*other.csdl);
    }

    void CSDLNhiPhan::operator = (const CSDLNhiPhan &other) {
        delete this->csdl;
        this->soItem = other.soItem;
        this->soTransaction = other.soTransaction;
        this->minSup = other.minSup;
        this->minConf = other.minConf;
        this->tenItem = other.tenItem;
        this->csdl = new BangBit(*other.csdl);
    }

    CSDLNhiPhan::~CSDLNhiPhan() {
        delete this->csdl;
    }


    std::vector< std::vector<std::string> > CSDLNhiPhan::thuatToanApriori() {
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
