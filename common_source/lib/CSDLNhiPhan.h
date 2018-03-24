#ifndef CSDLNHIPHAN_INCLUDED
#define CSDLNHIPHAN_INCLUDED
#include "../lib/BangBit.h"
#include <string>
#include <vector>

namespace NguyenQuocHuy {
    class CSDLNhiPhan {
    private:
    	static std::vector<std::string> tachChuoiDungDelimiter(std::string s, char delim);
    protected:
    	BangBit* csdl;
    	std::vector<std::string> tenThuocTinh;
    public:
    	CSDLNhiPhan(const std::string &fileName);
    	CSDLNhiPhan(const CSDLNhiPhan &other);
    	~CSDLNhiPhan();
    };
};

#endif
