#include "CSDLNhiPhan.h"
#include <new>
#include <string>
#include <vector>
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
        std::cout << fi.is_open() << std::endl;
        std::cout << metaDataFileName << std::endl;
        fi >> this->soTransaction >> this->soItem >> this->minSup >> this->minConf;
        std::cout << this->soItem << " " << this->soTransaction << std::endl;
        this->csdl = new BangBit(this->soItem, this->soTransaction);
        fi.close();
    }

    void CSDLNhiPhan::docData(const char* dataFileName) {
        std::ifstream fi(dataFileName, std::ifstream::in);
        std::string buff = "";
        std::vector<std::string> motTransaction;

        std::getline(fi, buff);
        this->tenThuocTinh = tachChuoiDungDelimiter(buff, ',');

        for (int tid = 0; tid < this->soTransaction; ++tid) {
            std::getline(fi, buff);
            motTransaction = tachChuoiDungDelimiter(buff, ',');
            for (int iid = 0; iid < this->soItem; ++iid) 
                if (motTransaction[iid].length() > 0) 
                    this->csdl->ganO(iid, tid, motTransaction[iid][0]-'0');
        }

        fi.close();
    }

	CSDLNhiPhan::CSDLNhiPhan(const std::string &dataFileName, const std::string &metaDataFileName) {
        this->docMetaData(metaDataFileName.c_str());
        this->docData(dataFileName.c_str());
	}

    CSDLNhiPhan::CSDLNhiPhan(const CSDLNhiPhan &other) {
        this->soItem = other.soItem;
        this->soTransaction = other.soTransaction;
        this->minSup = other.minSup;
        this->minConf = other.minConf;
        this->tenThuocTinh = other.tenThuocTinh;
        this->csdl = new BangBit(*other.csdl);
    }

	CSDLNhiPhan::~CSDLNhiPhan() {
        delete this->csdl;
	}

    /*  ----------------------------------------  */
};
