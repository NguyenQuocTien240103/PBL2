#include "bangdiem.h"
BangDiem::BangDiem()
{
}

// getter

int BangDiem::GetId()
{
    return this->Id;
}

float BangDiem::GetToan()
{
    return this->Toan;
}

// setter

void BangDiem::SetId(int Id)
{
    this->Id = Id;
}

void BangDiem::SetToan(float Toan)
{
    this->Toan = Toan;
}

void BangDiem ::DauVao()
{
    cout << "nhap Id = ";
    cin >> this->Id;
    cout << "nhap thong tin hoc sinh" << endl;
    HocSinh hocsinh;
    hocsinh.DauVao();
    this->hs = hocsinh;
}