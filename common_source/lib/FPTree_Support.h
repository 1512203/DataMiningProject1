#ifndef FPTREE_SUPPORT_INCLUDED
#define FPTREE_SUPPORT_INCLUDED

#include <vector>
#include <cstdio>
#include <algorithm>

namespace NguyenQuocHuy {
    //  Dung de sap xep item
    struct Compare {
        int* sortKey;

        Compare(int* key) { 
            sortKey = key; 
        }

        bool operator() (const int &x, const int &y) const {
            return sortKey[x] < sortKey[y];
        }
    };

    void sapXepMotMangTheoMotKhoa(int soPhanTu, int* mangMuonXep, int* mangKhoa); 

    //  Luu cay FP
    struct FPTreeNode {
        int itemID;
        int count;
        std::vector<FPTreeNode*> listChildren;
    };

    typedef FPTreeNode* FPTreePNode;

    FPTreePNode newFPTreeNode(int itemID, int count = 1); 
    void insertTransaction(FPTreePNode root, const std::vector<int> &transaction); 
    void clearTree(FPTreePNode &p);
}

#endif
