#include "FPTree.h"
#include "Sorting_Support.h"
#include <cstring>

namespace NguyenQuocHuy {
    /*  ---------- Non-staic members ----------  */

    void FPTree::sapXepItem() {
        this->doPhoBien = new int[this->soItem];
        this->danhSachItemSauSapXep = new int[this->soItem];

        for (int i = 0; i < this->soItem; ++i) {
            this->danhSachItemSauSapXep[i] = i;
            this->doPhoBien[i] = this->csdl->layANDCuaCacDong(1, &i).demSoBit1();
        }
        sapXepMotMangTheoMotKhoa(this->soItem, this->danhSachItemSauSapXep, this->doPhoBien);
    }

    FPTree::FPTree(const std::string &dataFileName, const std::string &metaDataFileName) {
        this->docMetaData(metaDataFileName.c_str());
        this->docData(dataFileName.c_str());
        this->sapXepItem();
    }

    FPTree::FPTree(const FPTree &other) {
        this->soItem = other.soItem;
        this->soTransaction = other.soTransaction;
        this->minSup = other.minSup;
        this->minConf = other.minConf;
        this->tenItem = other.tenItem;
        this->csdl = new BangBit(*other.csdl);
        this->danhSachItemSauSapXep = new int[this->soItem];
        memcpy(this->danhSachItemSauSapXep, other.danhSachItemSauSapXep, sizeof(int) * this->soItem);
        this->doPhoBien = new int[this->soItem];
        memcpy(this->doPhoBien, other.doPhoBien, sizeof(int) * this->soItem);
    }

    void FPTree::operator = (const FPTree &other) {
        delete this->csdl;
        delete[] this->danhSachItemSauSapXep;
        delete[] this->doPhoBien;
        this->soItem = other.soItem;
        this->soTransaction = other.soTransaction;
        this->minSup = other.minSup;
        this->minConf = other.minConf;
        this->tenItem = other.tenItem;
        this->csdl = new BangBit(*other.csdl);
        this->danhSachItemSauSapXep = new int[this->soItem];
        memcpy(this->danhSachItemSauSapXep, other.danhSachItemSauSapXep, sizeof(int) * this->soItem);
        this->doPhoBien = new int[this->soItem];
        memcpy(this->doPhoBien, other.doPhoBien, sizeof(int) * this->soItem);
    }

    std::vector< std::vector<std::string> > FPTree::mining() {
        FPTreeOperationContainer fpTree(this->soItem, this->danhSachItemSauSapXep);
        for (int i = 0; i < this->soTransaction; ++i) {
            std::vector<int> transaction;
            for (int j = 0; j < this->soItem; ++j) 
                if (this->csdl->layO(this->danhSachItemSauSapXep[j], i))
                    transaction.push_back(this->danhSachItemSauSapXep[j]);
            fpTree.insertTransaction(transaction);
        }
        std::vector< std::vector<int> > tapPhoBien = fpTree.findConditionalFrequentSet(this->soTransaction * this->minSup / 100.0);

        std::vector< std::vector<std::string> > ketQua;
        for (int i = 0, sz = tapPhoBien.size(); i < sz; ++i)
            ketQua.push_back(this->layDanhSachTen(tapPhoBien[i]));
        return ketQua;
    }

    FPTree::~FPTree() {
        delete this->csdl;
        delete[] this->doPhoBien;
        delete[] this->danhSachItemSauSapXep;
    }

    /*  ---------------------------------------  */
}
