#include "../lib/BitMap.h"
#include <cstdio>

void printMap(int n, int m, const NguyenQuocHuy::BitMap &bm) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            printf("%d ", bm.layNoiDung(i, j));
        puts("");
    }
}
int main() {
    int n = 4, m = 4;
    NguyenQuocHuy::BitMap bm(n, m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            bm.ganNoiDung(i, j, i+j);
    while (true) {
        int tp = 2;
        scanf("%d", &tp);
        if (tp == 0) {
            printMap(n, m, bm);
        }
        else if (tp == 1) {
            int col = 0, row = 0, val = 0;
            scanf("%d %d %d", &row, &col, &val);
            bm.ganNoiDung(row, col, val);
        }
        else {
            break;
        }
    }
	return 0;
}
