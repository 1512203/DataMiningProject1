#include "FPTree_Support.h"

namespace NguyenQuocHuy {
    void sapXepMotMangTheoMotKhoa(int soPhanTu, int* mangMuonXep, int* mangKhoa) {
        std::sort(mangMuonXep, mangMuonXep+soPhanTu, Compare(mangKhoa));
    }

    FPTreePNode newFPTreeNode(int itemID, int count) {
        FPTreePNode p = new FPTreeNode();
        p->itemID = itemID;
        p->count = count;
        p->listChildren.clear();
        return p;
    }

    void insertTransaction(FPTreePNode root, const std::vector<int> &transaction) {
        for (int i = 0, sz = transaction.size(); i < sz; ++i) {
            FPTreePNode newNode = NULL;
            for (int j = 0, sz = root->listChildren.size(); j < sz; ++j) 
                if (transaction[i] == root->listChildren[j]->itemID) {
                    newNode = root->listChildren[j];
                    newNode->count++;
                    break;
                }
            if (!newNode) {
                newNode = newFPTreeNode(transaction[i]);
                root->listChildren.push_back(newNode);
            }
            root = newNode;
        }
    }

    void clearTree(FPTreePNode &p) {
        for (int i = 0, sz = p->listChildren.size(); i < sz; ++i)
            clearTree(p->listChildren[i]);
        p->listChildren.clear();
        delete p;
    }
}
