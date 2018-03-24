#include "CSDLNhiPhan.h"
#include <new>
#include <string>
#include <fstream>

namespace NguyenQuocHuy {
	std::vector<std::string> CSDLNhiPhan::tachChuoiDungDelimiter(std::string s, char delim) {
		std::vector<std::string> ketQua;
		std::string token = "";
		
		s += delim;
		
		for (int i = 0, n = s.length(); i < n; ++i) 
			if (s[i] == delim) {
				if (token.length() > 0) 
					ketQua.push_back(token);
				token = "";
			}
			else 
				token += s[i];
		return ketQua;
	}

	CSDLNhiPhan::CSDLNhiPhan(const std::string &fileName) {
		// std::ifstream fi(fileName, std::ifstream::in);
		// std::string buff;
		// std::getline(fi, buff);
		// this->tenThuocTinh = tachChuoiDungDelimiter(buff, ',');
		// fi.close();
	}

	CSDLNhiPhan::~CSDLNhiPhan() {
		
	}
};
