#ifndef FPTREE_SUPPORT_INCLUDED
#define FPTREE_SUPPORT_INCLUDED

#include <vector>
#include <cstdio>

namespace NguyenQuocHuy {
    typedef struct FPTreeNode FPTreeNode;
    typedef FPTreeNode* FPTreePNode;
    struct FPTreeNode {
        int itemID;
        int count;
        int tempCount;
        bool isBlocked;
        FPTreePNode parent;
        std::vector<FPTreePNode> listChildren;
    };

    class FPTreeOperationContainer {
    private:
        static FPTreePNode newFPTreeNode(int itemID, FPTreePNode parent = NULL);

        FPTreePNode findBranchToGo(FPTreePNode p, int itemID);
        FPTreePNode makeNewConnection(int itemID, FPTreePNode p);
        void unblockConditionalFPTree(int itemID);

        FPTreePNode root;
        int nItems;
        std::vector<FPTreePNode> *headList;
    public:
        FPTreeOperationContainer(int nItems);
        void insertTransaction(const std::vector<int> &transaction);
        std::vector< std::vector<int> > conditionalFPSet(int itemID, double threshold);
        ~FPTreeOperationContainer();
    };

    void clearTree(FPTreePNode &p);
}

#endif

