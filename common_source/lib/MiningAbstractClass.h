#ifndef MININGABSTRACTCLASS_INCLUDED
#define MININGABSTRACTCLASS_INCLUDED

#include "BangBit.h"
#include <vector>
#include <string>

namespace NguyenQuocHuy {
    class MiningAbstractClass {
    protected:
        static std::vector<std::string> tachChuoiDungDelimiter(std::string s, char delim);

        void docMetaData(const char* metaDataFileName);
        void docData(const char* dataFileName);
        std::vector<std::string> layDanhSachTen(const std::vector<int> &danhSachItem) const; 

        virtual bool kiemTraSuPhoBien(const std::vector<int> &danhSachItem) const = 0;

        int soItem;
        int soTransaction;
        double minSup;
        double minConf;
        BangBit* csdl;
        std::vector<std::string> tenItem;
    public:
        virtual std::vector< std::vector<std::string> > mining() = 0;
        virtual ~MiningAbstractClass() {}
    };
}

#endif
