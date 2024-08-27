#include "quanli_lop.h"
QuanLiLop::QuanLiLop()
{
    this->Head = nullptr;
}
Node_Lop *QuanLiLop::getHead()
{
    return this->Head;
}
void QuanLiLop::SaveAllLop(const string &file_name)
{
    ofstream fileOutput(file_name); // Mở file output để ghi dữ liệu

    if (!fileOutput.is_open())
    {
        cerr << "Không thể mở file: " << file_name << endl;
        return;
    }

    Node_Lop *temp = this->Head;

    if (temp == nullptr)
    {
    }
    else
    {
        while (temp != nullptr)
        {
            temp->lop.GhiVaoFile(fileOutput);
            temp = temp->next;
            fileOutput << endl;
        }
    }

    fileOutput.close(); // Đóng file sau khi hoàn thành ghi dữ liệu
}
void QuanLiLop::ThemLop(Lop lop)
{
    // luôn luôn thêm vào cuối
    Node_Lop *new_lop = new Node_Lop(lop);
    if (this->Head == nullptr)
        this->Head = new_lop;
    else
    {
        Node_Lop *temp = this->Head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new_lop;
    }
}
void QuanLiLop::HienThiDanhSachLop()
{

    Node_Lop *temp = this->Head;
    while (temp != nullptr)
    {
        temp->lop.DauRa();
        temp = temp->next;
    }
}
void QuanLiLop::DocFile(ifstream &filein)
{
    string MaLop, TenLop;
    while (getline(filein, MaLop, ',') && getline(filein, TenLop))
    {
        // Kiểm tra xem tệp có mở thành công không
        if (!filein.is_open())
        {
            cerr << "Không thể mở tệp để đọc" << endl;
            return;
        }
        // Xóa khoảng trắng thừa nếu cần
        MaLop.erase(0, MaLop.find_first_not_of(" \t\n\r\f\v"));
        TenLop.erase(0, TenLop.find_first_not_of(" \t\n\r\f\v"));

        // Nếu dữ liệu không rỗng, thêm vào danh sách liên kết
        if (!MaLop.empty() && !TenLop.empty())
        {
            Lop newLop;
            newLop.SetMaLop(MaLop);
            newLop.SetTenLop(TenLop);
            ThemLop(newLop); // Thêm vào cuối danh sách
        }
    }
}

QuanLiLop::~QuanLiLop()
{
    Node_Lop *temp = this->Head;
    while (temp != nullptr)
    {
        Node_Lop *current = temp->next;
        delete temp;
        temp = current;
    }
    this->Head = nullptr;
}
