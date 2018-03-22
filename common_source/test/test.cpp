#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "../lib/BangBit.h"

void printBM(const NguyenQuocHuy::BangBit &bm) {
    for (int i = 0; i < bm.laySoDong(); ++i) {
        for (int j = 0; j < bm.laySoCot(); ++j) {
            printf("%d ", bm.layO(i, j));
        }
        puts("");
    }
    puts("");
}

int main() {
    srand(time(NULL));
    using namespace NguyenQuocHuy;
    int n = 10;
    BangBit bm(n, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            bm.ganO(i, j, rand()%2);
    }
    printBM(bm);
    BangBit b = bm.layANDCuaCacDong(4, 0, 2, 5, 7);
    printBM(b);
    return 0;
}
