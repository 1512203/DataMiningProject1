#ifndef CSDLNHIPHAN_INCLUDED
#define CSDLNHIPHAN_INCLUDED
#include "../lib/BangBit.h"
#include <string>
#include <vector>

namespace NguyenQuocHuy {
    class CSDLNhiPhan {
    private:
    	static std::vector<std::string> tachChuoiDungDelimiter(std::string s, char delim);
    public:
        void docMetaData(const char* metaDataFileName);
        void docData(const char* dataFileName);

        int soItem;
        int soTransaction;
        double minSup; // min supply
        double minConf; // min confident
    	BangBit* csdl;
    	std::vector<std::string> tenThuocTinh;
    public:
    	CSDLNhiPhan(const std::string &dataFileName, const std::string &metaDataFileName);
    	CSDLNhiPhan(const CSDLNhiPhan &other);
    	~CSDLNhiPhan();
    };
};

#endif
