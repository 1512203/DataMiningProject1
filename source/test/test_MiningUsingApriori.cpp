#include <cstdio>
#include <vector>
#include <string>

#include "../lib/BangBit.h"
#include "../lib/Apriori.h"

#define DATA_FILE_NAME "data.csv"
#define METADATA_FILE_NAME "meta-data.txt"
#define OUTPUT_FILE_NAME "result.txt"

int main() {
    using namespace NguyenQuocHuy;
    using namespace std;
    Apriori D(DATA_FILE_NAME, METADATA_FILE_NAME);
    vector< vector<string> > res = D.mining();

    FILE* fo = fopen(OUTPUT_FILE_NAME, "w");
    for (int i = 0, sz = res.size(); i < sz; ++i) {
        for (int j = 0, sz_j = res[i].size(); j < sz_j; ++j) {
            fprintf(fo, "%s%c", res[i][j].c_str(), (j == sz_j-1) ? '\n' : ',');
        }
    }
    fclose(fo);
    return 0;
}
