#include "BitMap.h"
#include <cstdio>
#include <cstdlib>

namespace NguyenQuocHuy {
    int BitMap::tinhSoBitCuaMang(int slDong, int slCot) {
        return slDong * slCot;
    }

    int BitMap::doiSoBitSangSoBlock(int soBitCuaMang) {
        return (soBitCuaMang - 1) / BYTE_SZ + 1;
    }



    int BitMap::tinhSoBitToiO(int dong, int cot) const {
        return (dong * this->soCot) + cot;
    }

    int BitMap::layBitTaiViTri(int viTri) const {
        int chiSoMang = viTri / BYTE_SZ;
        int chiSoBit = (BYTE_SZ - 1) - (viTri % BYTE_SZ);
        return (this->noiDung[chiSoMang] >> chiSoBit) & 1;
    }

    void BitMap::ganBitTaiViTri(int viTri, int val) {
        val &= 1;
        int chiSoMang = viTri / BYTE_SZ;
        int chiSoBit = (BYTE_SZ - 1) - (viTri % BYTE_SZ);
        int bitHienTai = (this->noiDung[chiSoMang] >> chiSoBit) & 1;
        if (bitHienTai == val) {
            // already equal
        }
        else {
            val ^= bitHienTai;
            this->noiDung[chiSoMang] ^= (val << chiSoBit); 
        }
    }



    BitMap::BitMap(int slDong, int slCot) {
        int soBitCuaMang = tinhSoBitCuaMang(slDong, slCot);
        int soBlock = doiSoBitSangSoBlock(soBitCuaMang);
        
        this->noiDung = (tblock*)calloc(soBlock, sizeof(uint*));
        this->soDong = slDong;
        this->soCot = slCot;
    }

    int BitMap::laySoCot() const {
        return this->soCot;
    }
    
    int BitMap::laySoDong() const {
        return this->soDong;
    }

    int BitMap::layNoiDung(int dong, int cot) const {
        int viTriTheoBit = this->tinhSoBitToiO(dong, cot);
        return this->layBitTaiViTri(viTriTheoBit);
    }

    void BitMap::ganNoiDung(int dong, int cot, int val) {
        int viTriTheoBit = this->tinhSoBitToiO(dong, cot);
        this->ganBitTaiViTri(viTriTheoBit, val);
    }


    BitMap::~BitMap() {
        free(this->noiDung);
    }
};
