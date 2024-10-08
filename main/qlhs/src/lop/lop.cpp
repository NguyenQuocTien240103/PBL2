#include <iostream>
#include "lop.h"
Lop::Lop() {}

// Getter
string Lop::GetMaLop()
{
    return this->MaLop;
}

string Lop::GetTenLop()
{
    return this->TenLop;
}

// Setter
void Lop::SetMaLop(string MaLop)
{
    this->MaLop = MaLop;
}

void Lop::SetTenLop(string TenLop)
{
    this->TenLop = TenLop;
}

// Nhập thông tin lớp
void Lop::DauVao()
{
    cout << "MaLop: ";
    cin >> this->MaLop;
    cout << "TenLop: ";
    cin >> this->TenLop;
}

void Lop::DauRa()
{
    cout << "MaLop:" << this->MaLop << ",TenLop:" << this->TenLop << endl;
}

// Xuất thông tin lớp ra file
void Lop::GhiVaoFile(ofstream &fileout)
{
    fileout << this->MaLop << ",";
    fileout << this->TenLop;
}

// Hàm hủy
Lop::~Lop()
{
    // Định nghĩa hàm hủy, nếu không có gì đặc biệt cần giải phóng, bạn có thể để trống
}