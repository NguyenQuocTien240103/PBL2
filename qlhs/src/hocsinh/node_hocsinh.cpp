#include "node_hocsinh.h"
Node_HocSinh::Node_HocSinh(HocSinh hs)
{
    this->hs = hs;
    this->next = nullptr;
}
void Node_HocSinh::SaveAllHocSinh(Node_HocSinh *&Head, const string &file_name)
{
    ofstream fileOutput(file_name); // Mở file output để ghi dữ liệu

    if (!fileOutput.is_open())
    {
        cerr << "Không thể mở file: " << file_name << endl;
        return;
    }

    Node_HocSinh *temp = Head;
    //    int count = 0; // Đếm số thứ tự

    if (temp == NULL)
    {
    }
    else
    {
        //fileOutput << "\t\t\t\t\t\t*****DANH SACH HOC SINH*****" << endl;
        while (temp != NULL)
        {
            temp->hs.GhiVaoFile(fileOutput);
            temp = temp->next;
            fileOutput << endl;
        }
    }

    fileOutput.close(); // Đóng file sau khi hoàn thành ghi dữ liệu
}
void Node_HocSinh::ThemHocSinh(HocSinh hs, Node_HocSinh *&Head)
{
    // luôn luôn thêm vào cuối
    Node_HocSinh *new_hocsinh = new Node_HocSinh(hs);
    if (Head == NULL)
        Head = new_hocsinh;
    else
    {
        Node_HocSinh *temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_hocsinh;
    }
}

void Node_HocSinh::DocFile(ifstream &filein, Node_HocSinh *&Head)
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
            ThemHocSinh(newHocSinh, Head); // Thêm vào đầu danh sách
        }
    }
}