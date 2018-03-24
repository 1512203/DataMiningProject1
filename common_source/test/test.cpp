#include <cstdio>
#include <vector>
#include <string>

#include "../lib/BangBit.h"
#include "../lib/CSDLNhiPhan.h"

#define DATA_FILE_NAME "data.csv"
#define METADATA_FILE_NAME "meta-data.txt"

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
    using namespace std;
    CSDLNhiPhan D(DATA_FILE_NAME, METADATA_FILE_NAME);
    vector< vector<string> > res = D.thuatToanApriori();
    for (int i = 0, sz = res.size(); i < sz; ++i) {
        for (int j = 0, sz_j = res[i].size(); j < sz_j; ++j) {
            printf("%s,", res[i][j].c_str());
        }
        puts("");
    }
    return 0;
}
