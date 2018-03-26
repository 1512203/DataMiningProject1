#ifndef SORTING_SUPPORT_INCLUDED
#define SORTING_SUPPORT_INCLUDED

namespace NguyenQuocHuy {
    struct CompareKeyDecreasing {
        int* sortKey;

        CompareKeyDecreasing(int* key) { 
            sortKey = key; 
        }

        bool operator() (const int &x, const int &y) const {
            return sortKey[x] > sortKey[y];
        }
    };

    void sapXepMotMangTheoMotKhoa(int soPhanTu, int* mangMuonXep, int* mangKhoa); 
}
#endif
