#include "Sorting_Support.h"
#include <algorithm>

namespace NguyenQuocHuy {
    void sapXepMotMangTheoMotKhoa(int soPhanTu, int *mangMuonXep, int* mangKhoa) {
        std::sort(mangMuonXep, mangMuonXep+soPhanTu, CompareKeyDecreasing(mangKhoa));
    }
}
