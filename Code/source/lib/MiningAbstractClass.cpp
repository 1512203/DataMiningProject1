#include "MiningAbstractClass.h"
#include <fstream>

namespace NguyenQuocHuy {
    /*  ---------- Static members ---------- */

    std::vector<std::string> MiningAbstractClass::tachChuoiDungDelimiter(std::string s, char delim) {
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


    /*  ---------- Non-static members ----------  */

    std::vector<std::string> MiningAbstractClass::layDanhSachTen(const std::vector<int> &danhSachItem) const {
        std::vector<std::string> ketQua;
        for (int i = 0, sz = danhSachItem.size(); i < sz; ++i)
            ketQua.push_back(this->tenItem[danhSachItem[i]]);
        return ketQua;
    }

    void MiningAbstractClass::docMetaData(const char* metaDataFileName) {
        std::ifstream fi(metaDataFileName, std::ifstream::in);
        fi >> this->soTransaction >> this->soItem >> this->minSup >> this->minConf;
        this->csdl = new BangBit(this->soItem, this->soTransaction);
        fi.close();
    }

    void MiningAbstractClass::docData(const char* dataFileName) {
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
}
