#include "hocsinh.h"
HocSinh::HocSinh() {}

void HocSinh::ThemHocSinh(HocSinh newhs)
{
}
// getter
int HocSinh::GetId()
{
    return this->Id;
}

string HocSinh::GetMaLop()
{
    return this->MaLop;
}

string HocSinh::GetTenHocSinh()
{
    return this->TenHocSinh;
}

string HocSinh::GetNgaySinh()
{
    return this->NgaySinh;
}

// setter

void HocSinh::SetId(int Id)
{
    this->Id = Id;
}

void HocSinh::SetMaLop(string MaLop)
{
    this->MaLop = MaLop;
}

void HocSinh::SetTenHocSinh(string TenHocSinh)
{
    this->TenHocSinh = TenHocSinh;
}

void HocSinh::SetNgaySinh(string NgaySinh)
{
    this->NgaySinh = NgaySinh;
}