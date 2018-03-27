#include "FPTree_Support.h"

namespace NguyenQuocHuy {
    /* ---------- Static members ----------  */

    FPTreePNode FPTreeOperationContainer::newFPTreeNode(int itemID, FPTreePNode parent) {
        FPTreePNode p = new FPTreeNode();
        p->itemID = itemID;
        p->count = 0;
        p->tempCount = 0;
        p->isBlocked = true;
        p->parent = parent;
        p->listChildren.clear();
        return p;
    }

    /* ------------------------------------  */

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
            FPTreePNode newNode = this->findBranchToGo(p, transaction[i]);
            this->headList[transaction[i]][0]->count++;
            p = newNode;
        }
    }

    void FPTreeOperationContainer::unblockConditionalFPTree(int itemID) {
        for (int i = 1, sz = this->headList[itemID].size(); i < sz; ++i) {
            int freq = this->headList[itemID][i]->count;
            FPTreePNode p = this->headList[itemID][i];
            FPTreePNode q = p->parent;

            do {
                p->isBlocked = false;
                p->tempCount += freq;
                p = q;
                q = q->parent;
            } while (p == this->root);
        }
    }

    std::vector< std::vector<int> > FPTreeOperationContainer::conditionalFPSet(int itemID, double threshold) {
        std::vector< std::vector<int> > result;
        this->unblockConditionalFPTree(itemID);
        return result;
    }

    void clearTree(FPTreePNode &p) {
        for (int i = 0, sz = p->listChildren.size(); i < sz; ++i)
            clearTree(p->listChildren[i]);
        p->listChildren.clear();
        delete p;
    }

}
