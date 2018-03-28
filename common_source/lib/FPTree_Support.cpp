#include "FPTree_Support.h"
#include "Sorting_Support.h"
#include <cstring>
#include <cstdio>

namespace NguyenQuocHuy {
    /* ---------- Static members ----------  */

    FPTreePNode FPTreeOperationContainer::newFPTreeNode(int itemID, FPTreePNode parent) {
        FPTreePNode p = new FPTreeNode();
        p->itemID = itemID;
        p->count = 0;
        p->parent = parent;
        p->listChildren.clear();
        return p;
    }

    /* ------------------------------------  */

    FPTreeOperationContainer::FPTreeOperationContainer(int _nItems, int* _itemOrdered) {
        this->root = newFPTreeNode(-1, NULL);
        this->nItems = _nItems;
        this->nTransactions = 0;
        this->headList = new std::vector<FPTreePNode>[_nItems];
        this->itemOrdered = new int[this->nItems];
        memcpy(this->itemOrdered, _itemOrdered, sizeof(int) * this->nItems);
        for (int i = 0; i < _nItems; ++i)
            printf("%d ", this->itemOrdered[i]);
        puts("");
    }

    FPTreeOperationContainer::~FPTreeOperationContainer() {
        delete this->root;
        for (int i = 0; i < this->nItems; ++i) {
            for (int j = 0, sz = this->headList[i].size(); j < sz; ++j) 
                delete this->headList[i][j];
            this->headList[i].clear();
        }
        delete[] this->headList;
        delete[] this->itemOrdered;
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
        return newNode;
    }

    void FPTreeOperationContainer::insertTransaction(const std::vector<int> &transaction, int freq) {
        FPTreePNode p = this->root;
        for (int i = 0, sz = transaction.size(); i < sz; ++i) {
            FPTreePNode newNode = this->findBranchToGo(p, transaction[i]);
            newNode->count += freq;
            p = newNode;
        }
        this->nTransactions += freq;
    }

    FPTreeOperationContainer FPTreeOperationContainer::unblockConditionalFPTree(int itemID) {
        int* count = new int[this->nItems];
        memset(count, 0, sizeof(int) * this->nItems);
        for (int i = 0, sz = this->headList[itemID].size(); i < sz; ++i) {
            FPTreePNode p = this->headList[itemID][i];
            int freq = p->count;

            for (FPTreePNode q = p->parent; q != this->root; q = q->parent) 
                count[q->itemID] += freq;
        }

        int* itemList = new int[this->nItems];
        for (int i = 0; i < nItems; ++i) 
            itemList[i] = i;
        sapXepMotMangTheoMotKhoa(this->nItems, itemList, count);

        FPTreeOperationContainer result(this->nItems, itemList);

        for (int i = 0, sz = this->headList[itemID].size(); i < sz; ++i) {
            FPTreePNode p = this->headList[itemID][i];
            int freq = p->count;

            std::vector<int> transaction;
            for (FPTreePNode q = p->parent; q != this->root; q = q->parent) 
                transaction.push_back(q->itemID);
            sapXepMotMangTheoMotKhoa(transaction, count);
            for (int j = 0, sz_t = transaction.size(); j < sz_t; ++j) {
                printf("%d ", transaction[j]);
            }
            puts("\n###***###\n");
            result.insertTransaction(transaction, freq);
        }

        delete[] itemList;
        delete[] count;
        return result;
    }

    std::vector< std::vector<int> > FPTreeOperationContainer::findConditionalFrequentSet(double threshold) {
        std::vector< std::vector<int> > result;
        for (int i = this->nItems-1; i >= 0; --i) {
            int item = this->itemOrdered[i];
            printf("## %d\n", item);
            FPTreeOperationContainer conditionalFPTree = this->unblockConditionalFPTree(item);
            printf("*** %d\n", conditionalFPTree.nTransactions);
            if (conditionalFPTree.nTransactions < threshold) 
                break;

            std::vector< std::vector<int> > subRes = conditionalFPTree.findConditionalFrequentSet(threshold);
            for (int j = 0, sz = subRes.size(); j < sz; ++j) 
                subRes[j].push_back(item);
            result.insert(result.end(), subRes.begin(), subRes.end());
        }
        return result;
    }

}
