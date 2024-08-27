#include "quanli_hocsinh.h"
QuanLiHocSinh::QuanLiHocSinh()
{
    this->Head = nullptr;
}
Node_HocSinh *QuanLiHocSinh::getHead()
{
    return this->Head;
}
void QuanLiHocSinh::SaveAllHocSinh(const string &file_name)
{
    ofstream fileOutput(file_name); // Mở file output để ghi dữ liệu

    if (!fileOutput.is_open())
    {
        cerr << "Không thể mở file: " << file_name << endl;
        return;
    }

    Node_HocSinh *temp = this->Head;

    while (temp != nullptr)
    {
        temp->hs.GhiVaoFile(fileOutput);
        temp = temp->next;
        fileOutput << endl;
    }

    fileOutput.close(); // Đóng file sau khi hoàn thành ghi dữ liệu
}
void QuanLiHocSinh::ThemHocSinh(HocSinh hs)
{
    // luôn luôn thêm vào cuối
    Node_HocSinh *new_hocsinh = new Node_HocSinh(hs);
    if (this->Head == nullptr)
        this->Head = new_hocsinh;
    else
    {
        Node_HocSinh *temp = this->Head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new_hocsinh;
    }
}
void QuanLiHocSinh::XoaVaoViTriBatKi(int pos)
{
    if (this->Head == nullptr)
        return;

    Node_HocSinh *temp = this->Head;

    if (pos == 0)
    {
        this->Head = temp->next;
        delete temp;
        return;
    }

    for (int i = 0; temp != nullptr && i < pos - 1; i++)
        temp = temp->next;

    if (temp == nullptr || temp->next == nullptr)
        return;

    Node_HocSinh *next = temp->next->next;
    delete temp->next;
    temp->next = next;
}
void QuanLiHocSinh::HienThiDanhSachHocSinh()
{

    Node_HocSinh *temp = this->Head;
    while (temp != nullptr)
    {
        temp->hs.DauRa();
        temp = temp->next;
    }
}
void QuanLiHocSinh::DocFile(ifstream &filein)
{
    string IdStr, MaLop, TenHocSinh, NgaySinh;
    while (getline(filein, IdStr, ',') && getline(filein, MaLop, ',') &&
           getline(filein, TenHocSinh, ',') && getline(filein, NgaySinh))
    {
        // Kiểm tra xem tệp có mở thành công không
        if (!filein.is_open())
        {
            cerr << "Không thể mở tệp để đọc" << endl;
            return;
        }
        // Xóa khoảng trắng thừa nếu cần
        IdStr.erase(0, IdStr.find_first_not_of(" \t\n\r\f\v"));
        MaLop.erase(0, MaLop.find_first_not_of(" \t\n\r\f\v"));
        TenHocSinh.erase(0, TenHocSinh.find_first_not_of(" \t\n\r\f\v"));
        NgaySinh.erase(0, NgaySinh.find_first_not_of(" \t\n\r\f\v"));
        // Nếu dữ liệu không rỗng, thêm vào danh sách liên kết
        if (!IdStr.empty() && !MaLop.empty() && !TenHocSinh.empty() && !NgaySinh.empty())
        {
            int Id = stoi(IdStr);
            HocSinh newHocSinh;
            newHocSinh.SetId(Id);
            newHocSinh.SetMaLop(MaLop);
            newHocSinh.SetTenHocSinh(TenHocSinh);
            newHocSinh.SetNgaySinh(NgaySinh);
            ThemHocSinh(newHocSinh); // Thêm vào đầu danh sách
        }
    }
}
QuanLiHocSinh::~QuanLiHocSinh()
{
    Node_HocSinh *temp = this->Head;
    while (temp != nullptr)
    {
        Node_HocSinh *current = temp->next;
        delete temp;
        temp = current;
    }
    this->Head = nullptr;
}