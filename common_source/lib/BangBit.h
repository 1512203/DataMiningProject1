#ifndef BITMAP_INCLUDED
#define BITMAP_INCLUDED

#include <cstdarg>

namespace NguyenQuocHuy {
    class BangBit {
    private:
        typedef unsigned char tblock;
        static const int BLOCK_SZ = 8; // 8 bits / byte

        static int tinhSoBlockBietSoBit(int soBit);
        static int tinhSoByteChoBang(int slByteMotDong, int slDong);
        static int tinhVitriCuaOTrenMang(int dong, int cot, int slByteMotDong);
        static int tinhViTriCuaOTrongBlock(int dong, int cot);
        static int layMotBitCuaMotPhanTuCuaMang(const tblock* mang, int chiSoPhanTu, int chiSoBit);
        static void ganMotBitChoMotPhanTuCuaMang(tblock* mang, int chiSoPhanTu, int chiSoBit, int giaTri);
        static void ANDMangVoiMang(tblock* mang_1, const tblock* mang_2, int slPhanTu);

    protected:
        int soDong;
        int soCot;
        int soByteMotDong;
        int soByteChoBang;
        tblock *duLieu;

    public:
        BangBit(int slDong, int slCot);
        
        int laySoDong() const;
        int laySoCot() const;

        int layO(int dong, int cot) const;
        void ganO(int dong, int cot, int giaTri);

        BangBit layANDCuaCacDong(int slDong, ...);

        ~BangBit();
    };
};

#endif
