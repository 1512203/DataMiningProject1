#ifndef APRIORI_INCLUDED 
#define APRIORI_INCLUDED 
#include "MiningAbstractClass.h"
#include <string>
#include <vector>

namespace NguyenQuocHuy {
    class Apriori: MiningAbstractClass {
    protected:
        std::vector<int> joinTwoItemsets(const std::vector<int> &x, const std::vector<int> &y) const;
        bool hasInfrequentSubset(const std::vector<int> &itemset, const std::vector< std::vector<int> > &L) const;
        std::vector< std::vector<int> > AprioriGen(const std::vector< std::vector<int> > &L) const;

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
