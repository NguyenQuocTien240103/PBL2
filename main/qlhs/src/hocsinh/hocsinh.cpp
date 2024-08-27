#include "hocsinh.h"
HocSinh::HocSinh() {}
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

void HocSinh::DauVao()
{
    cout << "nhap Id = ";
    cin >> this->Id;
    cout << "nhap MaLop = ";
    cin >> this->MaLop;
    cout << "nhap TenHocSinh = ";
    cin >> this->TenHocSinh;
    cout << "nhap NgaySinh = ";
    cin >> this->NgaySinh;
}
void HocSinh::DauRa()
{
    cout << "Id:" << this->Id << " Lop:" << this->MaLop << " Ten:" << this->TenHocSinh << " NgaySinh:" << this->NgaySinh << endl;
}
void HocSinh::GhiVaoFile(ofstream &fileout)
{
    fileout << this->Id << ",";
    fileout << this->MaLop << ",";
    fileout << this->TenHocSinh << ",";
    fileout << this->NgaySinh;
}
// Hàm hủy
HocSinh::~HocSinh()
{
    // Định nghĩa hàm hủy, nếu không có gì đặc biệt cần giải phóng, bạn có thể để trống
}