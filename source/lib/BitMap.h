#ifndef BITMAP_INCLUDED
#define BITMAP_INCLUDED

namespace NguyenQuocHuy {
    class BitMap {
    private:
        typedef unsigned char tblock;
        static const int BYTE_SZ = 8; // 8 bits / byte

        static int doiSoBitSangSoBlock(int soBitCuaMang);
        static int tinhSoBitCuaMang(int slDong, int slCot);

        int tinhSoBitToiO(int dong, int cot) const;
        int layBitTaiViTri(int viTri) const;
        void ganBitTaiViTri(int viTri, int val);

    protected:
        int soDong;
        int soCot;
        tblock *noiDung;

    public:
        BitMap(int slDong, int slCot);
        
        int laySoDong() const;
        int laySoCot() const;

        int layNoiDung(int dong, int cot) const;
        void ganNoiDung(int dong, int cot, int val);

        ~BitMap();
    };
};

#endif
