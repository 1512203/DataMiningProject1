#ifndef APRIORI_INCLUDED 
#define APRIORI_INCLUDED 
#include "MiningAbstractClass.h"
#include <string>
#include <vector>

namespace NguyenQuocHuy {
    class Apriori: MiningAbstractClass {
    private:
    protected:
        bool kiemTraSuPhoBien(const std::vector<int> &danhSachItem) const;

    public:
        Apriori(const std::string &dataFileName, const std::string &metaDataFileName);
        Apriori(const Apriori&other);
        void operator = (const Apriori&other);

        std::vector< std::vector<std::string> > mining();

        ~Apriori();
    };
};

#endif
