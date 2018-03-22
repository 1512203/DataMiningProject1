#include "BangBit.h"
#include <new>
#include <cstring>

namespace NguyenQuocHuy {
	/*	---------- Static members ----------  */

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

	/*	---------- ############## ----------  */



	/*	---------- Non-static members ----------  */

	BangBit::BangBit(int slDong, int slCot) {
		this->soDong = slDong;
		this->soCot = slCot;
		this->soByteMotDong = tinhSoBlockBietSoBit(slCot);
		this->soByteChoBang = tinhSoByteChoBang(this->soByteMotDong, slDong);
		this->duLieu = new tblock[ soByteChoBang ];
		memset(this->duLieu, 0, sizeof(this->soByteChoBang));
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

	BangBit::~BangBit() {
		delete[] this->duLieu;
	}

	/*	---------- ################## ----------  */
}