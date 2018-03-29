#ifndef FPTREE_INCLUDED
#define FPTREE_INCLUDED

#include "MiningAbstractClass.h"
#include "FPTree_Support.h"
#include <string>
#include <vector>

namespace NguyenQuocHuy {
    class FPTree: MiningAbstractClass {
    private:
    protected:
        void sapXepItem();

        int* doPhoBien;
        int* danhSachItemSauSapXep;
    public:
        FPTree(const std::string &dataFileName, const std::string &metaDataFileName);
        FPTree(const FPTree &other);
        void operator = (const FPTree &other);

        std::vector< std::vector<std::string> > mining();

        ~FPTree();

    };
}

#endif
