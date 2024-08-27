#include "bangdiem.h"
BangDiem::BangDiem()
{
}

// getter

HocSinh BangDiem::GetHocSinh()
{
    return this->hs;
}

float BangDiem::GetToan()
{
    return this->Toan;
}
float BangDiem::GetLi()
{
    return this->Li;
}
float BangDiem::GetHoa()
{
    return this->Hoa;
}
float BangDiem::GetDTB()
{
    // float Toan = this->Toan;
    // float Li = this->Li;
    // float Hoa = this->Hoa;
    // this->DTB = (Toan + Li + Hoa) / 3;
    return this->DTB;
}
string BangDiem::GetHocLuc()
{
    // if (this->DTB >= 8)
    //     this->HocLuc = "Gioi";
    // else if (this->DTB >= 6.5 && this->DTB < 8)
    //     this->HocLuc = "Kha";
    // else if (this->DTB >= 5 && this->DTB < 6.5)
    //     this->HocLuc = "Trung Binh";
    // else
    // {
    //     this->HocLuc = "Yeu";
    // }
    return this->HocLuc;
}

// setter
void BangDiem::SetToan(float Toan)
{
    this->Toan = Toan;
}
void BangDiem::SetLi(float Li)
{
    this->Li = Li;
}
void BangDiem::SetHoa(float Hoa)
{
    this->Hoa = Hoa;
}
void BangDiem::SetDTB(float toan, float li, float hoa)
{
    this->DTB = (toan + li + hoa) / 3;
}
void BangDiem::SetHocLuc(float DTB)
{
    if (DTB >= 8)
        this->HocLuc = "Gioi";
    else if (DTB >= 6.5 && DTB < 8)
        this->HocLuc = "Kha";
    else if (DTB >= 5 && DTB < 6.5)
        this->HocLuc = "Trung Binh";
    else
    {
        this->HocLuc = "Yeu";
    }
}
void BangDiem::SetHocSinh(HocSinh hs)
{
    this->hs = hs;
}
void BangDiem ::DauVao()
{
    cout << "nhap thong tin hoc sinh" << endl;
    HocSinh hocsinh;
    hocsinh.DauVao();
    this->hs = hocsinh;
    cout << "nhap diem toan = ";
    cin >> this->Toan;
    cout << "nhap diem li = ";
    cin >> this->Li;
    cout << "nhap diem hoa = ";
    cin >> this->Hoa;
    this->SetDTB(this->Toan, this->Li, this->Hoa);
    this->SetHocLuc(this->DTB);
}
void BangDiem ::DauRa()
{
    cout << "IdHocSinh : " << hs.GetId()
         << " Lop : " << hs.GetMaLop() << " TenHocSinh : " << hs.GetTenHocSinh()
         << " NgaySinh : " << hs.GetNgaySinh() << " DiemToan : " << this->Toan << " DiemLi : " << this->Li
         << " DiemHoa : " << this->Hoa << " DTB : " << this->DTB << " HocLuc : " << this->HocLuc << endl;
}

void BangDiem::GhiVaoFile(ofstream &fileout)
{
    fileout << this->hs.GetId() << ",";
    fileout << this->hs.GetMaLop() << ",";
    fileout << this->hs.GetTenHocSinh() << ",";
    fileout << this->hs.GetNgaySinh() << ",";
    fileout << this->Toan << ",";
    fileout << this->Li << ",";
    fileout << this->Hoa << ",";
    fileout << this->DTB << ",";
    fileout << this->HocLuc;
}

// Hàm hủy
BangDiem::~BangDiem()
{
}