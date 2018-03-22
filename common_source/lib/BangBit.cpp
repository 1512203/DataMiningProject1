#include "BangBit.h"
#include <new>
#include <cstring>

namespace NguyenQuocHuy {
    /*    ---------- Static members ----------  */

    int BangBit::tinhSoBlockBietSoBit(int soBit) {
        return ((soBit - 1) / BLOCK_SZ) + 1;
    }

    int BangBit::tinhSoByteChoBang(int slByteMotDong, int slDong) {
        return slByteMotDong * slDong;
    }

    int BangBit::tinhVitriCuaOTrenMang(int dong, int cot, int slByteMotDong) {
        int slByteDongCuoi = tinhSoBlockBietSoBit(cot + 1);
        int slByteTruocDongCuoi = tinhSoByteChoBang(slByteMotDong, dong);
        int viTriCuaOTrenMang = slByteTruocDongCuoi + slByteDongCuoi - 1;
        return viTriCuaOTrenMang;
    }

    int BangBit::tinhViTriCuaOTrongBlock(int dong, int cot) {
        int viTriCuaOTrongBlock = cot % BLOCK_SZ;
        return viTriCuaOTrongBlock;
    }

    int BangBit::layMotBitCuaMotPhanTuCuaMang(const tblock* mang, int chiSoPhanTu, int chiSoBit) {
        return (mang [ chiSoPhanTu ] >> chiSoBit) & 1;
    }

    void BangBit::ganMotBitChoMotPhanTuCuaMang(tblock* mang, int chiSoPhanTu, int chiSoBit, int giaTri) {
        giaTri &= 1;
        giaTri ^= layMotBitCuaMotPhanTuCuaMang(mang, chiSoPhanTu, chiSoBit);
        mang [ chiSoPhanTu ] ^= (giaTri << chiSoBit);
    }

    void BangBit::ANDMangVoiMang(tblock* mang_1, const tblock* mang_2, int slPhanTu) {
        for (int i = 0; i < slPhanTu; ++i) {
            mang_1[i] &= mang_2[i];
        }
    }

    /*    ---------- ############## ----------  */



    /*    ---------- Non-static members ----------  */

    BangBit::BangBit(int slDong, int slCot) {
        this->soDong = slDong;
        this->soCot = slCot;
        this->soByteMotDong = tinhSoBlockBietSoBit(slCot);
        this->soByteChoBang = tinhSoByteChoBang(this->soByteMotDong, slDong);
        this->duLieu = new tblock[ this->soByteChoBang ];
        memset(this->duLieu, 0, this->soByteChoBang * sizeof(tblock));
    }

    BangBit::BangBit(const BangBit &other) {
        this->soDong = other.soDong;
        this->soCot = other.soCot;
        this->soByteMotDong = other.soByteMotDong;
        this->soByteChoBang = other.soByteChoBang;
        this->duLieu = new tblock[ this->soByteChoBang ];
        memcpy(this->duLieu, other.duLieu, this->soByteChoBang * sizeof(tblock));
    }

    int BangBit::laySoDong() const {
        return this->soDong;
    }

    int BangBit::laySoCot() const {
        return this->soCot;
    }

    int BangBit::layO(int dong, int cot) const {
        int viTriCuaOTrenMang = tinhVitriCuaOTrenMang(dong, cot, this->soByteMotDong);
        int viTriCuaOTrongBlock = tinhViTriCuaOTrongBlock(dong, cot);
        return layMotBitCuaMotPhanTuCuaMang(this->duLieu, viTriCuaOTrenMang, viTriCuaOTrongBlock);
    }

    void BangBit::ganO(int dong, int cot, int giaTri) {
        int viTriCuaOTrenMang = tinhVitriCuaOTrenMang(dong, cot, this->soByteMotDong);
        int viTriCuaOTrongBlock = tinhViTriCuaOTrongBlock(dong, cot);
        ganMotBitChoMotPhanTuCuaMang(this->duLieu, viTriCuaOTrenMang, viTriCuaOTrongBlock, giaTri);
    }

    BangBit BangBit::layANDCuaCacDong(int slDong, ...) {
        BangBit ketQua(1, this->soDong);
        va_list vl;
        va_start(vl, slDong);
        for (int i = 0; i < slDong; ++i) {
            int dong = va_arg(vl, int);
            int chiSoMangCuaPhanTuDauDong = tinhSoByteChoBang(this->soByteMotDong, dong);
            ANDMangVoiMang(ketQua.duLieu, this->duLieu + chiSoMangCuaPhanTuDauDong, this->soByteMotDong);
        }
        va_end(vl);
        return ketQua;
    }

    BangBit::~BangBit() {
        delete[] this->duLieu;
    }

    /*  ---------- ################## ----------  */
}