#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "../lib/BangBit.h"
#include "../lib/CSDLNhiPhan.h"

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
    using namespace NguyenQuocHuy;
    CSDLNhiPhan trans("data.csv", "meta-data.txt");
    printBM(*trans.csdl);
    return 0;
}
