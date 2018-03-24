#ifndef CSDLNHIPHAN_INCLUDED
#define CSDLNHIPHAN_INCLUDED
#include "../lib/BangBit.h"
#include <string>
#include <vector>
#include <set>

namespace NguyenQuocHuy {
    class CSDLNhiPhan {
    private:
        static std::vector<std::string> tachChuoiDungDelimiter(std::string s, char delim);
    protected:
        void docMetaData(const char* metaDataFileName);
        void docData(const char* dataFileName);
        bool kiemTraSuPhoBien(const std::vector<int> &danhSachItem) const;
        std::vector<std::string> layDanhSachTen(const std::vector<int> &danhSachItem) const; 

        int soItem;
        int soTransaction;
        double minSup; // min supply
        double minConf; // min confident
        BangBit* csdl;
        std::vector<std::string> tenItem;
    public:
        CSDLNhiPhan(const std::string &dataFileName, const std::string &metaDataFileName);
        CSDLNhiPhan(const CSDLNhiPhan &other);
        void operator = (const CSDLNhiPhan &other);

        std::vector< std::vector<std::string> > thuatToanApriori();

        ~CSDLNhiPhan();

    };
};

#endif
