#include "FPTree_Support.h"

namespace NguyenQuocHuy {
    FPTreePNode FPTreeOperationContainer::newFPTreeNode(int itemID, FPTreePNode parent) {
        FPTreePNode p = new FPTreeNode();
        p->itemID = itemID;
        p->count = 0;
        p->tempCount = 0;
        p->parent = parent;
        p->listChildren.clear();
        return p;
    }

    FPTreeOperationContainer::FPTreeOperationContainer(int _nItems) {
        this->root = newFPTreeNode(-1, NULL);
        this->nItems = _nItems;
        this->headList = new std::vector<FPTreePNode>[_nItems];
        for (int i = 0; i < this->nItems; ++i) 
            this->headList[i].push_back(newFPTreeNode(i, NULL));
    }

    FPTreePNode FPTreeOperationContainer::makeNewConnection(int itemID, FPTreePNode p) {
        FPTreePNode newNode = newFPTreeNode(itemID, p);
        p->listChildren.push_back(newNode);
        this->headList[itemID].push_back(newNode);
        return newNode;
    }

    FPTreePNode FPTreeOperationContainer::findBranchToGo(FPTreePNode p, int itemID) {
        FPTreePNode newNode = NULL;
        for (int j = 0, sz = p->listChildren.size(); j < sz; ++j) 
            if (itemID == p->listChildren[j]->itemID) 
                newNode = p->listChildren[j];
        if (!newNode) 
            newNode = this->makeNewConnection(itemID, p);
        newNode->count ++;
        return newNode;
    }

    void FPTreeOperationContainer::insertTransaction(const std::vector<int> &transaction) {
        FPTreePNode p = this->root;
        for (int i = 0, sz = transaction.size(); i < sz; ++i) {
            FPTreePNode newNode = findBranchToGo(p, transaction[i]);

            this->headList[transaction[i]][0]++;

            p = newNode;
        }
    }

    void clearTree(FPTreePNode &p) {
        for (int i = 0, sz = p->listChildren.size(); i < sz; ++i)
            clearTree(p->listChildren[i]);
        p->listChildren.clear();
        delete p;
    }
}
